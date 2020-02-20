#include<stdio.h>
void main()
{
	float aver[5],sum;
	float a[4][6];
	int i,j;
	printf("Input:\n");
	for(i=0;i<3;i++)
		for(j=0;j<5;j++)
			scanf("%f",&a[i][j]);
	for(i=0;i<3;i++)
	{
		sum=0;
		for(j=0;j<5;j++)
			sum=sum+a[i][j];
		a[i][5]=sum/5;
	}
	for(j=0;j<5;j++)
	{
		sum=0;
		for(i=0;i<3;i++)
			sum=sum+a[i][j];
		a[3][j]=sum;
		aver[j]=sum/3;
	}
	a[3][5]=0;
	printf("Output:\n");
	for(i=0;i<4;i++)
	{
			for(j=0;j<6;j++)
				printf("%7.1f",a[i][j]);
			printf("\n");
	}
	printf("average:\n");
	for(i=0;i<5;i++)
		printf("%7.1f",aver[i]);
	printf("\n");
}