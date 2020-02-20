/*
#include<stdio.h>
int main()
{
	char str[3][4]={};//后面换成大于3和小于等于3的试试，输入数据加上空格试试
	int i;
	for(i=0;i<3;i++)//如果是三的话你输入四个字符就挤占了\0位置，输入时可以空格隔开也可以enter建
	{
		
		scanf("%s",&str[i]);//这样子可以,可以输入三个字符串，每个字符串字符小于等于三，空格和enter键均可以分割开
	}//也可以不要&
	for(i=0;i<3;i++)
	{
		printf("%s\n",str[i]);
	}
}
*/
/*
#include<stdio.h>
int main()
{
	char str[3][4]={};
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("i=%d\n",i);
			printf("j=%d",j);
		scanf("%c",&str[i][j]);
		}//这样子输入的话，则必须要达到你总共可以储存的字符，因为空格和换行都会作为字符处理
	}
	printf("\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		printf("%c",str[i][j]);//用了%c格式输入就老实用%c格式输出
	}
}
*/
/*
#include<stdio.h>
int main()
{
	char str[3][4]={};
	int i;
	for(i=0;i<3;i++)
	{
		printf("i=%d\n",i);
		gets(str[i]);             //这个输入字符串可以包括空格，但不能回车，输入时可以不满4个就回车代表这个字符串完成
	}                             //最后一个字符串长度要小于4
	for(i=0;i<3;i++)
	{                              
		printf("%s\n",str[i]);      
	}
}
                                    而且如果第一个字符串超过长度且二三字符串直接按回车，会显示四个字符，
                                    这时如果二三字符串输入一个字母，第一个字符串又会包括第二个字符串的字母
		                            似乎除了最后一个字符串，
			                        前面的两个字符串超过长度了会输出本身前四个字符上在它下面的所有字符串的前四个字符*/


/*
#include<stdio.h>
int main()
{
	char str[80];
	int i;
	gets(str);//空格没关系，回车代表结束
	printf("%s\n",str);
}
	/*for(i=0;i<80;i++)
	printf("%c",str[i]);
	这样子的话如果不满80个就会有乱码*/


#include<stdio.h>
void main()
{
	char str[80];
	gets(str);
	printf("%s",str);
}