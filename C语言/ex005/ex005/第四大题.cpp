#include<stdio.h>
#define N 10
void main()
{
	void sort(int array[]);
	void choose(int number[]);
	int a[N];
	int i;
	printf("please enter %d numbers:",N);
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);
	sort(a);
	printf("\n");
	choose(a);
	printf("\n");
}


void sort(int array[])
{
	int k,i,t;
	printf("The sorted array is:");
	for(i=0;i<N;i++)
	{
		for(k=i+1;k<N;k++)
		{
			if(array[i]>array[k])
			{
				t=array[i];
				array[i]=array[k];
				array[k]=t;
			}
		}
		printf("%5d",array[i]);
	}
}

void choose(int number[])
{
	int num,mid,p,q;
	int i;
	int t;//ÅĞ¶ÏÕæ¼Ù
	printf("Please enter a number to find:");
	scanf("%d",&num);
	t=1;
	p=0;
	q=N-1;
	while(t)
	{
		mid=(p+q)/2;
		if(num==number[mid])
		{
			printf("Has found %d,its position is %d",num,mid+1);
			t=0;
		}
		else if(num>number[mid])
			p=mid;
		else q=mid;
		if(q-p<=1) 
		{
				printf("cannot find %d",num);
				break;
		}
	}
}