#include<stdio.h>
#include<stdlib.h>
//堆栈特点之一：后进先出
#define DEPTH 128

int stack[DEPTH];
int top;

//首先初始化堆栈
void init()
{
    top = 0;
}

// 接下来开始压栈
void  push(int v)
{
    if(top == DEPTH - 1)
    {
        printf("stack overflow\n");
        exit(EXIT_FAILURE);
        //exit函数表示立即退出， 一般为非正常退出（此时往往取负值）， 退出时为返回值-1
    }

    ++top;

    stack[top] = v;
}


// 然后是弹栈
int pop()
{
    if (top -1 < 0)
    {
        printf("stack underflow");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}

int main()
{
    int i;
    for (i=0; i<DEPTH-1; ++i)//试试DEPTH, DEPTH-2
        push (i);

    for (i = 0; i < 99; ++i)//试试DEPTH, 99会怎么
    printf("%d\n",pop());
 
    putchar('\n');
    return 0;//试试99
}