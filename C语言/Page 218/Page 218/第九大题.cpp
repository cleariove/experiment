#include<stdio.h>
int letter,digit,space,others;
int main()
{
	void count(char str[]);
	char a[80];
	printf("please enter a string:");
	gets(a);
	letter=digit=space=others=0;
	count(a);
	printf("letter:%d,digit:%d,space:%d,others:%d\n",letter,digit,space,others);
	return 0;
}
void count(char str[])
{
	int i;
	for(i=0;str[i]!='\0';i++)
		if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
			letter++;
		else if(str[i]>='0'&&str[i]<='9')
			digit++;
		else if(str[i]==' ')
			space++;
		else others++;
}