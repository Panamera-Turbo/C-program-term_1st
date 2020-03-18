#include "library.h"

char land(){
    char c, flag;
    int i;
    while(1){
        for(i = 0; (c = getchar()) != '\n'; flag = c, ++i)
            ;
        if(i == 1){
            if(flag == '1' || flag == '2' || flag == '0'){
                return flag;
            }
        }else if(i == 0){
            continue;
        }
        printf("[请输入命令： 1 / 2 / 0 选择项目]");
    }
    return '\0';
}



//-----------------------------------------------------------------------------------
char dostudent(){//执行输入学生选项后的工作内容
    char c, flag;
    int i;
    while(1){
        for(i = 0; (c = getchar()) != '\n'; flag = c, ++i )
            ;
        if(i == 1){
            if(flag <= '3'&& flag >= '0'){
                return flag;
            }
        }else if(i == 0){
            continue;
        }
        printf("[请输入命令： 1 / 2 / 3/ 0 选择项目]");
    }
}
//--------------------------------------------------------------------------------------------------------

int usrstudent( bookList* L){
    
	 while (1) {
		// int choice;
		// bookInfo item;
		char temp_id[MAX_ID_LEN];
		printf("-------------------------------------\n");
		printf("请输入项目前编号执行相关操作：\n\n");
		printf("[1] 查看所有馆藏图书\n[2] 查找图书（可借阅或归还）\n[3] 修改密码\n[0] 返回主页\n");

		printf("输入您的选择: ");

		switch(dostudent()) {
			case '1':
				output_all_items(L);
				break;
			case '2':
				printf("输入要索引的 ID：");
				read_line(temp_id, MAX_ID_LEN);
				 bookList* p = search_item(L, temp_id);
				output_one_item(p);
				borrow_return(p);
				break;
			case '3':
				change_code();
				break;
			default:
				printf("您已经退出图书馆书籍管理系统!\n");
				destory_list(&L);
				return 0;
		}
		
	}
}


//--------------------------------------------------------------------------------
char domanager(){

    char c, flag;
    int i;
    
    while(1){
        for(i = 0; (c = getchar()) != '\n'; flag = c, ++i)
            ;
        if(i == 1){
            //if(flag <= '9'&& flag >= '1'){
            return flag;
        }else if(i == 0){
            continue;
        }
        printf("无效命令");
            
    }
    
    return '\0';
}


//----------------------------------------------------------------------
int usrmanager( bookList* L){
    char temp_id[MAX_ID_LEN];
	 bookInfo item;
	while (1) {
		// int choice;
		printf("图书馆书籍管理系统\n");
		printf("********************************************\n");
		printf("1.显示所有书籍的信息:\n");
		printf("2.修改某个书籍的信息:\n");
		printf("3.插入某个书籍的信息:\n");
		printf("4.删除某个书籍的信息:\n");
		printf("5.查找某个书籍的信息:\n");
		printf("6.书籍存盘并退出系统:\n");
		printf("7.对书籍价格进行排序:\n");
		printf("8.对书籍的ID进行排序:\n");
		printf("9.(慎用)删除所有内容:\n");
		printf("t.修改密码\n");
		printf("其他.不存盘并退出系统:\n");
		printf("********************************************\n");
		printf("输入您的选择: ");

		// scanf("%d", &choice);
		switch (domanager()) {
			case '1':
				output_all_items(L);
				 
				break;
			case '2':
				printf("输入要修改记录的 ID：");
				read_line(temp_id, MAX_ID_LEN);
				item = read_book_info();
				change_item(L, temp_id, item);
				break;
			case '3':
				item = read_book_info();
				int pos;
				printf("输入数字表明你要插入的书籍位置：0.书籍列表尾部 1.书籍列表头部 i.书籍列表中间第i号位置\n");
				scanf("%d", &pos);
				insert_item(L, item, pos);
				break;
			case '4':
				printf("输入要删除记录的 ID：");
				read_line(temp_id, MAX_ID_LEN);
				delete_item(L, temp_id);
				printf("删除成功！");
				break;
			case '5':
				printf("输入要查找记录的 ID：");
				read_line(temp_id, MAX_ID_LEN);
				 bookList* p = search_item(L, temp_id);
				output_one_item(p);
				break;
			case '6':
				save_to_file(L);
				printf("您已经存盘并退出图书馆书籍管理系统!\n");
				return 0;
			case '7':
				price_bubble_sort(L);
				output_all_items(L);
				break;
			case '8':
				id_bubble_sort(L);
				output_all_items(L);
				break;
			case '9':
				destory_list_and_file(&L);
				printf("您已经删除书籍文件内容以及链表内容!\n");
				return 0;
			case 't':
				change_code();
				break;
			default:
				printf("您已经退出图书馆书籍管理系统!\n");
				destory_list(&L);
				return 0;
		}
	}
}


void welcome( bookList* L){
    printf("*************************欢迎使用图书管理系统*************************\n");
    while(1){
        printf("-------------------------------------\n");
        printf("请输入项目前编号执行相关操作：\n");
        printf("\n[1] 管理员入口\n\n[2] 学生入口\n\n[0] 退出\n\n");
        switch(land()){
            case '1':
                mng_login();
                while(1){
                    if(usrmanager(L)){
                        continue;
                    }else{
                        break;
                    }
                 }
                break;
            case '2':
                std_login();
                while(1){
                    if(usrstudent(L)){
                        continue;
                    }else{
                        break;
                    }
                }
                break;
            case '0':
                exit(0);
            default:
                printf("无效命令");
				break;
        }
    }
}