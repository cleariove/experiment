#include<stdio.h>
#include<math.h>
#define N 15
int main()
{
	int a[N],b,i,p,q,t,T;
	char c,s;
	T=1;
	printf("enter data£º");
		for(i=0;i<N;i++)
			scanf("%d",&a[i]);
		for(i=0;i<N-1;i++)
		{
			if(a[i]<a[i+1]) ;
			else
			{
				printf("enter data again£º");
		            for(i=0;i<N;i++)
			        scanf("%d",&a[i]);
					i=0;
			}
		}
		while(T)
		{
			p=0;
		    q=N-1;
			printf("Input a number:");
			scanf("%d",&b);
		    while(fabs(1.0*p-q)>1)
		    {
				t=(p+q)/2;
			    if(b>=a[t])
					p=t;
			    else q=t;
		        if((fabs(1.0*p-q))==1)
		        {
					if(b==a[p])
						printf("Has found %d,its position is %d\n",b,p+1);
		            else 
			        {
						if(b==a[q])
							printf("Has found %d,its position is %d\n",b,q+1);

				        else 
							printf("cannot found %d\n",b);
		             }
		        }
		    }
			printf("continue or not(Y/N)?");
		    scanf(" %c",&c);
			if(c=='y'||c=='Y')
				T=1;
			else
				if(c=='n'||c=='N')
					T=0;
		}
	return 0;
}
