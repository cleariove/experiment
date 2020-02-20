#include<stdio.h>
#include<string.h>
#include<math.h>
void main()
{
	int change(char str[]);
	char a[20];
	int n;
	printf("input:");
	gets(a);
	n=change(a);
	printf("Decimalism is %d\n",n);
}
int change(char str[])
{
	int i,sum,j;
	sum=0;
	str=strupr(str);
	for(j=0,i=(strlen(str)-1);i>=0;i--,j++)
	{
		if(str[j]>='A'&&str[j]<='F')
			sum=sum+(str[j]-55)*pow(16.0,i);
		else
			sum=sum+(str[j]-48)*pow(16.0,i);
	}
	return (sum);
}