#include<stdio.h>
#include<stdlib.h>

typedef struct Link
{
	struct Link *next;
	int data;
}Link,*List;

float func4(List &L)
{
	float a;
	int sum = 0;
	int i = 0;
	List L1 = L;
	for(;i <L->data;i++)
	{
		L1 = L1->next;
		sum += L1->data;
	}
	a = (float)sum/L->data;
	return a;
}

void func(List &L)
{
	List L1;
	L = (List)malloc(sizeof(Link));
	L1 = (List)malloc(sizeof(Link));
	L->next = L1;
	L->data = 1;
	L1->data = 0;
	L1->next = NULL;
}

void func1(List &L,int x,int i)
{
	int j = 0;
	List L1 = L;
	for(;j < i;j++)
	{
		L1 = L1->next;
		L1->data += x;
	}
}

void func2(List &L,int k)
{
	List L1 = L,L2;
	L2 = (List)malloc(sizeof(Link));
	L2->next = NULL;
	L2->data = k;
	while(L1->next != NULL)
	{
		L1 = L1->next;
	}
	L->data ++;
	L1->next = L2;
}

void func3(List &L)
{
	int i;
	List L1 = L;
	for(i = 0;i< L->data;i++)
	{
		L1 = L1->next;
	}
	free(L1->next);
	L1->next = NULL;
	L->data --;
}

int main()
{
	List L;
	int choice,i,x,n=1,k;
	func(L);
	scanf("%d",&n);
	for(;n>0;n--)
	{
		scanf("%d",&choice);
		if(choice == 2)
		{
			scanf("%d",&k);
			func2(L,k);
		}
		else if(choice == 3)
			func3(L);
		else if(L->data >=2)
		{
			scanf("%d %d",&i,&x);
			func1(L,x,i);
		}
		printf("%f\n",func4(L));
	}
	system("pause");
	return 0;
}