#include<stdio.h>
//---------------------------------------------------------------
//汉诺塔问题，计算移动方案
//思路：递归
//---------------------------------------------------------------
void hanoi(int n, char src, char dest, char aux)
{/******src =>起始柱 ||  deat =>目标柱 || aux =>中转柱********/
    if (n==1)
    {
        printf("%c-->%c\n",src, dest);
        return;      
    }

    hanoi (n - 1, src, aux, dest );
    printf("%c-->%c\n",src, dest);
    hanoi(n-1, aux, dest , src);
}

int main()
{
    int n;
    printf("输入汉诺塔层数n");
    scanf("%d",&n);

    hanoi(n, 'a','b' ,'c');
    return 0;
}