#include<stdio.h>
int main()
{
	char i,m,n;
	for(i='X';i<='Z';i++)
	{
		for(m='X';m<='Z';m++)
		{
			for(n='X';n<='Z';n++)
			{
				if(i!='X'&&n!='X'&&n!='Z'&&i!=m&&i!=n&&m!=n)
					printf("A��%c������B��%c������C��%c����\n",i,m,n);
			}
		}
	}
	return 0;
}