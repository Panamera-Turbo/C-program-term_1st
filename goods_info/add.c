#include "library.h"
/*********************************************************************************************************
 * 注册新的书籍信息，包括书名，图书编号，数量。如果出错，会返回相应的错误提示
 * *******************************************************************************************************/


int addbook(){
     ;      ///////////////////////////////////////////
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
            if(bp == NULL || (strcpy(bp->name , namep)) == NULL){
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