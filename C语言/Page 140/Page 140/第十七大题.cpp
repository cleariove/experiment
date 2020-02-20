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
					printf("A与%c比赛，B与%c比赛，C与%c比赛\n",i,m,n);
			}
		}
	}
	return 0;
}