#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXN 35
#define MAX_NAME 256
typedef struct student  //学生信息
{
	int  no;
	char name[MAX_NAME];
	double  english;
	double  math;
	double  programming;
	double  mark_ave;
	double  mark_tot;
	STUDENT* next;
} STUDENT;

void unit(STUDENT *PL){
STUDENT inf;
char filename[100] ;
STUDENT *q = PL, *p;
FILE *fp;
printf("Please enter the file you want: \n");
scanf("%s" , filename);
getchar(); 
fp = fopen(filename, "r");
if(fp == NULL)
printf("There isn't such a file.");
if ((fp = fopen("data2.txt","w"))== NULL)
printf("Cannot create such a file.");
while(!feof(fp)){
fscanf(fp,"%d",inf.no);
fscanf(fp, "%s",inf.name); 
fscanf(fp,"%f",inf.english);
fscanf(fp,"%f",inf.math);
fscanf(fp,"%s\n",inf.programming);
p = (STUDENT*)malloc(sizeof(STUDENT));
// p->data = inf ; 
p->next=p;
p = p;
// ++q->size;
}
p->next = NULL ;
fclose(fp);
printf(" initialized successfully!\n");
}
/*-----------输入信息子程序---------*/
void input(STUDENT *data, int *len) 
{
	int no;
	putchar('\n');
	printf("%s\n", "请输入新的记录，如果需要退出当前菜单请输入-1.");
	printf("%s\n", "格式：\n学号\n");
	printf("%s\n", "姓名 英语 数学 C语言");
	putchar('\n');
	printf("如:\n");
	printf("5\n");
	printf("黄瑞 100 100 100\n");
	scanf("%d", &no);
	while(no != -1) {
		data[*len].no = no;
		scanf("%s %lf %lf %lf", data[*len].name, &data[*len].english, &data[*len].math,&data[*len].programming);		data[*len].mark_ave=(data[*len].english+data[*len].math+data[*len].programming)/3.0;		data[*len].mark_tot=data[*len].english+data[*len].math+data[*len].programming;
		(*len)++;
		scanf("%d", &no);
	}	
}
/*---------------输出信息子程序---------------*/
void output(STUDENT *data, int len)
{
  int i;
	  ;
  printf("%8s", "学号");
  printf("%8s", "姓名");
  printf("%8s", "英语");
  printf("%8s", "数学");
  printf("%10s", "计算机");
  printf("%12s", "平均分");
  printf("%10s", "总分");
  putchar('\n');
  for (i =0; i < 80; i++)
    putchar('=');
  putchar('\n');
  for (i = 0; i< len; i++)
  {
    printf("%8d", data[i].no);
    printf("%8s", data[i].name);
    printf("%8.1lf", data[i].english);
    printf("%8.1lf", data[i].math);
    printf("%10.1lf", data[i].programming);
    printf("%12.1lf", data[i].mark_ave);
    printf("%10.1lf", data[i].mark_tot);
    putchar('\n');
  }
  for (i =0; i < 80; i++)
    putchar('=');
  putchar('\n');
  printf("按回车键继续.");
  getchar();
  getchar();
}
/*--------------排序子程序------------*/
void sort(STUDENT *data, int len)
{
  int i,j,k;
  STUDENT temp;
  for (i=0; i<len-1; i++) {
    for (k=i, j=i+1; j<len; j++)
      if (data[k].mark_ave > data[j].mark_ave) k=j;
			if (k != i) {
				temp = data[i];
				data[i] = data[k];
				data[k] = temp;
			}
  }
}
/*--------------------搜索子程序-----------------------*/
void find(STUDENT *data, int len)
{
  int find_no, result ;
  int i;
lab: result=0;
		 printf("%s\n", "请输入需要查找的学生的学号，退出当前菜单请输入 -1.");
		 scanf("%d", &find_no);
		 if (find_no == -1) return;     /*exit the fine sub program*/
		 while( data[result].no != find_no && result < len) result ++;
		 if (result >= len ) {
			 printf("%s\n", "未查询到相关信息");
			 goto lab;
		 }
		 else {
			   ;
			 printf("%s\n", "查询信息如下：");
			 for (i =0; i < 80; i++)
				 putchar('=');
			 putchar('\n');
			 printf("%8s", "学号");
			 printf("%8s", "姓名");
			 printf("%8s", "英语");
			 printf("%8s", "数学");
			 printf("%10s", "计算机");
			 printf("%12s", "平均分");
			 printf("%10s", "总分");
			 putchar('\n');
			 printf("%8d", data[result].no);
			 printf("%8s", data[result].name);
			 printf("%8.1lf", data[result].english);
			 printf("%8.1lf", data[result].math);
			 printf("%10.1lf", data[result].programming);
			 printf("%12.1lf", data[result].mark_ave);
			 printf("%10.1lf", data[result].mark_tot);
			 putchar('\n');
			 for (i =0; i < 80; i++)
				 putchar('=');
			 putchar('\n');
			 goto lab;
		 }
}
/*-----------------插入子程序-------------*/
void insert(STUDENT *data, int *len)
{
  int no, pos;
	double english, math, programming, mark_ave, mark_tot;
	int i;
  char name[MAX_NAME];
lab: printf("%s\n", "输入新的记录，退出当前菜单请输入-1.");
		 printf("%s\n", "格式：学号");
		 printf("%s\n", "      姓名 英语 数学 计算机");
		 scanf("%d", &no);
		 if (no == -1) return;
		 data[*len].no = no;
		 scanf("%s %lf %lf %lf", name, &english, &math, &programming);
		 mark_ave=(english+math+programming)/3.0;
		 mark_tot=english+math+programming;
		 pos = 0;
		 while ((data[pos].mark_ave < mark_ave) && (pos < *len) )
			 pos ++;
		 for (i = *len-1; i >= pos; i--)
			 data[i+1] = data[i];
		 data[pos].no = no;
		 strcpy(data[pos].name, name);
		 data[pos].english = english;
		 data[pos].math = math;
		 data[pos].programming = programming;
		 data[pos].mark_ave = mark_ave;
		 data[pos].mark_tot = mark_tot;
		 (*len)++;
		 goto lab;
}
/*-------------删除子程序--------------*/
void delete_item(STUDENT *data, int *len)
{
  int no, i, pos;
lab: pos=0;
		 printf("%s\n", "输入需要删除的学生的学号，退出当前菜单请输入-1.");
		 scanf("%d", &no);
		 if (no == -1) return;
		 while( (data[pos].no != no) && (pos < *len) ) pos = pos +1;
		 if (pos >= *len) {
			 printf("%s\n", "未找到需要删除的学生");
			 goto lab;
		 }
		 else {
			 for (i = pos+1;i < *len; i++)
				 data[i-1] = data[i];
			 *len = *len -1;
			 if (*len == 0) {
				 printf("%s\n", "没有任何记录，请按回车键返回.");
				 getchar();
				 getchar();
				 return;
			 }
			 goto lab;
		 }
}

