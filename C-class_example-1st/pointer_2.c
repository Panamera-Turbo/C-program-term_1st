#include<stdio.h>

int main()
{
    char i = 1 , j;
    char *p = &i ,*q = &j;

    p + (p-q)/2;//指针可以加上或者减去整数，代表其前/后n个单元的地址
                //指针可以相减，代表中间差的单元数
                //指针不能相加
                // 指针可以比较，代表地址是否相同
    printf("%p,%p\n",p,p-3);
    return 0;
}