#include<stdio.h>
#include<math.h>
int main()
{
	double a;
	int b;
	scanf("%lf",&a);
	if(a>1000||a<0)
		printf("data error\n");
	else 
	{
			b=sqrt(a);
			printf("b=%d\n",b);
	}
	return 0;
}