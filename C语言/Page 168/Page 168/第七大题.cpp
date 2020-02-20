#include<stdio.h>
int main()
{
	int a[25][25]={0},i,j,n,m;
	printf("Please enter n:");
	scanf("%d",&n);
	j=((n+1)/2)-1;
	a[0][j]=1;
	i=0;
	for(m=2;m<=n*n;m++)
	{
    	if(i==0&&j==n-1)
			{
				i++;
			}
		else
			{
				i--;
		        j++;
				if(i>=0&&j<n&&a[i][j]!=0)
				{
					i=i+2;
					j=j-1;
				}
				else
					{
						if(i<0)
							i=n-1;
		                if(j>(n-1))
			                j=0;
				    }
		     }
		a[i][j]=m;
	}
	for(i=0;i<n;i++)
	{
			for(j=0;j<n;j++)
		    {
				printf("%-5d",a[i][j]);
		     }
			printf("\n");
	}
	return 0;
}