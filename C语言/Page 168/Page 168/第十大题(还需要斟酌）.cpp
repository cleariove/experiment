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
	    gets(str[i]);                            //����ϸ���������Ƕѭ����� scanf("%c",&str[i]);gets(str[i]);  
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
	printf("���ָ���Ϊ:%d\n��д��ĸ����Ϊ��%d\nСд��ĸ����Ϊ��%d\n�ո����Ϊ��%d\n�����ַ�����Ϊ��%d\n",a,b,c,d,e);
	return 0;
}