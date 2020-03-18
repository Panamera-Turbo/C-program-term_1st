/*寻找水仙花数（三位数各位数字立方和等于该数）*/ 

#include <stdio.h>
int main(int argc, char *argv[])
{
	int a, b, c;
	
	for (a = 1; a <= 9; ++a)
		for (b = 0 ; b<= 9; ++b)
			for (c = 0; c <= 9; ++c)
			if(100 * a + 10 * b + c == a*a*a +b*b*b + c*c*c)
			printf("%d\n", 100 * a + 10 * b + c);
			
	return 0;
}
