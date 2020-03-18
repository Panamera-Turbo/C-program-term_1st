/***********************************************************************************************
* 2019.11.11
*主要内容：指针                                                                       
*指针就是地址，在32位机上地址（也就是指针的大小）是32位数字，64位机是64位的数字                                                                                      
*内存线性排列，每个地址对应内存里不同位置（即编号）                             
--------------------------------------------------------------------------------------------                            
*地址从0开始排列                                                                                
*CPU为二进制，例如32位机只能查找到  2的32次方-1  的地址
*整数存储时，一个字节存不下，会把多个（4个）字节连在一起存储一个整数
*整数的存储地址为其存放的第一个字节编号，且一般为偶数编号，四字节对齐
*偶字节对齐，四字节对其……一般为2的幂次对齐
*两个相邻地址不一定是相连的编号（地址），可能中间因为对齐而被填充了无效的字节
*如果一个字符类型后面紧跟一个整形，？？？？？
*内存重解释：双刃剑，可能好用，也可能被恶意利用
*星号是指针的标志
************************************************************************************************/
#include<stdio.h>
int main()
{
    int i = 1;
    //double j=2.33
    int *p, *q;
        //*是指针的标志,*p装的是地址,
        //指针*p受到约束：1：只能装地址
        //               2.基类型约束，只能装指定的类型（如int  float等）
        //浮点数的指针是浮点指针，整数类型的指针是整数指针，指针的指针是  指针指针   。
    
    p = &i; 
        //指针指向变量 i ，获取其地址
        //p的值是i的地址，i的值仍然不变，p的地址不知道
        //
        //若此处添加 p =&j， 这就是内存重解释，应该避免

   /**************************************************************
    * 实验用，如果使用，下面所有都应该被注释掉
    *printf("%p,%p\n",p,&i);//结果是16进制
    *printf("%ls,%ls\n",p,&i);//u 是无符号十进制类型
    *printf("%ld,%ld\n",sizeof(p),sizeof(long));
    **************************************************************/


   //q = p;//这时，*q也是指向i，改变*p==改变*q==该变i
    

    *q = *p;//野指针
            //解决：在开头增加int j，int *q = &j;，进行初始化。使得这个野指针变成了i = j



  //i = 2;//直接赋值
  // *p = 2;//把2 赋给*p 所指向的地址里的变量
            //左值运算符



  //  ++ *p;
  // *p++;//有错误， 快去搞一个内存消毒器！！！！！！！！！！！！
  //gcc $1 -g -Wall -fsanitize=address
    printf("%d,%d\n",i,*p);
    return 0;
}