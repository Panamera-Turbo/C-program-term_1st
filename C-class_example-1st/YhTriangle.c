#include <stdio.h>
#define N 11

int main ()
{
    int yh[N][N] = {0};
    int i, j;

    for (i = 0; i <N; ++i)
    {    
        yh[i][0] = 1;
        for (j = 1; j <= i; ++j)
            yh[i][j] = yh[i - 1][j - 1] + yh[i - 1][j];
    }

    for (i = 0; i < N; ++i)
    {
        int k;
        printf ("#%2d#", i);
        for (k = 1; k <= N - i; ++k)
            printf ("   ");        
        for (j = 0; j <= i; ++j)
            printf ("%6d", yh[i][j]);
        putchar ('\n'); 
    }

    return 0;
}
