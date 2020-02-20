#include<stdio.h>
#include<math.h>
void main()
{
    int prime_num(int x);
	int a,b[10];//ÊäÈë¸ÃÊı
	int i,n,m;
	i=0;
	printf("please enter a intger:");
	scanf("%d",&a);
	m=prime_num(a);
	if(m)
		printf("%d is a prime number",a);
	else
		printf("%d is not a prime number",a);
	for(n=2;n<=2000;n++)
	{
		m=prime_num(n);
		if(!m)
		{
			b[i]=n;
			i++;
		}
		else 
		{
			i=0;
			continue;
		}
		if(i==10)
		{
			for(i=0;i<10;i++)
				printf("%5d",b[i]);
			printf("\n");
			i=0;
		}
	}
}
int prime_num(int x)
{
	int k,n;
	k=sqrt(x*1.0);
	if(x==2)
		return 1;
	else
	{
		for(n=2;n<=k+1;n++)
			if(x%n!=0);
		    else break;
			if(n==k+2)
				return 1;
			else 
				return 0;
	}
}