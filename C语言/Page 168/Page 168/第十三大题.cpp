#include<stdio.h>
int main()
{
	char str1[80]={},str2[80];
	int i,j;
	printf("input string1:");
	gets(str1);
	printf("input string2:");
	gets(str2);
	j=0;
	for(i=0;i<80;i++)
		if(str1[i]=='\0')
		{
				str1[i]=str2[j];
				j++;
		}
	printf("The new string is:%s\n",str1);
	return 0;
}