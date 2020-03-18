#include <stdio.h>
#include<stdlib.h>
/********************************************
 * 
 * 包含链表，指向指针的指针，指向函数的指针
 * 
 * ******************************************/

typedef void (*FUNPTR)(int);
/*************************************************************
 * 
 * 这句话 定义了 一种指针类型 ，指向一个函数，带有一个int型参数。返回值void
 * 
 * 注意，函数和数组类似，函数名就是指针
 * 
 * **************************************************************/

typedef struct node
{
    int data;
    struct node *next;
} NODE,*NODEPTR;

//下面是遍历的常用发法
void traverse(NODEPTR head, FUNPTR callback)
//callback 回调函数，这样便于更好的更改回调函数，而不必改变遍历函数
{
    NODEPTR p = head;
    while (p != NULL)
    {
        callback(p->data);
        // printf("%d\n",p->data);
        p = p->next;
    }
}
void print (int v)
{
     printf("%d\n",v);
}

void print_new (int v)
{
    printf("%d\n",v*10);
}

int main()
{
    NODE a = {1,NULL},b = {2,NULL}, c = {3,NULL};
    NODEPTR head = &a,p;

    a.next = &b;
    b.next = &c;

    p = (NODEPTR)malloc(sizeof(NODE));

    p->data = 5;
    p->next = NULL;

    c.next = p;

    traverse(head,print);
    traverse(head,print_new);

    free(p);

    return 0;
}