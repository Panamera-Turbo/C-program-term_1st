
#include<stdio.h>
#include<string.h>

typedef char GENDER;
const GENDER MALE = 'M';
const GENDER FEMALE = 'F';

typedef struct 
{
    unsigned year, month, day;
}date;

typedef struct student
{
    unsigned id;
    char name[32];
    GENDER gender;//'F' for male, 'F' for female ;
    date dob;
}student;

void bubble_sort(student a[], int len)
{
    int i, j;
    student t;

    for (i = 0; i < len - 1; ++i)
        for (j = 0; j < len - i - 1; ++j)
            if (strcmp(a[j].name, a[j+1].name)>0)
            { // block
                t = a[j] ;
                a[j] = a[j+1];
                a[j+1] = t;
            }
}

int main()
{
    student s[4] = {
        {1000,"Ken",MALE},
        {1001,"Lee",MALE},
        {1002,"Candy",FEMALE},
        {1003,"Linda",FEMALE}
    };//结构数组的初始化
    int i;
    student *p;
    p = s;
    bubble_sort(s,4);
    
    for (size_t i = 0; i < 4; ++i,++p)
    {
        printf("%u,%s,%s\n", p->id, p->name, p->gender == MALE ? "MALE" : "FEMALE");
    }
    
    

    return 0;
}