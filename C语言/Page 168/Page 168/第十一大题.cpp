#include<stdio.h>
int main()
{
	char c[]={"* * * * *"};
	int i,j,k;
	for(i=0;i<=5;i++)
	{
		for(j=1;j<=i;j++)
			printf("  ");
		for(k=0;k<9;k++)                                    /*�����п��Ժϲ�Ϊprintf("%s",c);	
			printf("%c",c[k]);                                  */
		printf("\n");
	}
	return 0;
}