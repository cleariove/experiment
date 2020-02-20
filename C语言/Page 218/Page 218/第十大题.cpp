#include<stdio.h>
#include<string.h>
int main()
{
	void longest(char str1[],char str2[]);
	char a[100],b[20];
	printf("please enter a string:");
	gets(a);
	longest(a,b);
	printf("%s\n",b);
	return 0;
}
void longest(char str1[],char str2[])
{
	int a,b;
	char str3[20],str4[20];
	int i,j,n,t;//t为判断真假
	int m;
	n=strlen(str1);
	t=1;
	a=b=0;
	for(i=0,j=0;i<=n;j++,i++)
	{
		if(t)
		{
			a++;
			str3[j]=str1[i];
	     }
		 else 
		 {
			 b++;
			 str4[j]=str1[i];
	      }
		 if(!((str1[i+1]>='A'&&str1[i+1]<='Z')||(str1[i+1]>='a'&&str1[i+1]<='z')))//下一个字符不是字母
		 {
			 j=0;
			 if(a>=b)
			 {
				 for(m=0;m<a;m++)
					 str2[m]=str3[m];
				 str2[m]='\0';
			 }
			 if(a<b)
			 {
				 for(m=0;m<b;m++)
					 str2[m]=str3[m];
				 str2[m]='\0';
			 }
			 t=-t;
			 if(t==-1)  a=0;
			 else b=0;
			 i++;
		 }
	}
}