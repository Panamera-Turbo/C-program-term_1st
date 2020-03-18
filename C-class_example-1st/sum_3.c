// 求1~1000所有奇数的和

#include <stdio.h>
int main(int argc, char *argv[])
{
	int sum, i;
	sum = 0;
	i = 1;
	while (i<=1000)
	{
		sum += i;
		i += 2;
	}
	printf("%d\n",sum);
	return 0;
}

