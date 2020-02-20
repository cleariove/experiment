#include<stdio.h>
void main()
{
	void newcopy(char *p1,char *p2);
	char a[]="I am a student in IES in NCU.";
	char b[100]={};
	char *p1=a,*p2;
	p2=b;
	printf("Original string:%s\n",p1);
	newcopy(a,b);
	printf("Old:%s\nNew:%s\n",p1,p2);
}
void newcopy(char *p1,char *p2)
{
	for(;*p1!='\0';p1++)
	{
		if(*p1>='a'&&*p1<='z')
		{
				*p2=*p1;
				*p1=' ';
				p2++;
		}
	}
	*(++p2)='\0';
}