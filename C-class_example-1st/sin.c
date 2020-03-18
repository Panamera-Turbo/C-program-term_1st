//---------------------------------
// 计算角度的正弦值
//方法：泰勒展开式
//----------------------------------
#include <stdio.h>
#include <math.h>
#define true 1
int main(int argc, char *argv[])
{
	double x, y, sin, sin_old;
	int f, i, sign;
	unsigned counter;
	const double pi = 3.1415926;
	
	printf("input x:");
	scanf("%lf",&x);
	x = x*pi/180.0;
	sin = 0.0;
	sign = 1;
	sin_old = 2.0;
	i = 1;
	f = 1;
	y = x;
	counter = 0;
	
	while(true)
	{
		++counter;
		sin += sign * y / f;
		sign *= -1;
		y *= x * x;
		f *= (i+1) * (i+2);
		i += 2;
		if (fabs(sin_old - sin) < 1E-6 ) break;
		sin_old = sin;
	}
	printf("sin x = %lf\ntimes:%d\n",sin,counter);
	return 0;
}
