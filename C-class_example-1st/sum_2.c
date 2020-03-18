//求  1 + 1/11 + 1/111 + 1/1111 ……的和
#include <stdio.h>
int main(int argc, char *argv[])
{
	float t,i,sum;
	sum = 0;
	t = 1;
	i = 10;
	while(i <= 111111111)
	{
		sum += t/i;
		i= 10 * i + 1;
		t= 10 * t + 1;
	}
	printf("%f\n",sum);
	return 0;
}
