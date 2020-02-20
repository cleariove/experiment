#include<stdio.h>
int main()
{
	int a[11][11],n,m;
	int i,j;
	int max,min;
	int x,p;
	int t;
	printf("enter n(2<n<10):");
	for(m=1;m==1;)
	{
	    scanf("%d",&n);
	    if(!(n>2&&n<10))
			printf("please enter n again:");
		else m=0;
	}           //程序初始化
	printf("please enter %d data:",n*n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	printf("original state:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}        //原始状况输出
	max=min=a[0][0];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(max<=a[i][j])
			{
				max=a[i][j];
				x=i;
			}
			if(min>=a[i][j])
			{
				min=a[i][j];
				p=i;
			}
		}
		printf("after the change:\n");
		if(x==m)
			printf("max and min is on the same line.\n");
		else
		{
			for(j=0;j<n;j++)
			{
				t=a[x][j];
				a[x][j]=a[p][j];
				a[p][j]=t;
			}
		}
		for(i=0;i<n;i++)
	    {
			for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
		}
	return 0;
}