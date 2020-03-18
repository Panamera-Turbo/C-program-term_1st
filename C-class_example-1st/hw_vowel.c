#include <stdio.h>
//----------------------------------------------
// 判断输入字母是不是元音
//---------------------------------------------

int main(int argc, char *argv[])
{
	char letter;
	printf("input a letter:");
	scanf("%c",&letter);
	switch(letter)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':printf("It is a vowel\n");
			break;
	default:printf("It is a consonant\n");
	}
	
	return 0;
}
