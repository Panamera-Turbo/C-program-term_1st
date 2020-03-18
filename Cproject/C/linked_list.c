#include "library.h"

//-------------------------------------------------------------
//初始化链表
//参数：链表指针的指针链表：02-初始化

// 函数原型：void init_list( bookList **L) 其中 *L 为指向链表头结点的指针，L为指向链表头结点指针的地址，
// init_list首先创建链表的头结点，后读取goodinfo.txt中的书籍信息，并初始化链表，函数执行后，需确保 *L 为指向链表头结点的指针。

//  init_list 实现书籍信息链表的初始化，函数从已有的书籍信息文件goodinfo.txt中读入书籍信息，并且分配内存保存至链表中。
// 为了方便在表头插入和删除结点的操作，经常在表头结点（存储第一个元素的结点）的前面增加一个结点，称之为头结点或表头附加结点。
// 这样原来的表头指针由指向第一个元素的结点改为指向头结点，头结点的数据域为空，头结点的指针域指向第一个元素的结点。
void init_list(bookList **L) {
	//从文件 bookInfo.txt中读入数据

	CurrentCnt = 0;
	FILE* f;
	f = fopen("bookinfo.txt","rt");
	if (f == NULL)
	{
		printf("cannot open\n");
		exit(1);
	}
	else{
	bookList *r ;
	(*L) = (bookList*)malloc(sizeof( bookList));
	r = (*L);
	
	while (!feof(f))
	{
		bookList* n = (bookList*)malloc(sizeof( bookList));

		fscanf(f,"%s",n->data.book_id);
		fscanf(f," %s",n->data.book_name);
		fscanf(f," %d",&n->data.book_price);
		fscanf(f," %s",n->data.book_discount);
		fscanf(f," %d",&n->data.book_amount);
		fscanf(f," %d",&n->data.book_remain);
		
		r->next = n;
		r = n;
		n->next = NULL;

		++CurrentCnt;
	}
	
	fclose(f);
	printf("书籍的链表文件已建立，有 %d 个书籍记录\n", CurrentCnt);
	}
}

//-------------------------------------------------------------
//添加一条书籍记录
// 函数原型：bool insert_item( bookList *L,  bookInfo  bookInfo, int choice)， L为指向链表头结点的指针，
// 函数根据choise的值，将 bookInfo插入到链表的指定位置，如果成功插入，函数返回true，如果未插入，函数返回false。
// 分别实现头插法、尾插法，中间位置插入三种:
// 用户输入0，将书籍信息插入到链表尾部；
// 用户输入1，将书籍信息插入到链表头部；
// 用户输入其它正整数i，将书籍信息插入到链表中间第i号位置, 例如：输入3，应该在第二个节点后插入新节点
//-------------------------------------------------------------
bool insert_item( bookList *L,  bookInfo  bookInfo, int choice) { 
	//在链表*L中添加一个记录 bookInfo
	//choice指明了添加位置

	  bookList *cur, *prev, *new_node;
    new_node = ( bookList*)malloc(sizeof( bookList));
    new_node->data =  bookInfo;
    if (choice == 0) {
        for (prev = NULL, cur = L; cur != NULL; prev = cur, cur = cur->next)
            ;
        new_node->next = NULL;
        if (prev == NULL)
            L = new_node;
        else
            prev->next = new_node;
        return true;
    } else if (choice == 1) {
        if (L->next == NULL)
            L->next = new_node;
        else {
            new_node->next = L->next;
            L->next = new_node;
        }
        return true;
    } else {
        int pos = 1;
        for (prev = NULL, cur = L; cur != NULL; prev = cur, cur = cur->next) {
            if (pos == choice)
                break;
            pos++;
        }
		if (pos < choice)
            return false;
        new_node->next = cur->next;
        cur->next = new_node;
        return true;
    }
}


//-------------------------------------------------------------
//删除一条书籍记录
// 函数原型：bool delete_item( bookList *L, char* book_id) 
// 其中L为指向链表头结点的指针，book_id为要删除书籍的ID； 如果成功删除，函数返回true，否则返回false。

// delete_item 根据书籍的ID来删除对应的书籍信息，书籍查找通过字符串比较的方式，查找到后释放对应指针指向的内存区域，完成删除。
//-------------------------------------------------------------
bool delete_item( bookList *L, char* book_id) {
	//在链表中删除指定ID号的记录
	//提示：先找到ID号记录在哪里
	 bookList *prev1,*prev2;
	prev1 = L;
	prev2 = prev1->next;
	bool flag = true;
	while (strcmp(prev1->next->data.book_id,book_id) != 0)
	{
		if(prev2 == NULL){
			flag = false;
		}
		prev1 = prev1->next;
		prev2 = prev1->next;
		
	}
	if (flag == true)
			{
				prev1->next = prev2->next;
				free(prev2);
				return true;
			}
	
	return false;
}


