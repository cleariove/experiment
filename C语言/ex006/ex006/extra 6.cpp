#include<stdio.h>
#include<string.h>
void main()
{
	void change(int x,char b[]);
	int a;
	char str[20];
	printf("please enter a integer:");
	scanf("%d",&a);
	change(a,str);
	printf("%s\n",str);
}
void change(int x,char b[])
{
	void sort(char str1[]);
	int i,n;
	for(i=0;x!=0;i++)
	{
		n=x%16;
		if(n>=0&&n<=9)
			b[i]=n+48;
		else b[i]=n+55;
		x=x/16;
	}
	b[i]='\0';
	sort(b);
}
void sort(char str1[])
{
	int n,i;
	char temp;
	n=strlen(str1)-1;//长度从‘1’开始计算，而序号从‘0’开始
	for(i=0;i<=n/2;i++)
	{
		temp=str1[i];
		str1[i]=str1[n-i];
		str1[n-i]=temp;
	}
}