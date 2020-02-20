#include<stdio.h>
void main()
{
	int score;
	scanf("%d",&score);
	if(score<60)  printf("Your grade is E\n");
	else if(score>=60&&score<70) printf("Your grade is D\n");
	else if(score>=70&&score<80) printf("Your grade is C\n");
	else if(score>=80&&score<90) printf("Your grade is B\n");
	else if(score>=90&&score<=100) printf("Your grade is A\n");
	else printf("ÊäÈëÊý¾Ý´íÎó\n");
}