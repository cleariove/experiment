#include<stdio.h>
#include<string.h>
int main()
{
	void inverse(char array[]);
	char str[100];
	printf("please input the character array:");
	gets(str);
	inverse(str);
	printf("%s\n",str);
}
void inverse(char array[])
{
	int i,j;
	char c;
	j=strlen(array)-1;//��Ϊ���һ����ŵ����ַ������ȼ�һ
	for(i=0;i<=j;i++,j--)
	{
		c=array[i];
		array[i]=array[j];
		array[j]=c;
	}
}