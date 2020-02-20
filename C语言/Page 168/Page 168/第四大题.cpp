#include<stdio.h>
int main()
{
	int a[11]={3,6,9,10,11,20,34,45,49,120};
	int b,i,n;
	for(i=0;i<=9;i++)
		printf("%-5d",a[i]);
	printf("\n请输入一个整数:");
	scanf("%d",&b);
	for(i=9;i>=0;i--)
			if(b>=a[i])
			{
				n=i;
				for(i=9;i>n;i--)
				{
					a[i+1]=a[i];
				}
				a[n+1]=b;
				break;
			}
	for(i=0;i<=10;i++)
		printf("%-5d",a[i]);	
	return 0;
}