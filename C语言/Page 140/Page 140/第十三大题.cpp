#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,t,x;
	a=2;
	b=1;
	t=b;
	printf("������һ�����֣�");
	scanf("%f",&x);
	while(fabs(a-t)>1e-5)
	{
		t=b;
		a=0.5*(b+x/b);
		b=a;
	}
	printf("������1/2�η�Ϊ��%f\n",a);
	return 0;
}