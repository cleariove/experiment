#include<stdio.h>
#include<math.h>
void main()
{
	int a,n,t,k,sum;
	sum=0;
	printf("�Ӵ�С���У�");
	for(a=999,t=1;a>2&&t<=10;a=a-2)
	{
			k=sqrt(a*1.0);
			for(n=2;n<=k;n++)
			{
				if(a%n==0)break;
			}
			if(n>=k)
			{	
				sum=sum+a;
	            printf("%d+",a);
				t++;
			}
	}
	if(t>=10)
    printf("\b=%d\n",sum);
	else
	printf("�÷�Χ����������С��10\n");
}