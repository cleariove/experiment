#include<stdio.h>
#define N 4
#define M 5
int main()
{
	int a[N][M],i,j,min,t;
	printf("Input:");
	for(i=0;i<N;i++)
		for(j=0;j<M;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<N;i++)
		{
			for(j=0;j<M-1;j++)
			min=((a[i][j]>a[i][j+1])?a[i][j]:a[i][j+1]);
			for(t=0;t<N;t++)
			{
				if(min<=a[t][j]) ;
				else break;
			}
			if(t==N)
				{
					printf("a[%d][%d]=%d",i+1,j+1,a[i][j]);
					break;
			    }
			else
			{
				if(i==N-1)
					printf("ÎÞ°°µã\n");
			}
	     }
	return 0;
}