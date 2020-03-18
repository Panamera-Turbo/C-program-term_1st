#include <stdio.h>
//---------------------------------
//理解静态变量
//---------------------------------

int f()
{
	static int i=0;
	++i;
	return i;
}

int g()
{
	int i=0;
	++i;
	return i;
}

int main(int argc, char *argv[])
{
	printf("%d,%d\n",f(),g());
	f();
	g();
	printf("%d,%d\n",f(),g());
	return 0;
}
