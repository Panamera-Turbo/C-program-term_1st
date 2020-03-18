#include <stdio.h>
//--------------------------------------------------
//找到输入数字的位置
//--------------------------------------------------

#define N 10

int main()
{ 
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int low = 0, high = N - 1, mid;
    int key;

    printf ("Enter a number between 0 and 9:");
    scanf ("%d", &key);

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == key) 
        {
            printf ("You number is at Num.%d\n", mid + 1);
            break;
        }
        else if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }

    if (low > high)
    printf ("Not found\n");

    return 0;
}
