#pragma once
#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AVAILABLE 0
#define UNAVAILABLE 1
#define MAXNAME 30
#define CLEAR "cls"


typedef struct book{         //结构定义
    char name[20];
    int id;
    int count;
    int status;
    struct book *next;
}Book,*bookptr;

int nbook;
Book *head;

extern  void init();                  //初始化
extern  void std_login();
extern  void mng_login();                 // [密码登录]
extern  void welcome();
extern  void error(char *);           // [异常提醒]
extern  char land();                  // [主页面项目]
extern  char dostudent();
extern  int usrstudent();             // [学生入口]返回 0表示返回主页 1表示继续执行本函数
extern  int usrmanager();             // [管理员入口]返回 0表示返回主页 1表示继续执行本函数
extern  int viewbook();               // [查看图书]返回打印的图书个数     失败返回-1
extern  int addbook();                // [注册图书]添加图书成功 返回图书id  失败返回-1
extern  int modbook();                // [修改图书]修改图书信息   成功后返回id  失败 -1
extern  int delbook();                // [注销图书]删除成功 返回被删除图书的id 失败返回-1
extern  void printbook(Book *);       // [打印图书]
extern  Book *lookup(char *, int);    // [搜索图书]
extern  int borrowbook();             // [借阅图书]
extern  int returnbook();             // [归还图书]