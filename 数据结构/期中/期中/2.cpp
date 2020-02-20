#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
	char *top,*base;
}stack;

void func1(stack &a)
{
	a.top = a.base = (char *)malloc(100 *sizeof(char));
	a.top ++;
}

void push(stack &a,char e)
{
	*a.top++ = e;
}
void pop(stack &a,char &e)
{
	e = -- *a.top;
}

int main()
{
	int n,i;
	char e;
	char s[100];
	stack a;
	func1(a);
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		e = getchar();
		push(a,e);
	}
	getchar();
	for(i = 0;i < n;i ++)
	{
		scanf("%c",&s[i]);
	}
	for(i = n - 1;i >= 0;i--)
	{
		pop(a,e);
		if(e != s[i])
			break;
		else
			printf("ok");
	}
	system("pause");
}