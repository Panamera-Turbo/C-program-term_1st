#include <stdio.h>
// ---------------------------------------------
// 找出数组里最大和第二大的数字
// ---------------------------------------------
int main ()
{
    int score[] = {3, 1, 0, 4, 2};
    int i, j, max, second_max;

    printf ("Enter five numbers:");
    for (i = 0; i < 5; ++i)
        scanf ("%d", &score[i]);
    
    j = 0;
    max = score[j];
    for (i = 0; i < 5; ++i)
        if (max < score[i])
            max = score[j = i];
    
    second_max = score[0];
    for (i = 0; i < 5; ++i)
        if (second_max < score[i] && i != j)
            second_max = score[i];

    printf ("The biggest one is %d\n", max);
    printf ("The second biggest one is %d\n", second_max);
    
    return 0;
}

