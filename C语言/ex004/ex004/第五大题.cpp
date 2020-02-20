#include<stdio.h>
#include<math.h>
void main()
{
	int a,n,t,sum,k;
	sum=0;
	t=0;
	printf("从大到小排列：");
		for(a=999;a>=2&&t!=10;a=a-2)
		{
			k=sqrt(a*1.0);
		  {for(n=2;n<=k;n++)
			{if(a%n==0) break;
			     if(n>=k)
				 {
					 printf("%d+",a);
					 sum=sum+a;
					 t++;
				 }
			}
		  }
		}
		if(t<10) printf("素数不足十个\n");
	else printf("\b=%d\n",sum);
}