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
	int n;							//参与人数
	int m;							//子弹位置
	int i = 0;						//记录出局的人位置
	Player *out;
	srand(time(0));
 	printf("请输入参与人数:");
	scanf("%d",&n);
	out = add_player(n);			//获得第一个人的位置
	while(n>1)
	{
		m = rand()%6+1;
		printf("子弹在第%d枪出膛\n",m);
		i = m%n-1;
		if(i==0)
			i = n ;
		out = out_player(out,i);
		n--;
		printf("剩余生存：%d人，good luck\n\n",n);
	}
	printf("恭喜%d号，幸运女神眷顾着你\n",out->num);
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
	Player *before_out;		//出局人的前驱
	while(n>1)			//找到出局的人的前驱
	{
		start = start->next;
		n--;
	}
	before_out = start;
	start = start->next;
	before_out->next = start->next;
	printf("很遗憾，%d号出局了\n",start->num);
	return (before_out->next);
}