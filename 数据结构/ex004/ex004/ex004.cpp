#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 1000

typedef int ElemType;

typedef struct Triper
{
	int i,j;
	ElemType e;
}Triper;

typedef struct TSMatrix
{
	Triper data[MAXSIZE+1];
	int mu,nu,tu;
}TSMatrix;

void CreatSMatrix(TSMatrix &a)
{
	int m,n;
	int k;
	printf("请输入该矩阵的行数和列数:");
	scanf("%d%d",&a.mu,&a.nu);
	a.tu = 0;
	printf("请输入数据:\n");
	for(m = 1;m<=a.mu;m++)
	{
		for(n = 1;n<=a.nu;n++)
		{
			scanf("%d",&k);
			if(k != 0)
			{
				a.tu ++;
				a.data[a.tu].e = k;
				a.data[a.tu].i = m;
				a.data[a.tu].j = n;
			}
		}
	}
}

void TransposeSMatrix(TSMatrix a,TSMatrix &t)
{
	int k;
	int col;
	int num[100];
	int cpot[100];
	t.mu = a.nu;
	t.nu = a.mu;
	t.tu = a.tu;
	for(col = 1;col<=a.nu;col++)
		num[col] = 0;
	for(k = 1;k<=a.tu;k++)
		num[a.data[k].j] ++;
	cpot[1] = 1;
	for(col = 2;col<=a.nu;col++)
		cpot[col] = cpot[col-1] + num[col-1];
	for(k = 1;k<=a.tu;k++)
	{
		col = a.data[k].j;
		t.data[cpot[col]].i = a.data[k].j;
		t.data[cpot[col]].j = a.data[k].i;
		t.data[cpot[col]].e = a.data[k].e;
		cpot[col] ++;
	}
}

void AddSMatrix(TSMatrix a,TSMatrix b,TSMatrix &sum)
{
	int m,n,p,q,k;
	if(a.mu == b.mu && a.nu == b.nu)
	{
		sum.mu = a.mu;
		sum.nu = a.nu;
		for(k = 1,m = 1,n = 1;m != MAXSIZE || n != MAXSIZE;k++) //当两个数组遍历完即完成加法
		{
			p = (a.data[m].i - 1) * a.nu + a.data[m].j;  //p,q分别表示在矩阵中的位置
			q = (b.data[n].i - 1) * b.nu + b.data[n].j;
			if(p < q)
			{
				sum.data[k] = a.data[m];
				m++;
			}
			else if(p == q)
			{
				sum.data[k] = a.data[m];
				sum.data[k].e += b.data[n].e;
				m++;
				n++;
			}
			else
			{
				sum.data[k] = b.data[n];
				n++;
			}
			if(m > a.tu)
				m = MAXSIZE;
			if(n > b.tu)
				n = MAXSIZE;
		}
		sum.tu = k-1;
		
	}
	else
		printf("两矩阵无法相加");
}

void MultSMatrix(TSMatrix a,TSMatrix b,TSMatrix &mul)
{
	int k;
	int m,n;
	int p,q;
	int col,row;
	int num[100] = {0};
	int rpos[100];
	int temp[11][11]={0}; //暂存和
	mul.mu = a.mu;
	mul.nu = b.nu;
	mul.tu = 0;
	if(a.nu == b.mu)
	{
		for(k = 1;k<=b.tu;k++)
			num[b.data[k].i] ++;
		rpos[1] = 1;
		for(k = 2;k<=b.mu;k++)
			rpos[k] = rpos[k-1] + num[k-1];
		rpos[k] = b.tu +1;
		for(k = 1;k<=a.tu;k++) //遍历A中每一个非零元
		{
			p = a.data[k].i;
			row = a.data[k].j;
			m = rpos[row];
			n = rpos[row+1];
			for(;m < n;m++)
			{
				q = b.data[m].j;
				col = b.data[m].i;
				temp[p][q] += a.data[k].e * b.data[m].e; 
			}
		}
		for(row = 1;row <= a.mu;row++)
		{
			for(col = 1;col <= b.nu;col++)
			{
				if(temp[row][col])
				{
					mul.tu++;
					mul.data[mul.tu].e = temp[row][col];
					mul.data[mul.tu].i = row;
					mul.data[mul.tu].j = col;
				}
			}
		}
	}
	else
		printf("两矩阵无法相乘\n");
}

void ShowSMatrix(TSMatrix &a)
{
	int m = 1,k;
	for(k = 1;k<=a.mu * a.nu;k++)
	{
		if(k !=( (a.data[m].i - 1) * a.nu + a.data[m].j))
			printf("0	");
		else
		{
			printf("%d	",a.data[m].e);
			m++;
		}
		if(k%a.mu == 0)
			printf("\n");
	}
}

int main()
{
	TSMatrix a,b,t,sum,mul;
	int choice;
	CreatSMatrix(a);
	while(1)
	{
		system("cls");
		printf("1.转置\n2.与另一个矩阵相加\n3.与另一个矩阵相乘\n4.退出\n请输入选择:");
		scanf("%d",&choice);
		if(choice == 1)
		{
			printf("原矩阵为:\n");
			ShowSMatrix(a);
			TransposeSMatrix(a,t);
			printf("转置矩阵为:\n");
			ShowSMatrix(t);
		}
		else if(choice == 2)
		{
			printf("请输入另一矩阵信息\n");
			CreatSMatrix(b);
			printf("两矩阵分别为:\n");
			ShowSMatrix(a);
			printf("\n");
			ShowSMatrix(b);
			printf("矩阵和为:\n");
			AddSMatrix(a,b,sum);
			ShowSMatrix(sum);
		}
		else if(choice == 3)
		{
			printf("请输入另一矩阵信息\n");
			CreatSMatrix(b);
			printf("两矩阵分别为:\n");
			ShowSMatrix(a);
			printf("\n");
			ShowSMatrix(b);
			printf("矩阵积为:\n");
			MultSMatrix(a,b,mul);
			ShowSMatrix(mul);
		}
		else if(choice == 4)
			break;
		else
			continue;
		system("pause");
	}
	return 0;
}