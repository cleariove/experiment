#include<stdio.h>
void main()
{
	void swap(int *p1,int *p2);
	int a[3];
	int *p1,*p2,*p3;
	printf("please enter three integers:");
	for(p1=a;p1<a+3;p1++)
		scanf("%d",p1);
	p1=a;p2=a+1;p3=a+2;
	if(*p1<*p2) swap(p1,p2);
	if(*p1<*p3) swap(p1,p3);
	if(*p2<*p3) swap(p2,p3);
	printf("%2d%2d%2d\n",*p1,*p2,*p3);
}
void swap(int *p1,int *p2)
{
	int p3;
	p3=*p1;
	*p1=*p2;
	*p2=p3;//�����Ըı��ַ��Ҳ����ȥ��*�ţ�����Ϊ�βθı䲻�ᵼ��ʵ�θı�
}
