//用函数求两个数的平均值

#include <stdio.h>

double average(double x, double y)
{
    double t = (x + y) / 2.0;//
    return t;                // = return (x + y) / 2.0;
}

int main ()
{
    double a, b, c, d;

    a = 2.3; b = 4.6;
    c = average(a, b);
    d = average(12.34, 56.78);
    printf ("%lf,%lf\n", c, d);

    return 0;
}
