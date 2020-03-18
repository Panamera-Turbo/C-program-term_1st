#include"library.h"
/***************************************************************************
 * 伤处书籍信息。根据输入的图书编号彻底删除某一图书的库存信息
 * *************************************************************************/

int delbook(){
     ;      ///////////////////////////////////////////
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
                free(bp->name);                                         //2018-05-26修改：添加释放name这块内存//bp内存的只是指向name的指针
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