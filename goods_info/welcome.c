#include"library.h"
//创建链表并显示登录界面
void init(Book**L){
    FILE* f;
    Book *r;
    f = fopen("book.txt","rt");
    
    if (f == NULL)
	{
		printf("cannot open\n");
		exit(1);
	}
    else{
    (*L) = (Book*)malloc(sizeof(Book));
    r = (*L);
    while (!feof(f))
    {
        Book*n = (Book*)malloc( sizeof(Book));
        fscanf(f,"%s",n->name);
		fscanf(f,"%d",&n->id);
		fscanf(f,"%d",&n->count);
		fscanf(f,"%d",&n->status);

        r->next = n;
        r = n;
        n->next = NULL;
    }
	
    fclose(f);
    }
}
void welcome(){
    printf("*************************欢迎使用图书管理系统*************************\n");
    while(1){
        printf("-------------------------------------\n");
        printf("请输入项目前编号执行相关操作：\n");
        printf("\n[1] 管理员入口\n\n[2] 学生入口\n\n[0] 退出\n\n");
        switch(land()){
            case '1':
                mng_login();
                while(1){
                    if(usrmanager()){
                        continue;
                    }else{
                        break;
                    }
                 }
                break;
            case '2':
                std_login();
                while(1){
                    if(usrstudent()){
                        continue;
                    }else{
                        break;
                    }
                }
                break;
            case '0':
                exit(0);
            default:
                error("采集项目参数失败");
        }
    }
}