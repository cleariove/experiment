#include<stdio.h>
#include<math.h>
int main()
{
	int a[101],i,j,n;
	n=0;
	for(i=1;i<=100;i++)
		a[i]=i;
		a[1]=0;
	for(i=2;i<=sqrt(100.0);i++)
		if(a[i]!=0)
		{
			for(j=i+1;j<=100;j++)
			{
				if(a[j]!=0)
				if(a[j]%a[i]==0)
				a[j]=0;
			}
		}
	for(i=1;i<=100;i++)
		if(a[i]!=0)
			{
				printf("%-5d",a[i]);
				n=n+1;
			    if(n%5==0)
					printf("\n");
		     }
	return 0;
}