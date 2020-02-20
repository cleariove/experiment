#include<stdio.h>
#define Pi 3.1415926
int main()
{
	float r,h,C,S1,S2,V1,V2;
	printf("请输入半径和高：");
	scanf("%f%f",&r,&h);
	C=2*Pi*r;
	S1=Pi*r*r;
	S2=4*Pi*r*r;
	V1=(4.0/3)*Pi*r*r*r;
	V2=S1*h;
	printf("圆周长为%0.2f\n圆面积为%0.2f\n圆球表面积为%0.2f\n圆球体积为%0.2f\n圆柱体积为%0.2f\n",C,S1,S2,V1,V2);
	return 0;
}