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
	gets(a);//�������������������л����Ļ�����ôenter�����������ַ����еģ�����ֱ�ӽ����ˣ����ո�Ҳ����һ���ַ�����������
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