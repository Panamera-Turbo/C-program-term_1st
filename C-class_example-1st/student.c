#include<stdio.h>

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
    //  struct date
    // {
    //     unsigned year, month, day;
    // }dob;//在C语言中这种嵌套合法，且不影响，从外部也可以访问
}student;



int main()
{
    student s = {1000, "cqz", MALE,{2001, 8, 24}};
    student *p = &s;

    // scanf("%u%s %c", &s.id, s.name, &s.gender);//输入时以空格为输入时的分隔符
    printf("%u,%s,%s,%u\n", 
        s.id, p->name, s.gender == MALE ? "MALE" : "FEMALE",
        p->dob.year/*相当于（p->dob）。year*/);

    return 0;
}