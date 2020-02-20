#include<stdio.h>
#include<math.h>
void main()
{
	int n,t;
	t=1;
	for(n=1;n<=100;n++)
	{
		t=2*t;
		if(t>=10)
			t=t-10;
	}
	printf("Ä©Î²Êý×ÖÎª£º%d\n",t);
}