//-------------------------------------------------------------
//查找一条书籍记录
//返回值：指向找到的记录的指针
//-------------------------------------------------------------
 bookList* search_item( bookList *L, char* book_id) {
	//在链表中查找指定ID号的记录

    if (L->next != NULL)
	{
         bookList* p;
        p = L->next;
        while (strcmp(book_id, p->data.book_id) != 0 && p->next != NULL) 
		p = p->next;
        
        return p;
    } 
	else
        return L;
}

//-------------------------------------------------------------
//修改一条书籍记录
//-------------------------------------------------------------
bool change_item( bookList *L, char* book_id,  bookInfo new_info) {
	//修改链表中的指定记录
	//先查找指定ID号的记录，然后再用new_info替换它
	 bookList *change;	
	change = search_item(L, book_id);
	if(change == NULL)return false;
	else
	{
		change->data = new_info;
		return true;
	}
}


//-------------------------------------------------------------
//打印单本书籍链表节点的信息
//按指定格式打印一条记录的信息
//-------------------------------------------------------------
void output_one_item( bookList *p){
	if(p != NULL)
	printf("ID:%-8s名称:%-8s价格:%-5d折扣:%-8s总数量:%-8d剩余:%-8d\n",
	p->data.book_id,p->data.book_name, p->data.book_price, p->data.book_discount, p->data.book_amount, p->data.book_remain);
	
}


//-------------------------------------------------------------
//在屏幕上输出所有书籍信息
//-------------------------------------------------------------
void output_all_items( bookList *L)
{
	 bookList *q;
	q = L->next;
	while(q != NULL)
	{
		output_one_item(q);
		q = q->next;
	}
}

//-------------------------------------------------------------
//释放书籍链表
//该函数释放包括头结点在内的所有结点，完成后指向链表头结点的指针为NULL。
//-------------------------------------------------------------
void destory_list( bookList **L) {
	 bookList *d;
	 bookList *k;
	d = *L;
	k = d->next;
	while (k != NULL)
	{
		d = k;
		k = k->next;
		free(d);
	}
	
}


//-------------------------------------------------------------
//删除书籍文件以及书籍链表中的所有信息
//-------------------------------------------------------------
void destory_list_and_file( bookList **L) {
	//删除文件用remove函数
	destory_list(L);
	remove("bookinfo.txt");
}

//-------------------------------------------------------------
//将当前书籍链表中的内容存入书籍文件 bookinfo.txt，返回书籍的个数
//-------------------------------------------------------------
int save_to_file(bookList *L) {
	FILE* txt = fopen("bookinfo.txt", "wt");
    int num = 0;

    for (L = L->next; L != NULL; L = L->next) {
        num++;
         bookInfo temp = L->data;
        fprintf(txt, "%-10s%-30s%-10d%-10s%-10d%-10d\n", temp.book_id, temp.book_name, temp.book_price, temp.book_discount, temp.book_amount, temp.book_remain);
    }
    fclose(txt);
    return num;
}

//--------------------------------------------------------------------
//冒泡排序实现对链表节点的排序，对价格从低到高排序
//--------------------------------------------------------------------
void price_bubble_sort(bookList *L) {
	 bookList *p, *q;
	p = L;
	int a, b;

    for (a = 0;a < CurrentCnt; ++a)
    {
		p = L;
        q = p->next;
        for (b=0; b < CurrentCnt-1; ++b)
        {
            if (p->data.book_price > q->data.book_price)
            { 
                 bookInfo t = p->data;
                p->data = q->data;
                q->data = t;
            }
            p = p->next;
            q = q->next;
        }
    }
}

void id_bubble_sort(bookList *L) {
	 bookList *p, *q;
	p = L;
	int a, b;

    for (a = 0;a < CurrentCnt; ++a)
    {
		p = L;
        q = p->next;
        for (b=0; b < CurrentCnt-1; ++b)
        {
            if (strcmp(p->data.book_id, q->data.book_id) > 0)
            { 
                 bookInfo t = p->data;
                p->data = q->data;
                q->data = t;
            }
            p = p->next;
            q = q->next;
        }
    }
}

//----------------------------------------------------------------------
//书籍借阅归还
//------------------------------------------------------------------
void borrow_return(bookList* p){
	int choi;
	printf("请输入选项对应的数字：\n[1]借阅\n[2]归还\n");
	scanf("%d",&choi);
	switch (choi)
	{
	case 1:
	printf("请注意您一次只能借阅一本书籍！\n");
		p->data.book_remain -= 1;
		break;
	case 2:
		printf("请注意您一次只能归还一本书籍！\n");
		p->data.book_remain += 1;
		break;
	default:
		printf("wrong order(s)!");
		break;
	}
}