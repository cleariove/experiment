#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct	BiTree
{
	BiTree *lchild,*rchild;
	float data;
}BiTree;

int Depth(BiTree *T)
{
	int left,right;
	if(T == NULL)
		return 0;
	else
	{		
		left = Depth(T->lchild);
		right = Depth(T->rchild);
		return left>right?left+1:right+1;
	}
}

void Leaf_num(BiTree *T,int &i)
{
	if((T->lchild == NULL) && (T->rchild == NULL))
		 i++;
	else 
	{
		if(T->lchild != NULL)
			Leaf_num(T->lchild,i);
		if(T->rchild != NULL)
			Leaf_num(T->rchild,i);
	}
}

BiTree* CreatTree(char* str,int start,int end)
{
	int last_add = 0;//�ҵ�δ�����Ű�ס�����һ���Ӽ���������������±ꣻ
	int last_mul = 0;
	int last_optr = 0;
	int flag = 0;//ÿ����һ�������ţ�flag��һ������һ�������ţ�flag��һ
	int i;
	BiTree *T;
	T = (BiTree *)malloc(sizeof(BiTree));
	if(end - start == 1)
	{
		printf("������%c��Ӧ����ֵ:",str[start]);
		scanf("%f",&T->data);
		T->lchild = NULL;
		T->rchild = NULL;
		return T;
	}
	else
	{
		for(i = start;i < end;i++)
		{
			if(str[i] == '(')
				flag++;
			else if(str[i] == ')')
				flag--;
			if(flag == 0)//�ҵ������������еļӼ���˳�
			{
				if(str[i] == '*' || str[i] == '/')
					last_mul = i;
				else if(str[i] == '+' || str[i] == '-')
					last_add = i;
			}
		}
		if(last_add == 0 && last_mul == 0)//���������û�мӼ��˳���˵������ʽ�ӱ����Ű�Χ����ȥ������һͷһβ
		{
			T = CreatTree(str,start + 1,end - 1);
			return T;
		}
		else if(last_add == 0)
			last_optr = last_mul;
		else
			last_optr = last_add;
		T->data = str[last_optr];
		T->lchild = CreatTree(str,start,last_optr);
		T->rchild = CreatTree(str,last_optr + 1,end);
		return T;
	}
}

float Add(BiTree *T)
{
	if(T->data == '+')
		return Add(T->lchild) + Add(T->rchild);
	else if(T->data == '-')
		return Add(T->lchild) - Add(T->rchild);
	else if(T->data == '*')
		return Add(T->lchild) * Add(T->rchild);
	else if(T->data == '/')
		return Add(T->lchild) / Add(T->rchild);
	else
		return T->data;
}

int main()
{
	BiTree *T;
	int deep,num;
	char str[100];
	float sum;
	printf("��������ʽ�����ֲ������ò�ͬ��ĸ����\n");
	scanf("%s",str);
	T = CreatTree(str,0,strlen(str));
	deep = Depth(T);
	num = 0;
	Leaf_num(T,num);
	sum = Add(T);
	printf("���Ϊ��%d\nҶ�ӽڵ������%d\n������Ϊ:%f\n",deep,num,sum);
	system("pause");
	return 0;
}