#include<stdio.h>

int main()
{
    char a[] = {'a', 'b', 'c', '\0'};//注意'0'， 用来终止数组

    char b[] = "abc";//这里是把值复制到b[]里，可以修改，但是只改了b[]

    char *p = "abc";//这里标记为常量，不能修改
     //指针指向字符串， 数组复制字符串

    b[0] = 'A';
    // *p = 'M';
    /**********************************************************
    这条是错误的. 为了让其能被修改，必须改成变量，即指向一个数组，
    如上面char *p="abc" 改成 char *p=b  
    ***********************************************************/
    
    printf("%s\n", a);
    printf("%s\n", b);
    printf("%s\n", p);



    return 0;
}