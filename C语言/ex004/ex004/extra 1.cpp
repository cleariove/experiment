#include<stdio.h>
void main()
{
	int n;
	for(n=10;n<=10000;n++)
	{
		if(n>=10&&n<100)
		{
			if((n/10)<(n%10))
				printf("%5d",n);
		}
		else
			{
				if(n>=100&&n<1000)
				{
					if((n/100)<(n/10-(n/100)*10)&&(n/10-(n/100)*10)<(n%10))
						printf("%5d",n);
				}
				else
					if((n/1000)<(n/100-(n/1000)*10)&&(n/100-(n/1000)*10)<(n/10-(n/100)*10)&&(n/10-(n/100)*10)<(n%10))
						printf("%5d",n);
		    }
	}
}