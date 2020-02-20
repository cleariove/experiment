#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
#define NULL 0
#define MAXSIZE 30							//单行表达式的符号总数最大值
typedef struct grammar_symbol				//文法符号
{
	char ch;
	int po;
	string val;
	int type;
}W;

char pre[6][6] = {					//优先关系表
		{ '>', '<', '<', '>', '<','>' },
		{ '>', '>', '<', '>', '<', '>' },
		{ '<', '<', '<', '=', '<', '1' },
		{ '>', '>', '2', '>', '2', '>' },
		{ '>', '>', '2', '>', '2', '>' },
		{ '<', '<', '<', '3', '<', '=' }
};
char GetChar(FILE* fp) {                      //读取文件中的一个字符
	char ch;
	ch = fgetc(fp);
	return ch;
}

char GetBC(FILE* fp) {							//读取文件的字符直至ch不是空白
	char ch;
	do {
		ch = GetChar(fp);
	} while (ch == ' ' || ch == '\t' || ch == '\n');
	return ch;
}

void Concat(char ch, char strToken[]) {            //将ch中的字符连接到strToken之后
	char str[2];
	int len = strlen(strToken);
	strToken[len] = ch;
	strToken[len + 1] = '\0';
}

int IsLetter(char ch) {							//布尔函数，判断ch中的字符是否为字母,是返回1，否则返回0
	int flag = 0;
	if (ch >= 'a' && ch <= 'z')
		flag = 1;
	return flag;
}

int IsDigit(char ch) {							//布尔函数，判断ch中的字符是否为数字,是返回1，否则返回0
	int flag = 0;
	if (ch >= '0' && ch <= '9')
		flag = 1;
	return flag;
}

int Reserve(char strToken[]) {	   //整型函数，对strToken中的字符串查找保留字表，若它是一个保留字则返回它的编码，否则返回0
	int code = 0, i;
	char keyWord[6][6] = { "if", "then", "else", "while", "do" };
	for (i = 0; i < 5; i++) {
		if (strcmp(strToken, keyWord[i]) == 0) {
			code = i + 1;
			break;
		}
	}
	return code;
}

int SearchOP(char ch) {		//整型函数，对strToken中的字符串查找运算符和界符，若它是一个运算符或界符，则返回它的编码，否则返回0
	int code = 0, i;
	char OP[10] = { '+', '*',' (', ')', '-', '/', '<', '>', '=', ';' };
	for (i = 0; i < 10; i++) {
		if (ch == OP[i]) {
			code = i + 1;
			break;
		}
	}
	return code;
}

char Retract(FILE* fp, char ch) {			//子函数，将搜索指示器回调一个字符位置，将ch置为空白字符
	ch = ' ';
	fseek(fp, -1L, 1);
	return ch;
}

void ProError() {						//错误处理函数
	printf("输入错误！\n");
	return;
}

int scan(FILE* fp, W* E, int num) {
	W w;
	char ch;
	char strToken[10];
	strToken[0] = '\0';						//置strToken为空串
	ch = GetBC(fp);					       //先读取一个非空白的字符
	if (feof(fp))			return 0;
	if (ch == ';') {
		printf(";");
		return 0;			//判断表达式尾，是则返回调用程序
	}
	if (IsLetter(ch)) {									//判断标识符
		while (IsLetter(ch) || IsDigit(ch)) {
			Concat(ch, strToken);
			ch = GetChar(fp);
		}
		ch = Retract(fp, ch);
		if (Reserve(strToken)) {						//判断关键字
			printf("<%s,->\n", strToken);
		}
		else          //判断标识符
		{
			printf("%s", strToken);
			w.ch = 'i';
			w.po = 4;
			w.val = strToken;
			w.type = 0;
			E[num] = w;
		}

	}
	else if (ch >= '1' && ch <= '9') {					//判断十进制整数
		while (IsDigit(ch)) {
			Concat(ch, strToken);
			ch = GetChar(fp);
		}
		ch = Retract(fp, ch);
		printf("%s", strToken);
		w.ch = 'i';
		w.po = 4;
		w.val = strToken;
		w.type = 1;
		E[num] = w;
	}
	else if (ch == '0') {
		ch = GetChar(fp);
		if (ch >= '1' && ch <= '7') {					//判断八进制整数
			while (ch >= '0' && ch <= '7') {
				Concat(ch, strToken);
				ch = GetChar(fp);
			}
			ch = Retract(fp, ch);
			printf("<2,%s>\n", strToken);
		}
		else if (ch == 'x') {						//判断十六进制整数
			ch = GetChar(fp);
			while (IsDigit(ch) || ch >= 'a' && ch <= 'f') {
				Concat(ch, strToken);
				ch = GetChar(fp);
			}
			ch = Retract(fp, ch);
			printf("<3,%s>\n", strToken);
		}
		else {						//判断十进制的0
			ch = Retract(fp, ch);
			printf("0");
			w.ch = 'i';
			w.po = 4;
			w.val = "0";
			w.type = 0;
			E[num] = w;
		}
	}
	else if (SearchOP(ch) != 0) {		//判断运算符和界符
		printf("%c", ch);
		int po = SearchOP(ch) - 1;
		w.ch = ch;
		w.po = po;
		E[num] = w;
	}
	else {								//出错
		ProError();
	}
	return 1;
}

