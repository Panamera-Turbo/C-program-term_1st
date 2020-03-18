#include<stdio.h>
 int main ()
 {
     int a[] = {1,2,3,4,5};//int [5]
     int *p;// int *
     int i;

     int (*q)[5];//int [5]
     //数组指针
                /***********************************************
                1.和 *p 的区别：*p指的是数组里一个元素，眼里只有一个整数，
                             （*P）指的是一个数组整体，p的眼里有一个数组
                2. ()表明了优先级，说明指针时指向数组   []的优先级高于*
                3.比较罕见
                ************************************************/
    q = &a; //

    int *t[5] = {a, a+1, a+2, a+3, a+4};
    //指针数组，数组的每一个元素是指针
    

    //  *p = &a[0];//*p 指针指向了数组的第一个元，即a[0]
    // p = &a[4];//指向数组最后一个元素，a[4]
    //错误示范：*p = &a[5]这个赋值没错，但是该地址下的单元未知，如果使用，就是非法访问，错误
    //在编译器里，数组就是一个常量指针！！，因此，可以有如下简写：
    p = a;
    
    /*********************************************************************
     *              a === &a[i]
     *              *(a+i) ===a[i]
     *              a+i === *（a+i)
     *              p[i] === a[i]
     *              *(p+i) === *(a+i)
     *              p+i === a+i
     *              a[i] ===*(i+a) ===i[a]
     * *******************************************************************/

    for ( i = 0; i < 5 ; ++i)
        printf("%4d",a[i]);
       // printf("%4d",p[i]);
        // printf("%4d",*(a+i));
        // printf("%4d",*(p+i));
        // printf("%4d",i[a]);
    putchar('\n');


    for ( p = a+4 ; p >= a ; --p)//这里a[5]是哨兵
        printf("%4d",*p);
    putchar('\n');

//下面是把数组每个数移到下一个单元，第一个单元为0
//！！！这种移动只能从尾巴开始！！！！
    for ( p = a+4 ; p > a ; --p)
        {*p = *(p - 1);
        printf("%4d",*p);};
        *p = 0;
        printf("%4d", *p);
    putchar('\n');


    return 0;
 }