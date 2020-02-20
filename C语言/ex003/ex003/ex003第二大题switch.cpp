#include<stdio.h>
void main()
{
	int a,b;
	scanf("%d",&a);
	b=a/10;
	switch(b)
	{
	    case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:printf("Your grade is E\n");break;
		case 6:printf("Your grade is D\n");break;
		case 7:printf("Your grade is C\n");break;
		case 8:printf("Your grade is B\n");break;
		case 9:
		case 10:printf("Your grade is A\n");break;
		default:printf("enter data error!\n");break;
	}
}