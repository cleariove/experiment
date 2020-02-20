#include<stdio.h>
#define N 10
void main()
{
	int a[N],i,max,min;
	int m,n;
	printf("please enter %d data:",N);
	for(i=0;i<N;i++)
	    scanf("%d",&a[i]);
	for(i=0;i<N;i++)
		printf("%d ",a[i]);
	printf("\n");
	max=min=a[0];
	for(i=0;i<N;i++)
	{
		if(max<=a[i])
		{
			max=a[i];
			m=i+1;
			
		}
		if(min>=a[i])
		{
			min=a[i];
			n=i+1;
		}
	}
	printf("max=%d,its position is %d\n",max,m);
	printf("min=%d,its position is %d\n",min,n);
}