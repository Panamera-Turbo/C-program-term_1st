#include "library.h"
/******************************************************************
 * 登录。根据输入不同的数字对应不同的登陆身份并执行相对应的操作
 * ****************************************************************/

char land(){
    char c, flag;
    int i;
    while(1){
        for(i = 0; (c = getchar()) != '\n'; flag = c, ++i)
            ;
        if(i == 1){
            if(flag == '1' || flag == '2' || flag == '0'){
                return flag;
            }
        }else if(i == 0){
            continue;
        }
        error("[请输入命令： 1 / 2 / 0 选择项目]");
    }
    return '\0';
}