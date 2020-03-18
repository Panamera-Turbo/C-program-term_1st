#include <stdio.h>
//--------------------------------------
//分数对应等级
//switch的简单应用
//--------------------------------------
int main(int argc, char *argv[])
{	
	int a;
	scanf("%d",&a);
		switch(a/10)
		{
		case 10:printf("outstading\n");
				break;
		case 9:printf("outstading\n");
				break;
		case 8:printf("excellent\n");
				break;
		case 7:printf("acceptable\n");
				break;
		case 6:printf("poor\n");
				break;
		default:printf("dreadful\n");
	
		}
		
	return 0;
}
