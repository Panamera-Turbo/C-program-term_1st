#include "library.h"

//-------------------------------------------------------------
//以行读取输入的信息
//-------------------------------------------------------------
int read_line(char str[], int n)
{
	int ch, i = 0;

	while (isspace(ch = getchar()))
		;
	while (ch != '\n' && ch != EOF) {
		if (i < n)
			str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';
	return i;
}

 bookInfo read_book_info()
{	//在这个函数中从键盘读入一个book的数据
	//如果是字符串，请调用read_line
	 bookInfo  bookInfo;
	printf("输入id：");
	read_line( bookInfo.book_id , MAX_ID_LEN);
	printf("输入名字（空格用'_'代替）：");
	read_line( bookInfo.book_name, MAX_NAME_LEN);
	printf("输入价格：");
	scanf("%d",& bookInfo.book_price);
	printf("输入折扣：");
	read_line( bookInfo.book_discount, MAX_DISCOUNT_LEN);
	printf("输入数量：");
	scanf("%d",& bookInfo.book_amount);
	printf("输入剩余：");
	scanf("%d",& bookInfo.book_remain);
	
	return  bookInfo;
}