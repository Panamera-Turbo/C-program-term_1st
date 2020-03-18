#include <stdio.h>
//将一个属拆分成小数和整数部分
void  decomp( double d, int *i, double *f)
 {
     *i = (int)d;

     *f = d- *i;//注意！！！！看*,可以试着删了所有指针看看后果 => 输出全为0
 }
 int main()
 {
    double x;
    int a = 0;
    double b = 0.0;
    printf("输入一个小数点后不超过6位的小数：");
    scanf("%le",&x);
    decomp (x,&a,&b);
    printf("整数：%d\n小数：%1f\n", a, b);
            return 0;
 }
 