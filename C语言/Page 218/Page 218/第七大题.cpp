#include<stdio.h>
int main()
{
	void cpy(char str1[],char str2[]);
	char a[100],b[100];
	printf("please input:");
	gets(a);
	cpy(a,b);
	printf("The vowel letters are:%s\n",b);
	return 0;
}
void cpy(char str1[],char str2[])
{
	int i,j;
	for(i=0,j=0;str1[i]!='\0';i++)
		if(str1[i]=='a'||str1[i]=='A'||str1[i]=='e'||str1[i]=='E'||str1[i]=='i'||str1[i]=='I'||str1[i]=='o'||str1[i]=='O'||str1[i]=='u'||str1[i]=='U')
		{
			str2[j]=str1[i];
			j++;
		}
	str2[j]='\0';
}