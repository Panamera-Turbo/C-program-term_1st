#include "library.h"

//执行对应输入管理员登陆时的操作


char domanager(){

    char c, flag;
    int i;
    
    while(1){
        for(i = 0; (c = getchar()) != '\n'; flag = c, ++i)
            ;
        if(i == 1){
            if(flag == '1' || flag == '2' || flag == '3' || flag == '4' || flag == '0'){
                return flag;
            }
        }else if(i == 0){
            continue;
        }
        error("[请输入命令： 1 / 2 / 3/ 4 / 0 选择项目]");
            
    }
    
    // return '\0';
}
int usrmanager(){
    printf("-------------------------------------\n");
    printf("请输入项目前编号执行相关操作：\n\n");
    printf("[1] 查看已存图书\n[2] 注册新图书\n[3] 修改已有图书信息\n[4] 注销现存图书\n");
    printf("[0] 返回主页\n");
    switch(domanager()){
        case '1':
            viewbook();
            break;
        case '2':
            addbook();
            break;
        case '3':
            modbook();
            break;
        case '4':
            delbook();
            break;
        case '0':
            return 0;
        default:
            error("采集项目参数失败");
            break;
    }
    return 1;

}