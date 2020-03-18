/*一百元买一百只鸡，公鸡五元一只，母鸡三元一只，小鸡一元三只，怎样买？*/ 

#include <stdio.h>
int main()
{
	int x, y, z;
	printf("公鸡 母鸡 小鸡\n");
	for (x = 0; x <= 100; ++x)
        for(y = 0; y <= 100; ++y)
 		{
			z = 100 - x -y;
			if (15*x + 9*y + z == 300 && x + y + z == 100)
	            printf("%4d%4d%4d\n", x, y, z);
 		}
	return 0;
}
