#include "library.h"

char dostudent(){//执行输入学生选项后的工作内容
    char c, flag;
    int i;
    while(1){
        for(i = 0; (c = getchar()) != '\n'; flag = c, ++i )
            ;
        if(i == 1){
            if(flag == '1' || flag == '2' || flag == '3' || flag == '0'){
                return flag;
            }
        }else if(i == 0){
            continue;
        }
        error("[请输入命令： 1 / 2 / 3/ 0 选择项目]");
    }
}


int usrstudent(){
    printf("-------------------------------------\n");
    printf("请输入项目前编号执行相关操作：\n\n");
    printf("[1] 借阅图书\n[2] 归还图书\n[3] 查看馆存图书\n");
    printf("[0] 返回主页\n");
    switch(dostudent()){
        case '1':
            borrowbook();
            break;
        case '2':
            returnbook();
            break;
        case '3':
            viewbook();
            break;
        case '0':
            return 0;
        default:
            error("没有对应可执行任务。请按照上述要求操作！");
            break;
    }
    return 1;
}