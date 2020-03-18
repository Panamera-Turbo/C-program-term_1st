//二维数组排序，字典序
#include <stdio.h>
#include<string.h>

void bubble_sort(char a[][8], int len)
{
    int i, j;
    char t[8];

    for (i = 0; i < len - 1; ++i)
        for (j = 0; j < len - i - 1; ++j)
            if (strcmp(a[j], a[j+1])>0)
            { // block
                strcpy( t, a[j] );
                strcpy(a[j],a[j+1]);
                strcpy(a[j+1] ,t);
            }
}


int main()
{
    char plnt[][8] = 
    {
        "Mecurry",
        "Venus",
        "Earth",
        "Mars",
        "Jupiter",
        "Saturn",
        "Neptune",
        "Urinas"
    };

    int i ;

    bubble_sort(plnt,8);
    for (size_t i = 0; i < 8; i++)
    {
        printf("%s\n",plnt[i]);
    }
    
    return 0;
}