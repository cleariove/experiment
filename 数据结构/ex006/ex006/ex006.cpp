#include<stdio.h>
#include<stdlib.h>

typedef struct EBox
{
	int mark;
	int ivex,jvex;
	struct EBox *ilink,*jlink;
	int info;
}EBox;

typedef struct VexBox
{
	char name[100];
	int mark;
	EBox *firstedge;
}VexBox;

typedef struct
{
	VexBox adjmulist[21];//���20����
	int vexnum,edgenum;
}AMLGraph;

void CreatGraph(AMLGraph &a)
{
	int i,p,q;
	printf("�����뾰������:\n");
	scanf("%d",&a.vexnum);
	printf("������·������:\n");
	scanf("%d",&a.edgenum);
	for(i = 1;i <= a.vexnum;i++)
	{
		printf("������%d����������:",i);
		scanf("%s",a.adjmulist[i].name);
		a.adjmulist[i].mark = 0;
	}
	for(i = 1;i <= a.edgenum;i++)
	{
		printf("��ֱ������%d��·�����ӵ���������ı��:",i);
		scanf("%d%d",&p,&q);
		EBox *pt = (EBox*)malloc(sizeof(EBox));
		printf("�������·�ĳ���:");
		scanf("%d",&pt->info);
		pt->mark = 0;
		pt->ivex = p;
		pt->jvex = q;
		pt->ilink = a.adjmulist[p].firstedge;
		pt->jlink = a.adjmulist[q].firstedge;
		a.adjmulist[p].firstedge = pt;
		a.adjmulist[q].firstedge = pt;
	}
}

int NextVex(AMLGraph a,int i,EBox* &p)
{
	int j;//���ڷ���
	int m,n;//��¼����·��������
	m = p->ivex;
	n = p->jvex;
	if(a.adjmulist[m].mark == 0 && a.adjmulist[n].mark != 0)//j�����ʹ���iδ������
	{
		j = p->ivex;
		p = p->ilink;
	}
	else if(a.adjmulist[n].mark == 0 && a.adjmulist[m].mark != 0)
	{
		j = p->jvex;
		p = p->jlink;
	}
	else 
}

void DFS(AMLGraph a,int i)
{
	EBox *p = a.adjmulist[i].firstedge;
	printf("%s",a.adjmulist[i].name);
	a.adjmulist[i].mark = 1;
	i = NextVex(a,i,p);
	DFS(a,i);
}

void DFSTraverse(AMLGraph a)
{
	int i;
	printf("�����������������ľ�����:");
	scanf("%d",&i);
	printf("����·��Ϊ:\n");
}

int main()
{
	AMLGraph park;
	CreatGraph(park);
}