#include<stdio.h>
int main()
{
	char ch[80],tran[80];
	int i;
	printf("please input cipher code:");
	gets(ch);
	printf("cipher code :%s\n",ch);
	for(i=0;i<80;i++)
	{
		if((ch[i]>='A'&&ch[i]<='Z'))
			tran[i]=155-ch[i];
		else if((ch[i]>='a'&&ch[i]<='z'))
			tran[i]=219-ch[i];
		else tran[i]=ch[i];
	}
	printf("original text:%s\n",tran);
	return 0;
}