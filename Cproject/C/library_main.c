#include "library.h"

int main(void)
{
	bookList*  bookList;

	init_list(&bookList);
	
	welcome(bookList);	
}