bool checkVt(char ch) {
	bool flag = false;
	int i;
	char Vt[6] = { '+', '*', '(', ')', 'i', '#' };
	for (i = 0; i < 6; i++) {
		if (ch == Vt[i]) {
			flag = true;
		}
	}
	return flag;
}


W Statute(W* S, int s, int e) {		//规约子函数，将S中j+1到k的符号规约为N
	W N;
	if (S[s].ch == 'i' && s == e) {
		N.ch = 'F';
		N.val = S[s].val;
		N.type = S[s].type;
	}
	else if (S[s].ch == '(' && !(checkVt(S[s + 1].ch)) && S[e].ch == ')') {
		if (S[s + 1].type == 1) {
			N.ch = 'F';
			N.val = S[s + 1].val;
			N.type = S[s + 1].type;
		}
		else {
			N.ch = 'F';
			N.val = '(' + S[s + 1].val + ')';
			N.type = S[s + 1].type;
		}
	}
	else if (!(checkVt(S[s].ch)) && S[s + 1].ch == '+' && !(checkVt(S[e].ch))) {
		N.ch = 'E';
		if (S[s].type == 1 && S[e].type == 1) {
			N.type = 1;
			int v = atoi(S[s].val.data()) + atoi(S[e].val.data());
			char l[30];
			sprintf_s(l, 30, "%d", v);
			N.val = l;
		}
		else {
			N.type = 0;
			N.val = S[s].val + S[s + 1].ch + S[e].val;
		}
	}
	else if ((s != e) && !(checkVt(S[s].ch)) && S[s + 1].ch == '*' && !(checkVt(S[e].ch))) {
		N.ch = 'T';
		if (S[s].type == 1 && S[e].type == 1) {
			N.type = 1;
			int v = atoi(S[s].val.data()) * atoi(S[e].val.data());
			char l[30];
			sprintf_s(l, 30, "%d", v);
			N.val = l;
		}
		else {
			N.type = 0;
			N.val = S[s].val + S[s + 1].ch + S[e].val;
		}
	}
	else if (S[s].ch == 'T' && s == e) {
		N.ch = 'E';
		N.val = S[s].val;
		N.type = S[s].type;
	}
	else {
		N.ch = '#';
	}
	N.po = 4;
	return N;
}

void error(char errnum) {				//错误处理子函数
	if (errnum == '1') {
		printf("错误，非法左括号\n\n");
	}
	else if (errnum == '2') {
		printf("错误，缺少运算符\n\n");
	}
	else if (errnum == '3') {
		printf("错误，非法右括号\n\n");
	}
	else if (errnum == '4') {
		printf("错误，缺少表达式\n\n");
	}
}

int syntax(W* E, int num) {			//算法对应的主要实现程序
	W S[MAXSIZE];
	int k = 1, i = 0, j;
	W border, A, Q;
	border.ch = '#';
	border.po = 5;
	E[num] = border;
	S[k] = border;
	do {
		A = E[i++];
		if (checkVt(S[k].ch))		//判断S[k]是终结符
			j = k;
		else
			j = k - 1;
		while (pre[S[j].po][A.po] == '>') {
			do {
				Q = S[j];
				if (checkVt(S[j - 1].ch))
					j = j - 1;
				else
					j = j - 2;
			} while (pre[S[j].po][Q.po] != '<');
			W N = Statute(S, j + 1, k);
			if (N.ch == '#') {
				error('4');
				return 0;
			}
			k = j + 1;
			S[k] = N;
		}
		if (pre[S[j].po][A.po] == '<' || pre[S[j].po][A.po] == '=') {
			k++;
			S[k] = A;
		}
		else {
			error(pre[S[j].po][A.po]);
			return 0;
		}
	} while (A.ch != '#');
	if (A.ch == '#') {
		printf("正确，结果为：%s\n\n", S[k - 1].val.data());
		return 0;
	}
}

int main() {
	FILE* fp;
	errno_t err;
	if ((err = fopen_s(&fp, "C:\\Users\\StephenHe\\Desktop\\expression.txt", "r")) != NULL) {            //以只读方式打开文件，失败则退出程序
		printf("file can not open!");
		exit(0);
	}
	int n = 0;
	printf("语法分析结果如下：\n\n");
	while (!feof(fp)) {					//若不是文件尾则执行循环
		int num = 0;
		W E[MAXSIZE];					//存储一行表达式
		GetBC(fp);
		if (!feof(fp)) {
			n++;
			fseek(fp, -1L, 1);
			printf("(%d)", n);
		}
		else {
			break;
		}
		while (1) {						//只读一行，行末标志为“；”
			int flag = scan(fp, E, num);
			if (flag == 0)		break;
			num++;
		}
		printf("\n输出：");
		syntax(E, num);
	}
	fclose(fp);                      //关闭文件
	fp = NULL;						//避免指向非法内存
}
