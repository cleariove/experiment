#include<stdio.h>
void main()
{
	int a,n;
	n=1;
	printf("Input:");
	scanf("%d",&a);
	printf("Output:");
	while(n<=a)
	{
		if(a%n==0)
        printf("%d,",n);
		n++;
	}
	printf("\n");
}