#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,t,x;
	a=2;
	b=1;
	t=b;
	printf("请输入一个数字：");
	scanf("%f",&x);
	while(fabs(a-t)>1e-5)
	{
		t=b;
		a=0.5*(b+x/b);
		b=a;
	}
	printf("该数的1/2次方为：%f\n",a);
	return 0;
}