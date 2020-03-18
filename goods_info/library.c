#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

bookptr head = NULL;
int nbook = 0;
Book *L ;

int main(){
    Book *L;
    init(&L);
    welcome();
    return 0;
}

void error(char *s){
    fprintf(stderr, "%s\n", s);
}

int viewbook(){//查看已经注册的所有图书
    Book *bp;
	bp = L->next;
    for(; bp != NULL; bp = bp->next){
        printbook(bp);
    }
    if(nbook){
        return nbook;
    }else{
        return 0;
    }
    return -1;
}
void printbook(Book *bp){//打印已经注册/储存的所有图书
    
    printf("\n图书名\t图书编号\t图书存数\t图书状态\n\n");
    printf("%s\t%d\t\t%d\t\t %s\n", bp->name, bp->id, bp->count, bp->status? "不可借" : "可借");
   
}
int addbook(){    
    char sname[MAXNAME];
    int id, count;
    char *namep;

    while(1){
        id = 0;
        count = 0;
        namep = NULL;
        printf("请输入图书名：\n");
        scanf("%s", sname);
        getchar();
        printf("请输入小于1000的图书编号：\n");
        scanf("%d", &id);
        getchar();
        if(!(id > 0 && id < 1000)){
            error("输入编号不符合要求");
            fflush(stdin);
            continue;
        }
        printf("请输入小于50的图书数量：\n");
        scanf("%d", &count);
        getchar();
        if(!(count > 0 && count < 50)){
            error("输入数目不符合要求");
            fflush(stdin);
            continue;
        }
        Book *bp;        
        if((bp = lookup(namep = strdup(sname), id)) == NULL){
            bp = (Book *)malloc(sizeof (Book));
            if(bp == NULL || strcpy(bp->name,namep) == NULL){
                error("注册图书失败");
                fflush(stdin);
                continue;
            }
            bp->id = id;
            bp->count = count;
            bp->status = AVAILABLE;
            ++nbook;
            
            bp->next = head;
            head = bp;
            printf("图书 %s 注册成功\n", sname);
            return id;
        }else{
            fflush(stdin);
            error("图书名或编号已经被占用");
        }
    }

    return -1;
}
Book *lookup(char *s, int id){
    Book *bp;
    for(bp = head; bp != NULL; bp = bp->next){
        if(id == bp->id || strcmp(s, bp->name) == 0){
            return bp;
        }
    }
    return NULL;
}

int modbook(){  // 修改除id之外的信息  因为要修改id 直接删掉后重新添加会更好
     ;      
    Book *bp = NULL;
    while(1){
        int id = 0;
        printf("请输入要修改信息的图书编号：\n");
        scanf("%d", &id);
        getchar();
        if(!(id > 0 && id < 1000)){
            fflush(stdin);
            error("图书编号不符合要求");
            continue;
        }
        if((bp = lookup("", id)) != NULL){
            printf("以下为要修改的图书的现有信息：\n");
            printbook(bp);
            printf("[1] 修改图书名\n[2] 修改图书数量\n[3] 修改图书状态\n[0] 放弃修改\n");
            while(1){
                int i;
                scanf("%d", &i);
                getchar();
                if(!(i == 1 || i == 2 || i == 3 || i == 0)){
                    fflush(stdin);
                    error("输入项目前编号选择相关项目");
                    continue;
                }
                switch(i){
                    case 1:
                        while(1){
                            char newname[MAXNAME], *namep;
                            printf("图书名：\n");
                            scanf("%s", newname);
                            getchar();
                            if((lookup(namep = strdup(newname), 0)) != NULL){
                                fflush(stdin);
                                error("图书名已存在");
                                continue;
                            }
                            if(strcpy(bp->name, namep) != NULL){
                                printf("修改成功\n");
                                return id;
                            }
                        }
                        break;
                    case 2:
                        while(1){
                            int bnum;
                            printf("输入图书数量：\n");
                            scanf("%d", &bnum);
                            getchar();
                            if(!(bnum > 0 || bnum < 1000)){
                                fflush(stdin);
                                error("数目不符合要求");
                                continue;
                            }
                            bp->count = bnum;
                            printf("修改成功\n");
                            return id;
                        }
                        break;
                    case 3:
                        while(1){
                            char c;
                            int status;
                            status = bp->status;
                            status == AVAILABLE ? printf("修改状态为[不可借]： Y N\n") : printf("修改状态为[可借]： Y N\n");
                            scanf("%c", &c);
                            getchar();
                            if(!( c == 'Y' || c == 'y' || c == 'N' || c == 'n')){
                                fflush(stdin);
                                error("指令无效");
                                continue;
                            }
                            if(c == 'Y' || c == 'y'){
                                 status == AVAILABLE ? bp->status = UNAVAILABLE : (bp->status = AVAILABLE);
                                 printf("修改成功\n");
                                 return id;
                            }else{
                                printf("放弃修改\n");
                                return 0;
                            }
                        }
                        break;
                    case 0:
                        return 0;
                    default:
                        error("获取参数失败");
                        break;   
                }
            }
        }else{
            printf("没有此图书\n");
            return 0;
        }
    }
    return -1;
}
int delbook(){//删除图书库存信息
     ;      
    Book *bp, *fbp;
    
    int id = 0;
    printf("请输入要注销的图书编号：\n");
    scanf("%d", &id);
    getchar();
    if(!(id > 0 && id < 1000)){
        fflush(stdin);
        error("图书编号不符合要求");
        return -1;
    }
    for(fbp = bp = head; bp != NULL; fbp = bp, bp = bp->next){
        if(bp->id == id){
            printbook(bp);
            break;
        }
    }
    if(bp != NULL){
        while(1){
            printf("确定要注销此图书：Y  N\n");
            char YN;
            scanf("%c", &YN);
            getchar();
            if(!((YN == 'Y' || YN == 'y') || (YN == 'N' || YN == 'n'))){
                fflush(stdin);
                error("指令无效\n");
                continue;
            }
            if(YN == 'Y' || YN == 'y'){
                bp == head ? head = bp->next : (fbp->next = bp->next);
                free(bp->name);                                         //添加释放name这块内存
                                                                        //bp内存的只是指向name的指针
                free(bp);
                bp = NULL;
                printf("图书注销成功\n");
                break;
            }else{
                printf("放弃注销\n");
                return 0;
            }
        }  
        return id;
    }else{
        printf("要注销的图书编号不存在\n");
        return -1;
    }
    return -1;
}
