//---------------------------------------------------------
//斐波那契数列的第n项
//方法：递归
//---------------------------------------------------------
#include <stdio.h>

long fibo(long n)
{//求第n项
    return n <= 2 ? 1 : fibo(n-1) + fibo(n-2);
}

long fibo2(long n, long a, long b)//a，b是首项和第二项
{//另一种求第n项的办法
    return n == 1 ? a : fibo2(n-1, b, a + b);
}

int main()
{
    unsigned long n;

    scanf("%ld", &n);
    printf("%ld, %ld\n", fibo(n), fibo2(n, 1, 1));

    return 0;
}