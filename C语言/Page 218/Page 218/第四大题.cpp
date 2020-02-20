#include<stdio.h>
int main()
{
	void change(int array[][3]);
	int i,j;
	int a[3][3];
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			a[i][j]=3*i+j+1;
	change(a);
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%5d",a[i][j]);
		printf("\n");
	}
	return 0;
}
void change(int array[][3])
{
	int i,j;
	int t;
	for(i=0;i<3 ;i++)
		for(j=i+1;j<3;j++)
		{ 
			if(i==j)  ;
			else
			{
				t=array[i][j];
				array[i][j]=array[j][i];
				array[j][i]=t;
			}
		}
}