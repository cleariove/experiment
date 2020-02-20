#include<stdio.h>
int main()
{
	float h,s;
	int k;
	h=100;
	s=-100;
	for(k=1;k<=10;k++)
	{
		s=s+2*h;
		h=h/2;
	}
	printf("s=%f,h=%f\n",s,h);
	return 0;
}