#include<stdio.h>
#include<string.h>
int main()
{
	char str1[20],str2[10];
    int i;
	printf("input string2:");
	gets(str2);
	for(i=0;i<=strlen(str2);i++)
	{
		str1[i]=str2[i];
	}
	//这里i不包括\0的长度
	printf("string1 is %s\n",str1);
	return 0;
}