#include<stdio.h>
#define N 15
void main()
{
	int a[N];
	int i,j,t;
	printf("please enter %d integers:",N);
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);
	for(i=0;i<N;i++)
	{
		for(j=i+1;j<N;j++)
		{
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
		printf("%5d",a[i]);
	}
	printf("\n");
}