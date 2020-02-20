#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define longer 100
#define add 10

typedef char SElemType;
typedef float ElemType;

typedef struct
{
	SElemType *base,*top;
	int stacksize;
}SqStack_char;

typedef struct
{
	ElemType *base,*top;
	int stacksize;
}SqStack_num;

int InitStack_char(SqStack_char &S)
{
	S.base = (SElemType *)malloc(longer * sizeof(SElemType));
	if(!S.base)
		return 0;
	S.top = S.base;
	S.stacksize = longer;
	return 1;
}

int InitStack_num(SqStack_num &S)
{
	S.base = (ElemType *)malloc(longer * sizeof(ElemType));
	if(!S.base)
		return 0;
	S.top = S.base;
	S.stacksize = longer;
	return 1;
}

int Push_char(SqStack_char &S,SElemType e)
{
	if(S.top - S.base >= longer)
	{
		S.base = (SElemType *)realloc(S.base,(S.stacksize + add)*sizeof(SElemType));
		if(!S.base)
			return 0;
		S.top = S.base + S.stacksize;
		S.stacksize += add;
	}
	*S.top++ = e;
	return 1;
}

int Push_num(SqStack_num &S,ElemType e)
{
	if(S.top - S.base >= longer)
	{
		S.base = (ElemType *)realloc(S.base,(S.stacksize + add)*sizeof(ElemType));
		if(!S.base)
			return 0;
		S.top = S.base + S.stacksize;
		S.stacksize += add;
	}
	*S.top++ = e;
	return 1;
}

int Pop_char(SqStack_char &S,SElemType &e)
{
	if(S.top == S.base)
		return 0;
	e = *--S.top;
	return 1;
}

int Pop_num(SqStack_num &S,ElemType &e)
{
	if(S.top == S.base)
		return 0;
	e = *--S.top;
	return 1;
}

SElemType GetTop_char(SqStack_char &S,SElemType &e)
{
	if(S.top == S.base)
		return '\0';
	e = *(S.top-1);
	return e;
}

ElemType GetTop_num(SqStack_num &S,ElemType &e)
{
	if(S.top == S.base)
		return '\0';
	e = *(S.top-1);
	return e;
}

int In(char c)
{
	switch(c)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '#':
	case '(':
	case ')':
		return 1;
		break;
	}
	return 0;
}

char Precede(char a, char b)
{
    int i,j;
    char pre[][7]=
	{         
        {'>','>','<','<','<','>','>'},
        {'>','>','<','<','<','>','>'},
        {'>','>','>','>','<','>','>'},
        {'>','>','>','>','<','>','>'},
        {'<','<','<','<','<','=','0'},
        {'>','>','>','>','0','>','>'},
        {'<','<','<','<','<','0','='}
	};
    switch(a)
	{
        case '+': i=0; break;
        case '-': i=1; break;
        case '*': i=2; break;
        case '/': i=3; break;
        case '(': i=4; break;
        case ')': i=5; break;
        case '#': i=6; break;
    }
    switch(b)
	{
        case '+': j=0; break;
        case '-': j=1; break;
        case '*': j=2; break;
        case '/': j=3; break;
        case '(': j=4; break;
        case ')': j=5; break;
        case '#': j=6; break;
    }
    return pre[i][j];
}

ElemType Operate(ElemType a,SElemType e,ElemType b)
{
	ElemType c;
	switch(e)
	{
	case '+': 
		c = a + b;
		break;
	case '-':
		c = a - b;
		break;
	case '*':
		c = a * b;
		break;
	case '/':
		c = a / b;
		break;
	}
	return (c);
}

int main()
{
	SqStack_char optr;
	SqStack_num opnd;
	SElemType c,e1;
	ElemType e2,e3,num = 0;
	int i = 0,j = 0;
	InitStack_char(optr);
	InitStack_num(opnd);
	Push_char(optr,'#');
	printf("请输入表达式(以#号结尾):\n");
	c=getchar();
	while(c != '#' || GetTop_char(optr,e1) != '#')
	{
		if(!In(c))								
		{
			if((c >= '0' && c <= '9'))					//防止出现小数，记录总位数以及小数点前位数
			{
					num = 10 * num +(c - '0');
					i++;
					j++;
			}
			c = getchar();
			if(c == '.')
			{
				i = 0;
				c = getchar();
				continue;
			}
			if(In(c))
			{
				Push_num(opnd,num/pow(10.0,j - i));
				i = j = 0;
				num = 0;
			}
		}
		else 
		{
			switch(Precede(GetTop_char(optr,e1),c))
			{
			case '<':
				Push_char(optr,c);
				c = getchar();
				break;
			case '=':
				Pop_char(optr,e1);
				c = getchar();
				break;
			case '>':
				Pop_char(optr,e1);
				Pop_num(opnd,e2);
				Pop_num(opnd,e3);
				Push_num(opnd,Operate(e3,e1,e2));
				break;
			}
		}
	}
	printf("结果为:%f\n",GetTop_num(opnd,e2));
	system("pause");
	return 0;
}