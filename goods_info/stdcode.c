/*******************************************************************************
验证登录：
    输入一个用户名和八位纯数字密码，用户名和stdaccount.txt中的第一个数据进行比对，密码第二个数据进行异或运算，并与第三个数据相比较，相同则返回0，进入图书馆系
统；错误三次则返回-1，退出程序。
    使用方法：管理员登陆代码中加：std_login();

更改密码：
    输入一个八位纯数字密码，和一个随机数进行异或运算，将原用户名和这个随机数和计算结果一起存储。
    使用方法：代码中添加 change_std_code();
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    long id;
    long check;
    long value;
} stdcode;

stdcode std_read_file(void)
{
    FILE *fp;

    fp = fopen("stdaccount.txt", "rt");

    if (fp == NULL)
    {
        printf ("File Broken");
        exit(-1);
    }

    stdcode v;
    
    fscanf (fp, "%ld,%ld,%ld", &v.id, &v.check, &v.value);

    fclose(fp);

    return v;
}

int std_confirm(void)
{    
    int n = 3;    
    stdcode v = std_read_file();  
    long input, ipt;
    int ck1, ck2;

    for (;;)  
    {
        printf("\n请输入你的用户名：");
        scanf ("%ld", &ipt);
        if (ipt == v.id)
            ck1 = 0;
        else
            ck1 = 1;

        printf("\n请输入你的登录密码:");        
        scanf("%ld", &input); 

        if ((v.check ^ input) == v.value)        
            ck2 = 0;        
        else    
            ck2 = 1;

        if (ck1 == 0 && ck2 == 0)
            return 0;
        else    
        {            
            n--;   

            if (n == 0)    
                return(-1);      

            printf("用户名或密码输入有误，剩余输入次数为%d\n", n);         
        }    
    }
}

void std_login(void)
{
    int a = std_confirm();

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

void change_std_code(void)
{
    long v, w;
    stdcode s;
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

    s = std_read_file();

    fp = fopen("stdaccount.txt", "wt");
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

    fprintf (fp, "%ld,%ld,%ld", s.id, v, v ^ w);

    fclose(fp);

    printf ("密码更改成功!\n");
}