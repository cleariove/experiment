#include<stdio.h>
int main()
{
	void cpy(char str[][30]);
	char str[2][30];
	int i;
	for(i=0;i<2;i++)
	{
			printf("please enter string%d:",i+1);
			gets(str[i]);
	}
	cpy(str);
	printf("%s\n",str[0]);
	return 0;
}
void cpy(char str[][30])
{
	int i,j;
	for(i=0;i<30;i++)
		if(str[0][i]=='\0')
		{
			for(j=0;str[1][j]!='\0';j++)
			{
				str[0][i]=str[1][j];
			    i++;
			}
			break;
		}
	str[0][i]='\0';
}