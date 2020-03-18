#include <stdio.h>
//求平均值
int main()
{
    int score[5];
    int i;
    double avg;

    for (i = 0; i < 5; ++i)
        scanf("%d", &score[i]);

    avg = 0;
    for (i = 0; i < 5; ++i)
        avg += score[i];
    avg /= 5;
    
    printf ("%lf\n", avg);

    return 0;
}
