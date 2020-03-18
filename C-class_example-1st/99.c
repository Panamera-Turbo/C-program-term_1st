/*输出九九乘法表*/
#include <stdio.h>
#define N 9
int main()
{
    int a[N][N];
    int i, j;

    for (i = 1; i <= N; ++i)
        for (j = 1; j <= N; ++j)
            a[i - 1][j - 1] = i * j;

    for (i = 0; i < N; ++i)
    {
        for (j = 0; j < N; ++j)
            printf("%d*%d=%-3d",i+1,j+1, a[i][j]);
        putchar('\n');
    }

    return 0;
}
