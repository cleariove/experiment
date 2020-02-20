#include<stdio.h>
#include<string.h>
#define N 3
#define M 10
int main()
{
	char str[N][M];
	int i,j,a=0,b=0,c=0,d=0,e=0;
	for(i=0;i<N;i++)
	{
		printf("please enter line%d:\n",i+1); 
	    gets(str[i]);                            //请仔细想想放在内嵌循环情况 scanf("%c",&str[i]);gets(str[i]);  
		for(j=0;j<M;j++)
		{
			if(str[i][j]=='\0') break;
			if(str[i][j]>='0'&&str[i][j]<='9')
			a++;
		else if (str[i][j]>='A'&&str[i][j]<='Z')
			b++;
		else if(str[i][j]>='a'&&str[i][j]<='z')
			c++;
		else if(str[i][j]==' ')
			d++;
		else 
			e++;
		}
	}
	printf("数字个数为:%d\n大写字母个数为：%d\n小写字母个数为：%d\n空格个数为：%d\n其它字符个数为：%d\n",a,b,c,d,e);
	return 0;
}