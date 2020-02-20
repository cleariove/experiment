#include<stdio.h>
void main()
{
	void swap(char *,char *);
	char a,b,c;
	char *p1,*p2,*p3;
	p1=&a,p2=&b,p3=&c;
	printf("please enter three characters:");
	scanf("%c%c%c",p1,p2,p3);
	if(*p1<*p2) swap(p1,p2);
	if(*p1<*p3) swap(p1,p3);
	if(*p2<*p3) swap(p2,p3);
	printf("%c%c%c\n",*p1,*p2,*p3);
}
void swap(char *p1,char *p2)
{
	char temp;
	temp=*p1;
	*p1=*p2;
	*p2=temp;
}