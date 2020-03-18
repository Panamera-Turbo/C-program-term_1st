#include <stdio.h>
typedef struct node
{
    int data;
    struct node *next;
} NODE,*NODEPTR;

void traverse(NODEPTR head)//遍历
{
    NODEPTR p = head;
    while (p != NULL)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
}

int main()
{
    NODE a = {1,NULL},b = {2,NULL}, c = {3,NULL};
    NODEPTR head, p;

    a.next = &b;
    b.next = &c;

    head = &a;
    traverse(head);

    return 0;
}