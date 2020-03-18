#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//---------------------------------------------
//判断输入数据是否为素数
//---------------------------------------------

int main(int argc, char *argv[])
{
	int n, i, r;
	bool isPrime = true;
	
	printf("input a number:");
	scanf("%d",&n);
	for (i = 2; i <= sqrt(n); ++i)
	{
		r = n % i;
		if (r == 0)
		{
			isPrime = false;
			break;
		}
	}
	printf(isPrime ? "It is prime\n" : "It is not prime\n");
	return 0;
}
