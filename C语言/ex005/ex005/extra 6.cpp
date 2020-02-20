#include<stdio.h>
#include<string.h>
#include<math.h>
void main()
{
	int  j;
	char a[100];
	int sum,t,k;
	float b;
	sum=0;
	printf("please ener the number:");
	gets(a);//将上面两行与下面两行互换的话，那么enter键算是下面字符串中的，所以直接结束了，而空格也算是一个字符，就有问题
	printf("please enter the scale of number:");
	scanf("%f",&b);
	t=strlen(a);
	k=t;
	for(j=0;j<t;j++)
	{
		sum=sum+(a[j]-'0')*pow(b,k-1);
		k--;
	}
	printf("Decimalism is %d",sum);
}