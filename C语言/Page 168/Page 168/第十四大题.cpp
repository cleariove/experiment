#include<stdio.h>
int main()
{
	char s1[10],s2[10];
	int i,differ,t;
	t=1;
	printf("input s1:");
	gets(s1);
	printf("input s2:");
	gets(s2);
	for(i=0;i<10&&t;i++)
	{
		if(s1[i]!='\0'&&s2[i]!='\0')
		{
			differ=s1[i]-s2[i];
		    if(differ!=0)
			{
					printf("result is:%d",differ);
					t=0;
			}
		}
		else break;
	}
	printf("\n");
	return 0;
}