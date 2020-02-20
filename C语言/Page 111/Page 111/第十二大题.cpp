#include<stdio.h>
#include<math.h>
int main()
{
	float x,y;
	int h;
	scanf("%f,%f",&x,&y);
	if(pow(x-2,2)+pow(y-2,2)<=1||pow(x+2,2)+pow(y-2,2)<=1||pow(x-2,2)+pow(y+2,2)<=1||pow(x+2,2)+pow(y+2,2)<=1)
		h=10;
	else h=0;
	printf("h=%d\n",h);
	return 0;
}