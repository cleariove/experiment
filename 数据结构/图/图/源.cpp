#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MVNum 100//最大顶点数
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
void CreatGraph(MGraph *,int n,int m);//函数申明
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
fprintf(fp,"景点(%d ,%d)有边，且它们之间的距离为%4d\n",n1,m1,G->arc[n1][m1].weight);
fclose(fp);
}
void CreatGraph(MGraph *G,int n,int m)//构件图
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
for( i=1;i<=m;i++)//输入边和权值
{
printf("\n请输入有边的2个顶点:\n");
scanf("%d%d",&n1,&m1);
while(n1<1||m1<1||n1>n||m1>n)
{
printf("输入的数字不符合要求 请重新输入:");
scanf("%d%d",&n1,&m1);
}
G->arc[n1][m1].adj=G->arc[m1][n1].adj = 1;
printf("\n请输入%d与%d之间的权值:", n1, m1);
scanf("%d",&G->arc[n1][m1].weight);
G->arc[m1][n1].weight=G->arc[n1][m1].weight;
}
save(G,n,m);
printf("邻接矩阵为:\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
printf("%d",G->arc[i][j].adj);
}
printf("\n");
}
}
void sort(edge edges[],MGraph *G,int m)//对权值进行排序
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
printf("权排序之后的为:\n");
for(i=1;i< m;i++)
{
printf("<<%d,%d>> %d\n",edges[i].begin,edges[i].end,edges[i].weight);
}
}
void Swapn(edge *edges,int i,int j)//交换权值 以及头和尾
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
void MiniSpanTree(MGraph *G,int n,int m)//生成最小生成树
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
printf("最小生成树为:\n");
for(i=1;i<=m;i++)//核心部分
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
int Find(int *parent,int f)//找尾
{
while(parent[f]>=0)
{
f=parent[f];
}
return (f);
}
void Dijkstra(MGraph *G,int v1,int n)
{
//用Dijkstra算法求有向图G的v1顶点到其他顶点v的最短路径p[v]及其权D[v]
//设G是有向图的邻接矩阵，若边<i,j>不存在，则G[i][j]=Maxint
//S[v]为真当且仅当v属于s,即已求得从v1到v的最短路径
int D2[MVNum],p2[MVNum];
int v,i,w,min;
enum boolean S[MVNum];
for(v=1;v<=n;v++)
{
//初始化S和D
S[v]=FALSE;//置空最短路径终点集
D2[v]=G->arc[v1][v].weight;//置初始的最短路径值
if(D2[v]<Maxint)
p2[v]=v1;//v1是v的前趋
else p2[v]=0;//v无前趋
}//end_for
D2[v1]=0;S[v1]=TRUE;//S集初始时只有源点，源点到源点的距离为0
//开始循环，每次求得v1到某个v顶点的最短路径，并加v到S集中
for(i=2;i<n;i++)
{//其余n-1个顶点
min=Maxint;
for(w=1;w<=n;w++)
if(!S[w]&&D2[w]<min)
{
v=w;min=D2[w];
}//w顶点离v1顶点更近
S[v]=TRUE;
for(w=1;w<=n;w++)//更新当前最短路径及距离
if(!S[w]&&(D2[v]+G->arc[v][w].weight<D2[w]))
{ //修改D2[w]和p2[w]，w属于V-S
D2[w]=D2[v]+G->arc[v][w].weight;
p2[w]=v;
}//end_if
}//end_for
printf("路径长度 路径\n");
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
for(i=1;i<=n;i++)//设置路径长度D和路径path初值
for(j=1;j<=n;j++)
{
if(G->arc[i][j].weight!=Maxint)
p[i][j]=j;//j是i的后继
else
p[i][j]=0;
D[i][j]=G->arc[i][j].weight;
}
for(k=1;k<=n;k++)
{ //做k次迭代，每次均试图将顶点k扩充到当前求得的从i到j的最短路径pij上
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
if(D[i][k]+D[k][j]<D[i][j])
{
D[i][j]=D[i][k]+D[k][j];//修改长度
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
printf("请输入顶点数和边数:");
scanf("%d%d",&G->vexnum,&G->arcnum);
n=G->vexnum;
m=G->arcnum;
CreatGraph(G,n,m);//建立图的存储结构
while(xz!=0)
{
printf("******求景点之间的最短路径******\n");
printf("================================\n");
printf("1.求一个景点到所有景点的最短路径\n");
printf("2.求任意的两个景点之间的最短路径\n");
printf("3.求从景点的入口到出口的最短路径\n");
printf("=================================\n");
printf(" 请选择: 1 或 2, 选择 0 退出 :");
scanf("%d",&xz);
if(xz==2)
{
Floyd(G,n);//调用Floyd算法
printf(" 输入起点和终点: v,w : ");
scanf("%d%d",&v,&w);
k=p[v][w];//k为起点v的后继顶点
if(k==0)
printf("景点 %d到 %d 无路径!\n",v,w);
else
{
printf("从景点%d到%d的最短路径是:%d",v,w,v);
while(k!=w)
{
printf("->%d",k);//输出后继顶点
k=p[k][w];//继续找下一个后继顶点
}
printf("->%d",w);//输出终点w
printf(" 路径长度: %d\n",D[v][w]);
}
}
else
if(xz==1)
{
printf("求单源路径,输入景点 v: ");
scanf("%d",&v);
Dijkstra(G,v,n);//调用Dijkstra算法
}
else
if(xz==3)
{
MiniSpanTree(G,n,m);
}
}
printf("结束求最短路径，再见！\n");
}
