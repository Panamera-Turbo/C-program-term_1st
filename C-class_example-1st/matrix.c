#include <stdio.h>
//-----------------------
//二维数组
//计算矩阵乘法 a*b
//-----------------------
#define M 3
#define N 5
#define K 3

int main ()
{
    int a[][N] = {
        1, 2, 3, 4, 5,
        2, 3, 4, 5, 6,
        3, 4, 5, 6, 7
    }, 
    b[N][K] = {
        3, 4, 5,
        4, 5, 6,
        5, 6, 7,
        6, 7, 8,
        8, 9, 0
    }, 
    c[M][K] = {0};
    int i, j, k;

    for (i = 0; i < M ; ++i)
        for (j = 0; j < K; ++j)
        {
            for (k = 0; k < N; ++k)
                c[i][j] += a[i][k] * b[k][j];
        }

    for (i = 0; i < M; ++i)
    {
        for (j = 0; j < K; ++j)
            printf ("%6d", c[i][j]);
        putchar ('\n');
    }

    return 0;
}
