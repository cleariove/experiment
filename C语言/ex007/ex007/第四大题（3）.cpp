#include<stdio.h>
#include<string.h>
void main()
{
	char a[3][50];
	char (*p1)[50],(*p2)[50],(*p3)[50];
	int i;
	char (*temp)[50];
	p1=a;
	printf("please enter:");
	for(i=0;i<3;i++)
		gets(*(p1+i));
	p1=a,p2=a+1,p3=a+2;
	if(strcmp(*p1,*p2)<0) {temp=p1;p1=p2;p2=temp;}
	if(strcmp(*p1,*p3)<0) {temp=p1;p1=p3;p3=temp;}
	if(strcmp(*p2,*p3)<0) {temp=p2;p2=p3;p3=temp;}
	printf("after change:\n%s\n%s\n%s\n",p1,p2,p3);
}