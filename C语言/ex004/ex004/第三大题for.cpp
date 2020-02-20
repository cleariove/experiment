#include<stdio.h>
void main()
{
	int a,n;
	printf("Input:");
	scanf("%d",&n);
	if(n>0&&n<1000)
	{
		printf("Output:");
		for(a=1;a<=n;a++)
		{
			if(n%a==0)
				printf("%d,",a);
		}
		printf("\n");
	}
	else printf("data error\n");
}