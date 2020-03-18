/*******************************************************************************
验证登录：
    输入一个八位纯数字密码，和account.txt中的第一个数据进行异或运算，并与第二个数据相比较，相同则返回0，进入图书馆系
统；错误三次则返回-1，退出程序。
    使用方法：管理员登陆代码中加：mng_login();

更改密码：
    输入一个八位纯数字密码，和一个随机数进行异或运算，将这个随机数和计算结果一起存储。
    使用方法：代码中添加 change_mng_code();
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    long check;
    long value;
} code;

code read_file(void)
{
    FILE *fp;

    fp = fopen("account.txt", "rt");

    if (fp == NULL)
    {
        printf ("File Broken");
        exit(-1);
    }

    code v;
    
    fscanf (fp, "%ld,%ld", &v.check, &v.value);

    fclose(fp);

    return v;
}

int confirm(void)
{    
    int n = 3;    
    code v = read_file();  
    long input;

    for (;;)  
    {
        printf("\n请输入你的登录密码:");        
        scanf("%ld", &input); 

        if ((v.check ^ input) == v.value)        
            return 0;        
        else        
        {            
            n--;   

            if (n == 0)    
                return(-1);      

            printf("输入有误，剩余输入次数为%d\n", n);         
        }    
    }
}

void mng_login(void)
{
    int a = confirm();

    if (a == 0)
    {
        printf("登录成功!\n");
    }    
    else if (a == -1)    
    {        
        printf("输入次数已经用尽，系统将自动退出！\n");   
        exit(-1);
    }    
}   

void change_mng_code(void)
{
    long v, w;
    FILE *fp;

    srand ((unsigned) time(NULL));

    for (;;)
    {
        printf ("\n请输入你的新密码（密码必须由八位纯数字组成）：");
        scanf ("%ld", &w);

        if (w >= 10000000 && w < 100000000)
        {
            break;
        }
        else
        {
            printf ("您的密码必须由八位纯数字组成！\n");
        }
    }

    fp = fopen("account.txt", "wt");
    if (fp == NULL)
    {
        printf ("File Broken" );
        exit(1);
    }

    v = rand() % 100000000;
    if (v < 10000000)
    {
        v += 10000000;
    }

    fprintf (fp, "%ld,%ld", v, v ^ w);

    fclose(fp);

    printf ("密码更改成功!\n");
}
