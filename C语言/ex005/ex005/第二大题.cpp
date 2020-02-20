#include<stdio.h>
int main()
{
	char str[21]={"This is a C program."};
	char c;
	int i;
	printf("%s\n",str);
	printf("input a character to find:");
	scanf("%c",&c);
	for(i=0;i<20;i++)
	{
		if(c==str[i])
		{
			printf("Has found %c,its position is %d\n",c,i+1);
			break;
		}
	}
	if(i==20)
		printf("cannot find %c\n",c);
	return 0;
}