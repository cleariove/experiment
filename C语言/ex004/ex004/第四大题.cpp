#include<stdio.h>
void main()
{
	char x;
	int a,b,c,d,e;
	a=b=c=d=e=0;
	printf("Input:\n");
    while((x=getchar())!='\n')
	{
		if(x>='0'&&x<='9')
			a++;
		else if (x>='A'&&x<='Z')
			b++;
		else if(x>='a'&&x<='z')
			c++;
		else if(x==' ')
			d++;
		else 
			e++;
	}
	printf("���ָ���Ϊ:%d\n��д��ĸ����Ϊ��%d\nСд��ĸ����Ϊ��%d\n�ո����Ϊ��%d\n�����ַ�����Ϊ��%d\n",a,b,c,d,e);
}