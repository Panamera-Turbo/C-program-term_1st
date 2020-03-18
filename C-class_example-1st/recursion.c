#include<stdio.h>
//-------------------------------------------
//计算n的阶乘
// ------------------------------------------
unsigned long fact(unsigned long n)
{
    return n<=1? 1 :fact(n-1)*n;
}
//过程为递推，层层迭代
//fact(n)=> return fact(n-1)*n
//fact(n-1)=> return fact(n-2)*(n-1), the answer will return to last line(line 12 in this example),till we get to "fact (1)=> return 1"
int main ()
{
    unsigned long a;
    printf("输入数字：");
    scanf("%ld",&a);
    printf("%1ld\n",fact(a));
    return 0;
}