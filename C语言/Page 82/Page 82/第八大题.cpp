#include<stdio.h>
int main()
{
	int c1,c2;
	c1=getchar();
	c2=getchar();
	printf("��putchar�������Ľ����");
	putchar(c1);
	putchar('\ ');
	putchar(c2);
	putchar('\n');
	printf("��printf�������Ľ����");
	printf("%c %c\n",c1,c2);
	printf("ֻ����printf��������ASC����\n");
	printf("%d %d\n",c1,c2);
	return 0;
}