/*---------------统计子程序------------*/
void stat(STUDENT *data, int len)
{
  int no_59=0, no_69=0, no_79=0, no_89=0, no_100=0;
  int i;
  for (i = 0;i < len; i++) {
    if (data[i].mark_ave <=59) no_59++;
    else if (data[i].mark_ave <=69) no_69++;
		else if (data[i].mark_ave <=79) no_79++;
		else if (data[i].mark_ave <= 89) no_89++;
		else no_100++;
  }
	  ;
  for (i =0; i < 80; i++)
    putchar('=');
	putchar('\n');
  printf("%10s", "分数");
  printf("%10s", "0--59");
  printf("%10s", "60--69");
  printf("%10s", "70--79");
  printf("%10s", "80--89");
  printf("%10s", "90--100");
  putchar('\n');
  putchar('\n');
  printf("%10s", "学生");
  printf("%10d", no_59);
  printf("%10d", no_69);
  printf("%10d", no_79);
  printf("%10d", no_89);
  printf("%10d", no_100);
  putchar('\n');
  for (i =0; i < 80; i++)
    putchar('=');
  putchar('\n');
  printf("按回车键返回");
  getchar();
  getchar();
}
/*---------------显示信息子程序------------*/
void paint()
{
  int i;
	  ;
  printf("%55s\n", "学生管理系统\n");
  printf("           制作者:自动控制欲进行工程学院电气 (2)班  吴洲洋  \n");
  for (i = 0; i < 80; i++)
    putchar('=');
  putchar('\n');
  printf("             1 输入信息                        2 输出信息\n");
  printf("             3 按平均分排序                    4 按学号查找\n");
  printf("             5 插入                            6 按学号删除\n");
  printf("             7 按平均分输出统计信息            8 保存到文件\n");
  printf("             0 退出\n");
	for (i = 0; i<= 79; i++)
    putchar('=');
  putchar('\n');
  printf("%s\n", "请输入各操作对应的序号:");
}
void save(STUDENT *data, int len)//将数据保存到文件
{
	int i;
	FILE *fp;
	fp=fopen("成绩统计表.txt","w");
	fprintf(fp,"%8s", "学号");
  fprintf(fp,"%8s", "姓名");
  fprintf(fp,"%8s", "英语");
  fprintf(fp,"%8s", "数学");
  fprintf(fp,"%10s", "计算机");
  fprintf(fp,"%12s", "平均分");
  fprintf(fp,"%10s\n", "总分");
  fprintf(fp,"========================================================================\n");
  putchar('\n');
  for (i = 0; i< len; i++)
  {
    fprintf(fp,"%8d", data[i].no);
    fprintf(fp,"%8s", data[i].name);
    fprintf(fp,"%8.1lf", data[i].english);
    fprintf(fp,"%8.1lf", data[i].math);
    fprintf(fp,"%10.1lf", data[i].programming);
    fprintf(fp,"%12.1lf", data[i].mark_ave);
    fprintf(fp,"%10.1lf\n", data[i].mark_tot);
  }
  fprintf(fp,"========================================================================\n");
	fclose(fp);
	printf("文件已保存到\"成绩统计表.txt\"");
	getchar();getchar();
}
/*-----------主程序--------------*/
int main()
{
	STUDENT **L;
	unit(&L);
  STUDENT data[MAXN];
  int len = 0;
  char ctrl_ch;
  paint();
  scanf("%c", &ctrl_ch);
  while (ctrl_ch != '0') {
    switch(ctrl_ch) {
		case '1':
			input(data, &len);
			break;
		case '2':
			output(data, len);
			break;
		case '3':
			sort(data, len);
			break;
		case '4':
			find(data, len);
			break;
		case '5':
			insert(data, &len);
			break;
		case '6':
			delete_item(data, &len);
			break;
		case '7':
			stat(data, len);
			break;
		case '8':
			save(data, len);
			break;
		default:
			if (ctrl_ch != '\n') printf("%s\n", "输入错误!");
			break;
    }
    if (ctrl_ch != '\n') paint();
    scanf("%c", &ctrl_ch);
  }
  return 0;
}

