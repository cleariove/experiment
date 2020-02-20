#include<stdio.h>
#define N 5
int main()
{
	int a[N],i,t;
	printf("please enter %d numbers:",N);
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);
	for(i=0;i<=N/2;i++)
	{
		t=a[i];
		a[i]=a[N-1-i];
		a[N-1-i]=t;
	}
	for(i=0;i<N;i++)
	printf("%-5d",a[i]);
	printf("\n");
	return 0;
}