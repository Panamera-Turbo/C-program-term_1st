#include "library.h"

int returnbook(){//归还图书
     ;
    char sname[MAXNAME];
    printf("归还图书：\n");
    scanf("%s", sname);
    getchar();
    Book *bp;
    char *namep;
    if((bp = lookup(namep = strdup(sname), 0)) == NULL){
        fflush(stdin);
        printf("此图书并不是馆内图书\n");
        return -1;
    }else{
        printbook(bp);
        printf("归还图书： Y N\n");
        while(1){
            char c = '\0';
            scanf("%c", &c);
            getchar();
            if(!(c == 'Y' || c == 'y' || c == 'N' || c == 'n')){
                fflush(stdin);
                error("指令无效");
            }else if(c == 'Y' || c == 'y'){
                bp->count++ ? : (bp->status = AVAILABLE);
                printf("成功\n");
                return bp->id;
            }else{
                return 0;
            }
        }
    }

    return -1;
}