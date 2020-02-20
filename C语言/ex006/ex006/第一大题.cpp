#include<stdio.h>
#include<math.h>
int main()
{
	int primeNum(int num);
	int num;
	printf("please enter a integer:\n");
	scanf("%d",&num);
	num=primeNum(num);
	if(num) printf("num is prime.\n");
	else printf("num is not a prime.\n");
	return 0;
}
int primeNum(int num)
{
	int k;
	int i;
	k=sqrt(num*1.0);
	for(i=2;i<=k;i++)
		if(num%i!=0);
		else break;
	if(i==k+1)
		return (num);
	else return(0);
}