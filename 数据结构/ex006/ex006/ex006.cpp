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
	VexBox adjmulist[21];//最多20个点
	int vexnum,edgenum;
}AMLGraph;

void CreatGraph(AMLGraph &a)
{
	int i,p,q;
	printf("请输入景点数量:\n");
	scanf("%d",&a.vexnum);
	printf("请输入路的数量:\n");
	scanf("%d",&a.edgenum);
	for(i = 1;i <= a.vexnum;i++)
	{
		printf("请输入%d个景点名称:",i);
		scanf("%s",a.adjmulist[i].name);
		a.adjmulist[i].mark = 0;
	}
	for(i = 1;i <= a.edgenum;i++)
	{
		printf("请分别输入第%d条路的连接的两个景点的编号:",i);
		scanf("%d%d",&p,&q);
		EBox *pt = (EBox*)malloc(sizeof(EBox));
		printf("请输入该路的长度:");
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
	int j;//用于返回
	int m,n;//记录这条路的两定点
	m = p->ivex;
	n = p->jvex;
	if(a.adjmulist[m].mark == 0 && a.adjmulist[n].mark != 0)//j被访问过，i未被访问
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
	printf("请输入你现在所处的景点编号:");
	scanf("%d",&i);
	printf("游览路线为:\n");
}

int main()
{
	AMLGraph park;
	CreatGraph(park);
}