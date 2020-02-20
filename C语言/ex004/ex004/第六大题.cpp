#include<stdio.h>
void main()
{
	int n,a,t;
	for(n=1;n<=11;n++)
	{  
		for(t=0;t<=37-3*n;t++)
		printf(" ");
		for(a=1;a<=(2*n-1);a=a+2)
		{
			if(a<10)
			printf("%d  ",a);
			else
			printf("%d ",a);
		}
		while(a>=4)
		{
			if(a<14)
			printf("%d  ",(a-4));
			else
			printf("%d ",(a-4));
			a=a-2;
		}
		printf("\n");
	}
}