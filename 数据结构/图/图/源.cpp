#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MVNum 100//��󶥵���
#define MAXEDGE 10000
#define datatype int
#define Maxint 32767
#define MAX 100
enum boolean{FALSE,TRUE};
int D1[MVNum],p1[MVNum];
int D[MVNum][MVNum],p[MVNum][MVNum];
typedef struct
{
int begin;
int end;
int weight;
}edge;
typedef struct
{
int adj;
int weight;
}AdjMatrix[MAX][MAX];
typedef struct
{
AdjMatrix arc;
int vexnum, arcnum;
}MGraph;
void CreatGraph(MGraph *,int n,int m);//��������
void sort(edge* ,MGraph *,int m);
void MiniSpanTree(MGraph *,int n,int m);
int Find(int *, int );
void Swapn(edge *, int, int);
void Dijkstra(MGraph *G,int v1,int n) ;
void Floyd(MGraph *G,int n);
void save(MGraph *G,int n1,int m1)
{
FILE *fp;
fp=fopen("sheji.txt","a+");
fprintf(fp,"����(%d ,%d)�бߣ�������֮��ľ���Ϊ%4d\n",n1,m1,G->arc[n1][m1].weight);
fclose(fp);
}
void CreatGraph(MGraph *G,int n,int m)//����ͼ
{
int i,j,n1,m1;
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
G->arc[i][j].adj=G->arc[j][i].adj=0;
G->arc[i][j].weight=G->arc[j][i].weight=Maxint;
}
}
for( i=1;i<=m;i++)//����ߺ�Ȩֵ
{
printf("\n�������бߵ�2������:\n");
scanf("%d%d",&n1,&m1);
while(n1<1||m1<1||n1>n||m1>n)
{
printf("��������ֲ�����Ҫ�� ����������:");
scanf("%d%d",&n1,&m1);
}
G->arc[n1][m1].adj=G->arc[m1][n1].adj = 1;
printf("\n������%d��%d֮���Ȩֵ:", n1, m1);
scanf("%d",&G->arc[n1][m1].weight);
G->arc[m1][n1].weight=G->arc[n1][m1].weight;
}
save(G,n,m);
printf("�ڽӾ���Ϊ:\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
printf("%d",G->arc[i][j].adj);
}
printf("\n");
}
}
void sort(edge edges[],MGraph *G,int m)//��Ȩֵ��������
{
int i, j;
for(i=1;i<m;i++)
{
for(j=i+1;j<=m;j++)
{
if(edges[i].weight>edges[j].weight)
{
Swapn(edges,i,j);
}
}
}
printf("Ȩ����֮���Ϊ:\n");
for(i=1;i< m;i++)
{
printf("<<%d,%d>> %d\n",edges[i].begin,edges[i].end,edges[i].weight);
}
}
void Swapn(edge *edges,int i,int j)//����Ȩֵ �Լ�ͷ��β
{
int temp;
temp = edges[i].begin;
edges[i].begin = edges[j].begin;
edges[j].begin = temp;
temp = edges[i].end;
edges[i].end = edges[j].end;
edges[j].end = temp;
temp = edges[i].weight;
edges[i].weight = edges[j].weight;
edges[j].weight = temp;
}
void MiniSpanTree(MGraph *G,int n,int m)//������С������
{
int i,j,n1,m1;
int k=1;
int parent[MVNum];
edge edges[MVNum];
for(i=1;i<n;i++)
{
for(j=i+1;j<=n;j++)
{
if(G->arc[i][j].adj==1)
{
edges[k].begin=i;
edges[k].end=j;
edges[k].weight=G->arc[i][j].weight;
k++;
}
}
}
sort(edges,G,m);
for(i=1;i<=m;i++)
{
parent[i]=0;
}
printf("��С������Ϊ:\n");
for(i=1;i<=m;i++)//���Ĳ���
{
n1=Find(parent,edges[i].begin);
m1=Find(parent,edges[i].end);
if(n1!=m1)
{
parent[n1]=m1;
printf("<<%d,%d>>%d\n",edges[i].begin,edges[i].end,edges[i].weight);
}
}
}
int Find(int *parent,int f)//��β
{
while(parent[f]>=0)
{
f=parent[f];
}
return (f);
}
void Dijkstra(MGraph *G,int v1,int n)
{
//��Dijkstra�㷨������ͼG��v1���㵽��������v�����·��p[v]����ȨD[v]
//��G������ͼ���ڽӾ�������<i,j>�����ڣ���G[i][j]=Maxint
//S[v]Ϊ�浱�ҽ���v����s,������ô�v1��v�����·��
int D2[MVNum],p2[MVNum];
int v,i,w,min;
enum boolean S[MVNum];
for(v=1;v<=n;v++)
{
//��ʼ��S��D
S[v]=FALSE;//�ÿ����·���յ㼯
D2[v]=G->arc[v1][v].weight;//�ó�ʼ�����·��ֵ
if(D2[v]<Maxint)
p2[v]=v1;//v1��v��ǰ��
else p2[v]=0;//v��ǰ��
}//end_for
D2[v1]=0;S[v1]=TRUE;//S����ʼʱֻ��Դ�㣬Դ�㵽Դ��ľ���Ϊ0
//��ʼѭ����ÿ�����v1��ĳ��v��������·��������v��S����
for(i=2;i<n;i++)
{//����n-1������
min=Maxint;
for(w=1;w<=n;w++)
if(!S[w]&&D2[w]<min)
{
v=w;min=D2[w];
}//w������v1�������
S[v]=TRUE;
for(w=1;w<=n;w++)//���µ�ǰ���·��������
if(!S[w]&&(D2[v]+G->arc[v][w].weight<D2[w]))
{ //�޸�D2[w]��p2[w]��w����V-S
D2[w]=D2[v]+G->arc[v][w].weight;
p2[w]=v;
}//end_if
}//end_for
printf("·������ ·��\n");
for(i=1;i<=n;i++)
{
printf("%5d",D2[i]);
printf("%5d",i);
v=p2[i];
while(v!=0)
{
printf("<-%d",v);
v=p2[v];
}
printf("\n");
}
}
void Floyd(MGraph *G,int n)
{
int i,j,k;
for(i=1;i<=n;i++)//����·������D��·��path��ֵ
for(j=1;j<=n;j++)
{
if(G->arc[i][j].weight!=Maxint)
p[i][j]=j;//j��i�ĺ��
else
p[i][j]=0;
D[i][j]=G->arc[i][j].weight;
}
for(k=1;k<=n;k++)
{ //��k�ε�����ÿ�ξ���ͼ������k���䵽��ǰ��õĴ�i��j�����·��pij��
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
if(D[i][k]+D[k][j]<D[i][j])
{
D[i][j]=D[i][k]+D[k][j];//�޸ĳ���
p[i][j]=p[i][k];
//printf("dij=%d,pij=%d\n",D[i][j],p[i][j]);
}
}
}
}
void main()
{
MGraph *G;
int n,m,v,w,k;
int xz=1;
G=(MGraph *)malloc(sizeof(MGraph));
if (G == NULL)
{
printf("memory allcation failed,goodbye");
exit(1);
}
printf("�����붥�����ͱ���:");
scanf("%d%d",&G->vexnum,&G->arcnum);
n=G->vexnum;
m=G->arcnum;
CreatGraph(G,n,m);//����ͼ�Ĵ洢�ṹ
while(xz!=0)
{
printf("******�󾰵�֮������·��******\n");
printf("================================\n");
printf("1.��һ�����㵽���о�������·��\n");
printf("2.���������������֮������·��\n");
printf("3.��Ӿ������ڵ����ڵ����·��\n");
printf("=================================\n");
printf(" ��ѡ��: 1 �� 2, ѡ�� 0 �˳� :");
scanf("%d",&xz);
if(xz==2)
{
Floyd(G,n);//����Floyd�㷨
printf(" ���������յ�: v,w : ");
scanf("%d%d",&v,&w);
k=p[v][w];//kΪ���v�ĺ�̶���
if(k==0)
printf("���� %d�� %d ��·��!\n",v,w);
else
{
printf("�Ӿ���%d��%d�����·����:%d",v,w,v);
while(k!=w)
{
printf("->%d",k);//�����̶���
k=p[k][w];//��������һ����̶���
}
printf("->%d",w);//����յ�w
printf(" ·������: %d\n",D[v][w]);
}
}
else
if(xz==1)
{
printf("��Դ·��,���뾰�� v: ");
scanf("%d",&v);
Dijkstra(G,v,n);//����Dijkstra�㷨
}
else
if(xz==3)
{
MiniSpanTree(G,n,m);
}
}
printf("���������·�����ټ���\n");
}
