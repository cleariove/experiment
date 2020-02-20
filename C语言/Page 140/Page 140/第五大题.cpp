#include<stdio.h>
#include<math.h>
int main()
{
	int a,n,i,sum,t,m;
	sum=0;
	m=0;
	printf("请分别输入数字与位数：\n");
	scanf("%d%d",&a,&n);
	for(i=0;i<=n-1;i++)
	{
		t=a*pow(10,1.0*i);
		m=m+t;
		sum=sum+m;
	}
    printf("sum=%d\n",sum);
	return 0;
}