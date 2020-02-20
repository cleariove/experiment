#include<stdio.h>
int main()
{
	void sort(char str[],int n);
	char array[11];
	printf("please enter ten characters:");
	gets(array);
	sort(array,10);
    printf("%s",array);
	return 0;
}
void sort(char str[],int n)
{
	int i,j;
	char temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
			if(str[j]>str[j+1])
			{temp=str[j];str[j]=str[j+1];str[j+1]=temp;}
	}
}