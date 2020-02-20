#include<stdio.h>
int main()
{
	int c1,c2;
	c1=getchar();
	c2=getchar();
	printf("用putchar语句输出的结果：");
	putchar(c1);
	putchar('\ ');
	putchar(c2);
	putchar('\n');
	printf("用printf语句输出的结果：");
	printf("%c %c\n",c1,c2);
	printf("只能用printf语句输出其ASCⅡ码\n");
	printf("%d %d\n",c1,c2);
	return 0;
}