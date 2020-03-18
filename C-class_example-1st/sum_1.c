//求自然对数的底e 的近似值。 其中 e = 1 +1 + 1/10 +1/100 +1/1000 ……

#include <stdio.h>
int main(int argc, char *argv[])
{
	float sum,i,a;
	sum = 0;
	i = 1;
	a = 1;
		while(a <= 10)
	{
		sum += 1/i;
		i = i * a;
		++a;
	}
	printf("e=%f\n",sum);
	return 0;
}
