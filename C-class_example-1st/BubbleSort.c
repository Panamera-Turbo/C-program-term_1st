#include <stdio.h>
//输入十个数，冒泡排序

#define N 10
int main ()
{
    int a[N];
    int i, j;

    printf ("Enter ten out-of-order numbers:");
    for (i = 0; i < 10; ++i)
        scanf ("%d", &a[i]);

    for (i = 0; i < N - 1; ++i)
        for (j = 0; j < N - i - 1; ++j)
            if (a[j] >= a[j + 1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
    printf("Small -> large:\t");
    for (i = 0; i < N; ++i)
        printf ("%4d", a[i]);
    putchar ('\n');

    return 0;
}
