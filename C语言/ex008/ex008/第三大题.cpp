#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
	char num[9];
	char name[8];
	float score;
	char remark[20];
	struct student *next;
};
#define LEN sizeof(struct student)
int main()
{
	struct student* input();
	void refer(struct student *);
	void sort(struct student *);
	struct student*  p;
	void print(struct student*);
	p=input();
	refer(p);
	sort(p);
	print(p);
}
struct student* input()
{
	struct student *p1,*p2;
	struct student *head=NULL;
	p2=p1=(struct student*)malloc(LEN);
	printf("num  name score    remark                      以学号#结束\n");
	scanf("%s%s%f%s",p1->num,p1->name,&p1->score,p1->remark);
	if(p1->num[0]=='#') head=NULL;
	else head=p1;
	while(p1->num[0]!='#')
	{
		p2=p1;
		p1=(struct student*)malloc(LEN);
		p2->next=p1;
		scanf("%s%s%f%s",p1->num,p1->name,&p1->score,p1->remark);
	}
	p2->next=NULL;
	return(head);
}
void refer(struct student *p)
{
	float a;
	printf("please enter score:");
	scanf("%f",&a);
	while(p!=NULL)
	{
		if(p->score>=a)
			printf("%9s%8s%7.2f%20s\n",p->num,p->name,p->score,p->remark);
		p=p->next;
	}
}
void sort(struct student *p)
{
	struct student *p1,*p2,*p3;
	struct student temp;
	for(;p!=NULL;p=p->next)
	{
		p2=p;
		for(p1=p->next;p1!=NULL;p1=p1->next)
			if((p->score)<(p1->score)) p2=p1;
		if(p2!=p)
		{
			temp=*p;
			*p=*p2;
			*p2=temp;
			p3=p->next;
			p->next=p2->next;
			p2->next=p3;
		}//这样之后地址也被换了

	}
}
void print(struct student*p)
{
	printf("The sorted line:\n");
	while(p!=NULL)
	{
		printf("%9s%8s%7.2f%20s\n",p->num,p->name,p->score,p->remark);
		p=p->next;
	}
}