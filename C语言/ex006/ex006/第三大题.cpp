#include<stdio.h>
void main()
{
	int mulNum(int a,int b);
	int x,y;
	printf("please input two numbers:");
	scanf("%d%d",&x,&y);
	if(mulNum(x,y))
		printf("%d is multiple of %d\n",x,y);
	else printf("%d is not multiple of %d\n",x,y);
}
int mulNum(int a,int b)
{
	if(a%b==0)
		return 1;
	else return 0;
}