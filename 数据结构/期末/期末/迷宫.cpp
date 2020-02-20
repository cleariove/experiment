#include<stdio.h>
#include<stdlib.h>
#include<math.h>

char map[10][10];
int a2,b2;

int judge(int a,int b)
{
	if(map[a][b] == 'X' || map[a][b] == 'x')
		return 0;
	else
		return 1;
}

int DFS(int a,int b,int t)
{
	int s;
	if((map[a][b] == 'd'|| map[a][b] == 'D') && t == 0)
		return 1;
	else
	{
		s = abs(a2 + b2 - a - b);
		if(s > t ||(s % 2 != t % 2))
			return 0;
		else
		{
			if(judge(a,b + 1))
				DFS(a,b + 1,t - 1);
			else if(judge(a + 1,b))
				DFS(a + 1,b,t - 1);
			else
				return 0;
		}
	}
}

int main()
{
	int m,n,t;
	int i,j;
	int a1,b1;
	while(scanf("%d%d%d",&n,&m,&t) && (m != 0 || n != 0 || t != 0))
	{

		for(i = 0;i <= n+1;i++)
		{
			if(i == 0 || i == n+1)
				for(j = 0;j<=m+1;j++)
					map[i][j] = 'x';
			else
				for(j = 0;j <= m+1;j++)
				{
					if(j == 0 || j == m+1)
						map[i][j] = 'x';
					else
						scanf("%c",&map[i][j]);
					if(map[i][j] == 'S' || map[i][j] == 's')
					{
						a1 = i;
						b1 = j;
					}
					if(map[i][j] == 'x' || map[i][j] == 'X')
					{
						a2 = i;
						b2 = j;
					}
				}
			getchar();
		}
		if(DFS(a1,b1,t))
			printf("YES\n");
		else
			printf("NO\n");
		system("pause");
	}
}