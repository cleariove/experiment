#include<stdio.h>
struct student
{
	long num;
	char name[10];
	float score[3];
}stu[10];
int main()
{
	void input();
	student* max(float [],int);
	float average(student*);
	int i;
	float aver[10];
	student *p=stu; 
	input();
	for(i=0;i<10;i++)
		aver[i]=average(p++);
	p=stu;
	p=max(aver,10);
	printf("Num     Name       Score                average\n");
	for(i=0;i<10;i++)
		printf("%-5ld   %-10s %-7.2f%-7.2f%-7.2f%-7.2f\n",stu[i].num,stu[i].name,
		stu[i].score[0],stu[i].score[1],stu[i].score[2],aver[i]);
	printf("The highest grades is\n");
	printf("%-5ld   %-10s %-7.2f%-7.2f%-7.2f%-7.2f\n",p->num,p->name,
		p->score[0],p->score[1],p->score[2],aver[(p-stu)]);
}
void input()
{
	int i;
	printf("please enter data:\n");
	for(i=0;i<10;i++)
		scanf("%ld%s%f%f%f",&stu[i].num,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
}
student* max(float aver[],int n)
{
	int i;
	int k=0;
	student *p=stu;
	for(i=1;i<n;i++)
		if(aver[k]<aver[i])
			k=i;
	return (p+k);
}
float average(student*p)
{
	int i;
	float a=0;
    for(i=0;i<3;i++)
		a=a+p->score[i];
	return (a/3);
}