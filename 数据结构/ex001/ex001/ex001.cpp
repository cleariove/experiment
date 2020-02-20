#include<stdlib.h>
#include<stdio.h>

#define longer 100
#define N 10			//ÿ�ζ�ӵ�Ԫ��

typedef struct
{
	char *elem;
	int length;
	int listsize;
}SqList;
typedef struct LNode
{
	char data;
	struct LNode *next;
}LNode,*LinkList;

SqList InitList_Sq(SqList &L)											//��ʼ˳���
{
	L.elem = (char *)malloc(longer * sizeof(char));
	if(!L.elem)
		return L;
	L.length = 0;
	L.listsize = longer;
	return L;
}

int ListInsert_Sq(SqList &L,int i,char e)								//˳����������
{
	char *newbase;
	if((i < 1) || (i > L.length+1))
		return 0;
	if(L.length >= L.listsize)
	{
		newbase = (char *)realloc(L.elem,(L.listsize + N) * sizeof(char));
		if(!newbase)
			return 0;
		L.elem = newbase;
		L.listsize += N;
	}
	for(int j = L.length - 1;j >= i;j--)
		L.elem[j]=L.elem[j-1];
	L.elem[i-1] = e;
	L.length ++;
	return 1;
}

int ListDelete_Sq(SqList &L,int i,char &e)								//˳���ɾ������
{
	if((i < 1) || (i >L.length-1))
		return 0;
	e = L.elem[i-1];
	for(int j = i - 1;j < L.length-1;j++)
		L.elem[j] = L.elem[j+1];
	L.length --;
	return 1;
}

void ListShow_Sq(SqList &L)												//˳�����ʾ����
{
	system("cls");
	printf("���Ա�������Ϊ:");
	for(int i = 0;i < L.length;i++)
		printf("%c,",L.elem[i]);
	printf("\b \n");
}

int LinkInsert_L(LinkList &L,int i,char e)								//�������
{
	LinkList s,p = L;
	int j = 0;
	while(p&&j< i - 1)
	{
		p = p->next;
		j++;
	}
	if(!p||j> i - 1)
		return 0;
	s = (LinkList)malloc(sizeof(char));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return 1;
}

int LinkDelete_L(LinkList &L,int i,char &e)								//����ɾ��
{
	LinkList s,p = L;
	int j = 0;
	while(p->next && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if(!(p->next) || j > i - 1)
		return 0;
	s = p->next;
	p->next = s->next;
	e = s->data;
	free(s);
	return 1;
}

void LinkShow_L(LinkList L)												//�������
{
	system("cls");
	printf("����������Ϊ:");
	L = L ->next;
	while(L)
	{
		printf("%c,",L->data);
		L = L->next;
	}
	printf("\b \n");
}

int main()
{
	int n,i;
	SqList L;
	LinkList L0,L1,L2,head;
	char e;
	int choice;
	while(1)
	{
		printf("1.˳���\n2.����\n3.�˳�\n����������ѡ��:");
		scanf("%d",&choice);
		getchar();
		system("cls");
		if(choice == 1)														//˳���										
		{
			printf("�������ʼ����:\n");
			L = InitList_Sq(L);
			while(1)
			{
				scanf("%c",&L.elem[L.length]);
				if(L.elem[L.length] == '\n')
					break;
				L.length++;
			}
			system("cls");
			while(1)
			{
				printf("1.ɾ��\n2.����\n3.����\n��ѡ��Ҫ���еĲ���:");
				scanf("%d",&choice);
				if(choice == 1)
				{
					ListShow_Sq(L);
					printf("������ɾ���ڼ���Ԫ��:");
					scanf("%d",&i);
					n = ListDelete_Sq(L,i,e);
					if(n == 1)
					{
						ListShow_Sq(L);
						printf("ɾ����Ԫ��Ϊ:%c\n",e);
						system("pause");
						system("cls");
					}
				}
				else if(choice == 2)
				{
					ListShow_Sq(L);
					printf("����������λ��:");
					scanf("%d",&i);
					getchar();
					printf("����������Ԫ��:");
					scanf("%c",&e);
					n = ListInsert_Sq(L,i,e);
					if(n == 1)
						ListShow_Sq(L);
					system("pause");
					system("cls");
				}
				else if(choice == 3)
				{
					choice = 0;
					system("cls");
					break;
				}
				else
				{
					printf("�����������������룡\n");
					system("pause");
					system("cls");
				}
			}
		}
		else if(choice == 2)											//����
		{
			printf("�������ʼ����:\n");
			head = (LinkList)malloc(sizeof(LNode));
			L0 = L1 = L2 = (LinkList)malloc(sizeof(LNode));
			scanf("%c",&L1->data);
			head->next = L0;
			while(1)
			{
				L1 = (LinkList)malloc(sizeof(LNode));
				scanf("%c",&L1->data);
				if(L1->data == '\n')
				{
					L2->next = nullptr;
					break;
				}
				L2->next = L1;
				L2 = L1;
			}
			L1 = head;
			system("cls");
			while(1)
			{
				printf("1.ɾ��\n2.����\n3.����\n��ѡ��Ҫ���еĲ���:");
				scanf("%d",&choice);
				system("cls");
				if(choice == 1)
				{
					LinkShow_L(L1);
					printf("������ɾ���ڼ���Ԫ��:");
					scanf("%d",&i);
					n = LinkDelete_L(L1,i,e);
					LinkShow_L(L1);
					printf("ɾ����Ԫ��Ϊ:%c\n",e);
					system("pause");
					system("cls");
				}
				else if(choice == 2)
				{
					LinkShow_L(L1);
					printf("����������λ��:");
					scanf("%d",&i);
					getchar();
					printf("����������Ԫ��:");
					scanf("%c",&e);
					n = LinkInsert_L(L1,i,e);
					LinkShow_L(L1);
					system("pause");
					system("cls");
				}
				else if(choice == 3)
				{
					choice = 0;
					system("cls");
					break;
				}
				else
				{
					printf("�����������������룡\n");
					system("pause");
					system("cls");
				}
			}
		}
		else if(choice == 3)
			break;
		else
		{
			printf("�����������������룡\n");
			system("pause");
			system("cls");
		}
	}
	system("pause");
	return 0;
}