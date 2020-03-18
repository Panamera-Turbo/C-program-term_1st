// #pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

#define MAX 100
#define BOOK_FILE_NAME " bookInfo.txt"
#define MAX_ID_LEN 40
#define MAX_NAME_LEN 40
#define MAX_PRICE_LEN 40
#define MAX_DISCOUNT_LEN 40

typedef struct {
	char    book_id[MAX_ID_LEN];
	char    book_name[MAX_NAME_LEN];
	int     book_price;
	char    book_discount[MAX_DISCOUNT_LEN];
	int     book_amount;
	int     book_remain;
}  bookInfo;

typedef struct node
{
	 bookInfo data;
	struct node *next;
}bookList;

typedef struct
{
    long id;
    long check;
    long value;
} stdcode;


//全局变量，存储当前书籍种类的数量
int CurrentCnt;

typedef struct
{
    long check;
    long value;
} code;

extern  void borrow_return(bookList* p);
extern  void init_list( bookList **L);
extern  int read_line(char str[], int n);
extern  bookInfo read_book_info();
extern  bool insert_item( bookList *L,  bookInfo  bookInfo, int choice);
extern  bool delete_item( bookList *L, char* book_id);
extern  bookList* search_item( bookList *L, char* book_id);
extern  bool change_item( bookList *L, char* book_id,  bookInfo new_info);
extern  void output_one_item( bookList *p);
extern  void output_all_items( bookList *L);
extern  void destory_list( bookList **L);
extern  void destory_list_and_file( bookList **L);
extern  int save_to_file(bookList *L);
extern  void price_bubble_sort(bookList *L);
extern  void id_bubble_sort(bookList *L);
extern  code read_file(void);
extern  int confirm(void);
extern  void mng_login(void);
extern  void change_code(void);
extern  char land();
extern  stdcode std_read_file(void);
extern  int std_confirm(void);
extern  void std_login(void);
extern  void change_std_code(void);
extern  char dostudent();
extern  int usrstudent( bookList* L);
extern  char domanager();
extern  int usrmanager( bookList* L);
extern  void welcome( bookList* L);
