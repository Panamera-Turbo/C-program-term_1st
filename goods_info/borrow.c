#include "library.h"
/*****************************************************************************
 * 借阅。根据输入的图书名，查询相应的馆存图书及其数量。完成借阅后库存相应减少
 * ***************************************************************************/

int borrowbook(){
     ;
    char sname[MAXNAME];
    printf("搜索图书:\n");
        scanf("%s", sname);
        getchar();
        Book *bp;
        char *namep = NULL;
        if((bp = lookup(namep = strdup(sname), 0)) == NULL){
            printf("图书 %s 不存在\n", namep);
            fflush(stdin);
            return -1;
        }else{
            printbook(bp);
            if(! bp->status){
                printf("借阅图书： Y N\n");
            }else{
                printf("图书外借中\n");
                return 0;
            }
            while(1){
                char c = '\0';
                scanf("%c", &c);
                getchar();
                if(!(c == 'Y' || c == 'y' || c == 'N' || c == 'n')){
                    fflush(stdin);
                    error("指令无效");
                    continue;
                }
                if(c == 'Y' || c == 'y'){
                    --bp->count > -1 ? printf("成功\n") : printf("失败\n");
                    if(! bp->count){
                        bp->status = UNAVAILABLE;
                    }
                    return bp->id;
                }else{
                    return 0;
                }
            }
        }  
    return -1;
}