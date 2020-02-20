#include<stdio.h>
#include<math.h>
void main()
{
	int i,j,k,a[1001];
	for(i=1;i<1001;i++)
		a[i]=i;
	a[1]=0;
	for(i=2;i<sqrt(1000.0);i++)
		if(a[i]!=0)
			for(j=i+1;j<=1000;j++)
				if(a[j]!=0&&a[j]%a[i]==0)
					a[j]=0;
	for(i=1;i<1001;i++)
		if(a[i]!=0)
			printf("%5d",a[i]);
}