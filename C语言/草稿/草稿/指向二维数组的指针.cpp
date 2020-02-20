#include<stdio.h>
int main()
{
	int *p;
	int a[3][4]={};
	printf("%d,%d,%f\n",*a,*a+1,((*a+1)-*a)/4.0);
	printf("%d,%d,%f\n",&a,&a+1,((&a+1)-&a)/4.0);
	printf("%d,%d,%f\n",*(a+1),*(a+1)+1,((*(a+1)+1)-*(a+1))/4);
	printf("%d,%d,%f\n",&a[0],&a[0]+1,((&a[0]+1)-&a[0])/4);
	printf("%d,%d,%f\n",a[0],a[0]+1,((a[0]+1)-a[0])/4);
	printf("%d,%d,%f\n",&a[0][0],&a[0][0]+1,((&a[0][0]+1)-&a[0][0])/4);
	printf("%d,%d,%f\n",a,a+1,((a+1)-a)/4);
	return 0;
}