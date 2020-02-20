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
	printf("数字个数为:%d\n大写字母个数为：%d\n小写字母个数为：%d\n空格个数为：%d\n其它字符个数为：%d\n",a,b,c,d,e);
}