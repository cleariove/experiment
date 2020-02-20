#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a,b;
	int i;
	unsigned long long mul;
	while(1)
	{
		scanf("%d%d",&a,&b);
		if(a == 0 && a == b)
			break;
		mul = 1;
		for(i = 1;i <= b;i++)
			mul *= a;
		mul = mul % 1000;
		printf("%d\n",mul);
	}
	return 0;
}