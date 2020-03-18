#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define PI 3.1415926//另外一种定义方法   const double PI = 3.1415926;

// struct _circle
// {
//     double x, y;
//     double r;
// };//定义一种结构类型，意味着这样的单元并不实际存在，但是可以使用

// typedef struct _circle CIRCLE;//CIRCLE 是circle 的别名


typedef struct
{
double x,y;
double r;
}circle;

double area(circle *c)
{
    return c->r*c->r*PI;//这里的r是局部变量，掩蔽了上面的全局变量r
}

circle make_circle() //随机生成一个圆

{
    circle t;
    t.x = rand() % 100;
    t.y = rand() % 100;
    t.r = rand() % 10;

    return t;
}

int main()
{
    circle c;
    int i;

    srand(time(NULL));

    for (size_t i = 0; i < 5; ++i)
    {
        c = make_circle();
        printf("(%.2lf,%.2lf),(%.2lf)=>%.2lf\n",c.x, c.y, c.r, area(&c));//注意&c
    }
    
    return 0;
}