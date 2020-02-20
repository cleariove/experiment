#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LEN sizeof(struct player)
typedef struct player
{
	int num;
	struct player *next;
}Player;

Player* add_player(int n);
Player* out_player(Player *start,int n);

int main()
{
	int n;							//��������
	int m;							//�ӵ�λ��
	int i = 0;						//��¼���ֵ���λ��
	Player *out;
	srand(time(0));
 	printf("�������������:");
	scanf("%d",&n);
	out = add_player(n);			//��õ�һ���˵�λ��
	while(n>1)
	{
		m = rand()%6+1;
		printf("�ӵ��ڵ�%dǹ����\n",m);
		i = m%n-1;
		if(i==0)
			i = n ;
		out = out_player(out,i);
		n--;
		printf("ʣ�����棺%d�ˣ�good luck\n\n",n);
	}
	printf("��ϲ%d�ţ�����Ů��������\n",out->num);
	system("pause");
	return 0;
}

Player* add_player(int n)
{
	int i = 0;
	Player *p1,*p2,*head;
	head = p1 = p2 = (Player *)malloc(LEN);
	p2->num = 1;
	for(i = 2;i<=n;i++)
	{

		p2 = (Player *)malloc(LEN);
		p2->num = i;
		p1->next = p2;
		p1 = p2;
	}
	p2->next = head;
	return (head);
}

Player* out_player(Player *start,int n)
{
	Player *before_out;		//�����˵�ǰ��
	while(n>1)			//�ҵ����ֵ��˵�ǰ��
	{
		start = start->next;
		n--;
	}
	before_out = start;
	start = start->next;
	before_out->next = start->next;
	printf("���ź���%d�ų�����\n",start->num);
	return (before_out->next);
}