//求字符串长度。
//这里仅做示例，几乎没有工程价值
//实际上可以直接调用strlen函数（<string.h>里）
#include<stdio.h>
size_t strlen(char *s)
//思路：一个一个数，直到'\0'
{
    size_t i = 0;
    while (*s++)//等价于 *s != '\0' ，
    {
        ++i;
        // ++s;
    }
    return i;
}

size_t new_len(char *s)//思路：指针之差
{
    char *t = s;
    while (*t++){
        //??
    }
    
}


 int main()
 {
     int i;
     char *p = "1234567890";

 

     printf("%-5ld", sizeof p);
     //这样求出来是指针长度

     printf("%-5ld", sizeof (*p));
      //得到第一个元素长度，所以也不对

    i = strlen(p);
    printf("%-5d\n", i);


   
     return 0;
 }