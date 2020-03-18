#include<stdio.h>
#include<string.h>
//拷贝字符串
char * strcpy(char *dest, const char *src)
//拷贝数组
//const约束了char是常量，即指针本身是常量，但是指向可以是变量数组
{
    char *t = dest;
    while ((*dest++ = *src++));
    /*************************************************************
    *        等价于
    *       while (*src++) *dest++ = *src++;
    *       *dest = '\0';//!!!!!千万记得封尾
    *************************************************************/
   return dest;
}

int * foo()
{
    static int i = 1;
    return &i;
}

int main()
{
    char *p = "1234567890";
    char *q, *t, *j;//讨论字符串复制
    char buf[1024];//增加缓冲区

    q = buf;

    printf("%ld\n", strlen(p));
    t = strcpy(q,p);
    *t = 'X';
    printf("%s\n", t);

    // j = foo();
    // *foo() = 0;
    printf("%d\n", *foo());

    strcmp(p, q);//比较字符串字典序（相等时返回0）



    return 0;
}

