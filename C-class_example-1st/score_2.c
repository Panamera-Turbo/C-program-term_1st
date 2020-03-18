#include <stdio.h>
//--------------------------------------
//分数对应等级
//else if的简单应用
//--------------------------------------
int main(int argc, char *argv[])
{
	int a;
	scanf("%d",&a);
	if (a >=90)
		printf("outstanding\n");
	else if(a >= 80)
		printf("excellent\n");
	else if(a >= 70)
		printf("acceptable\n");
	else if(a >= 60)
		printf("poor\n");
	else 
		printf("dreadful\n");
	
	return 0;
}
