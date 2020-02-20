#include<stdio.h>
#include<math.h>
void main()
{
	float x,y,z;
	scanf("%f%f",&x,&y);
	if(x<0&&y<0) 
		z=(float)exp(x+y);
	else if(x+y>=1&&x+y<10)
		z=(float)log(x+y);
	else z=(float)log10(abs(x+y)+1);
	printf("z=%f\n",z);
}