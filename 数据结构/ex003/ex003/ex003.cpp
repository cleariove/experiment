#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Line
{
	int num;
	struct Line *next_line;
	struct Character *point_char;
}Line;

typedef struct Character
{
	char data;
	struct Character *next;
}Character;

void show(Line* &head)		//展示文本内容
{
	Line *p1;
	Character *p2;
	int i,j;
	p1 = head->next_line;
	p2 = p1->point_char;
	for(i = 0;i < head->num+1;i++)
	{
		for(j = 0;j < p1->num;j++)
		{
			printf("%c",p2->data);
			p2 = p2->next;
		}
		p1 = p1->next_line;
		if(p1 != NULL)
			p2 = p1->point_char;
	}
}

void insert(Line* &head)
{
	Line *p1 = head;
	Character *p2,*p3,*p4,*temp;
	int m,n,i,j;
	printf("在第x行，第y个字母前插入,请输入x，y:");
	scanf("%d%d",&i,&j);
	getchar();
	if(i<1 || i > head->num)
		printf("输入有误!\n");
	for(m = 0;m<i;m++)
		p1 = p1->next_line;
	if(j<1 || j > p1->num+1)
		printf("输入有误!\n");
	p2 = p1->point_char;
	printf("请输入插入的内容:");
	p3 = p4 = temp = (Character*)malloc(sizeof(Character));
	n = 0;
	while(1)
	{
		scanf("%c",&p4->data);
		if(p4->data == '\n')
		{
			free(p4);
			p3 = temp;
			for(m = 1;m < n;m++)
				p3 = p3->next;
			p3->next = NULL;
			break;
		}
		else
		{
			n++;
			p4 = (Character*)malloc(sizeof(Character));
			p3->next = p4;
			p3 = p4;
		}
	}
	p1->num += n;
	p3 = temp;
	while(p3->next)
		p3 = p3->next;
	if(j == 1)
	{
		p3->next = p2;
		p1->point_char = temp;
	}
	else
	{
		for(m = 2;m<j;m++)
			p2 = p2->next;
		p3->next = p2->next;
		p2->next = temp;
	}
}

void delete_line(Line *head,int m)
{
	int i,j,n;
	Line *p2 = head,*p1 = head;
	if(m)
	{
		printf("从第i行开始，删除j行。请输入i,j:");
		scanf("%d %d",&i,&j);
	}
	else
	{
		printf("请输入删除的行:");
		scanf("%d",&i);
		j = 1;
	}
		if(i < 0 || i+j-1 > head->num)
			printf("输入有误！");
		for(n = 1;n < i;n++)
			p1 = p1->next_line;
		for(n = 0;n < i + j - 1;n++)
			p2 = p2->next_line;
		p1->next_line = p2->next_line;
		head->num -= j;
}

void delete_char(Line *head)
{
	int i,j,n;
	Line *p1 = head;
	Character *p2,*p3;
	printf("请输入删除第i行，第j个字符:");
	scanf("%d%d",&i,&j);
	if(i<0 || i> p1->num)
		printf("输入错误!");
	for(n = 0;n < i;n++)
		p1 = p1->next_line;
	if(j<0 || j>p1->num)
		printf("输入错误!");
	p2 = p1->point_char;
	if(j == 1)
	{
		p1->point_char = p2->next;
	}
	else
	{
		for(n = 1;n<j-1;n++)
			p2 = p2->next;
		p3 = p2->next;
		p2->next = p3->next;
	}
	p1->num --;
}

void save(Line *head)
{
	int i,j;
	Line *p1 = head;
	Character *p2;
	FILE *fp;
	char name[20]; 
	printf("请输入文件名:");
	scanf("%s",name);
	fp =fopen(name,"w+");
	for(i = 0;i<=head->num;i ++)
	{
		p1 = p1->next_line;
		p2 = p1->point_char;
		for(j =0;j<p1->num;j++)
		{
			fputc(p2->data,fp);
			p2 = p2->next;
		}
	}
}

int main()
{
	Line *head,*p1,*p2;
	Character *p3,*p4;
	FILE *fp;
	int choice;
	if((fp = fopen("1.txt","r+")) == NULL)
	{
		printf("无法打开文件\n");
		exit(0);
	}
	head = p1 = (Line*)malloc(sizeof(Line));
	head->point_char = NULL;
	head->num = 0;
	p2 = (Line*)malloc(sizeof(Line));
	p1->next_line = p2;
	p2->num = 0;
	p1 = p2;
	p3 = (Character*)malloc(sizeof(Character));
	p2->point_char = p3;
	while(!feof(fp))
	{
		p3->data = fgetc(fp);
		p1->num ++;
		if(p3->data != '\n')
		{
			p4 = (Character*)malloc(sizeof(Character));
			p3->next = p4;
			p3 = p4;
		}
		else
		{
			p3->next = NULL;
			head->num ++;
			p2 =  (Line*)malloc(sizeof(Line));
			p1->next_line = p2;
			p2->num = 0;
			p3 = (Character*)malloc(sizeof(Character));
			p2->point_char = p3;
			p1 = p2;
		}
	}
	p1->next_line = NULL;
	p1->num --;
	show(head);
	while(1)
	{
		printf("\n1.插入\n2.删除某一行\n3.删除某几行\n4.删除某字符\n5.保存\n6.退出\n请选择要进行的操作:");
		scanf("%d",&choice);
		if(choice == 6)
			break;
		switch(choice)
		{
		case 1:
			insert(head);
			break;
		case 2:
			delete_line(head,0);
			break;
		case 3:
			delete_line(head,1);
			break;
		case 4:
			delete_char(head);
			break;
		case 5:
			save(head);
			break;
		}
		system("cls");
		show(head);
	}
	system("pause");
	return 0;
}