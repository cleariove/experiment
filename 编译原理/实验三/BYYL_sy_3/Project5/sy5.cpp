#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
#define NULL 0
#define MAXSIZE 30							//���б��ʽ�ķ����������ֵ
typedef struct grammar_symbol				//�ķ�����
{
	char ch;
	int po;
	string val;
	int type;
}W;

char pre[6][6] = {					//���ȹ�ϵ��
		{ '>', '<', '<', '>', '<','>' },
		{ '>', '>', '<', '>', '<', '>' },
		{ '<', '<', '<', '=', '<', '1' },
		{ '>', '>', '2', '>', '2', '>' },
		{ '>', '>', '2', '>', '2', '>' },
		{ '<', '<', '<', '3', '<', '=' }
};
char GetChar(FILE* fp) {                      //��ȡ�ļ��е�һ���ַ�
	char ch;
	ch = fgetc(fp);
	return ch;
}

char GetBC(FILE* fp) {							//��ȡ�ļ����ַ�ֱ��ch���ǿհ�
	char ch;
	do {
		ch = GetChar(fp);
	} while (ch == ' ' || ch == '\t' || ch == '\n');
	return ch;
}

void Concat(char ch, char strToken[]) {            //��ch�е��ַ����ӵ�strToken֮��
	char str[2];
	int len = strlen(strToken);
	strToken[len] = ch;
	strToken[len + 1] = '\0';
}

int IsLetter(char ch) {							//�����������ж�ch�е��ַ��Ƿ�Ϊ��ĸ,�Ƿ���1�����򷵻�0
	int flag = 0;
	if (ch >= 'a' && ch <= 'z')
		flag = 1;
	return flag;
}

int IsDigit(char ch) {							//�����������ж�ch�е��ַ��Ƿ�Ϊ����,�Ƿ���1�����򷵻�0
	int flag = 0;
	if (ch >= '0' && ch <= '9')
		flag = 1;
	return flag;
}

int Reserve(char strToken[]) {	   //���ͺ�������strToken�е��ַ������ұ����ֱ�������һ���������򷵻����ı��룬���򷵻�0
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

int SearchOP(char ch) {		//���ͺ�������strToken�е��ַ�������������ͽ����������һ��������������򷵻����ı��룬���򷵻�0
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

char Retract(FILE* fp, char ch) {			//�Ӻ�����������ָʾ���ص�һ���ַ�λ�ã���ch��Ϊ�հ��ַ�
	ch = ' ';
	fseek(fp, -1L, 1);
	return ch;
}

void ProError() {						//��������
	printf("�������\n");
	return;
}

int scan(FILE* fp, W* E, int num) {
	W w;
	char ch;
	char strToken[10];
	strToken[0] = '\0';						//��strTokenΪ�մ�
	ch = GetBC(fp);					       //�ȶ�ȡһ���ǿհ׵��ַ�
	if (feof(fp))			return 0;
	if (ch == ';') {
		printf(";");
		return 0;			//�жϱ��ʽβ�����򷵻ص��ó���
	}
	if (IsLetter(ch)) {									//�жϱ�ʶ��
		while (IsLetter(ch) || IsDigit(ch)) {
			Concat(ch, strToken);
			ch = GetChar(fp);
		}
		ch = Retract(fp, ch);
		if (Reserve(strToken)) {						//�жϹؼ���
			printf("<%s,->\n", strToken);
		}
		else          //�жϱ�ʶ��
		{
			printf("%s", strToken);
			w.ch = 'i';
			w.po = 4;
			w.val = strToken;
			w.type = 0;
			E[num] = w;
		}

	}
	else if (ch >= '1' && ch <= '9') {					//�ж�ʮ��������
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
		if (ch >= '1' && ch <= '7') {					//�жϰ˽�������
			while (ch >= '0' && ch <= '7') {
				Concat(ch, strToken);
				ch = GetChar(fp);
			}
			ch = Retract(fp, ch);
			printf("<2,%s>\n", strToken);
		}
		else if (ch == 'x') {						//�ж�ʮ����������
			ch = GetChar(fp);
			while (IsDigit(ch) || ch >= 'a' && ch <= 'f') {
				Concat(ch, strToken);
				ch = GetChar(fp);
			}
			ch = Retract(fp, ch);
			printf("<3,%s>\n", strToken);
		}
		else {						//�ж�ʮ���Ƶ�0
			ch = Retract(fp, ch);
			printf("0");
			w.ch = 'i';
			w.po = 4;
			w.val = "0";
			w.type = 0;
			E[num] = w;
		}
	}
	else if (SearchOP(ch) != 0) {		//�ж�������ͽ��
		printf("%c", ch);
		int po = SearchOP(ch) - 1;
		w.ch = ch;
		w.po = po;
		E[num] = w;
	}
	else {								//����
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


W Statute(W* S, int s, int e) {		//��Լ�Ӻ�������S��j+1��k�ķ��Ź�ԼΪN
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

void error(char errnum) {				//�������Ӻ���
	if (errnum == '1') {
		printf("���󣬷Ƿ�������\n\n");
	}
	else if (errnum == '2') {
		printf("����ȱ�������\n\n");
	}
	else if (errnum == '3') {
		printf("���󣬷Ƿ�������\n\n");
	}
	else if (errnum == '4') {
		printf("����ȱ�ٱ��ʽ\n\n");
	}
}

int syntax(W* E, int num) {			//�㷨��Ӧ����Ҫʵ�ֳ���
	W S[MAXSIZE];
	int k = 1, i = 0, j;
	W border, A, Q;
	border.ch = '#';
	border.po = 5;
	E[num] = border;
	S[k] = border;
	do {
		A = E[i++];
		if (checkVt(S[k].ch))		//�ж�S[k]���ս��
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
		printf("��ȷ�����Ϊ��%s\n\n", S[k - 1].val.data());
		return 0;
	}
}

int main() {
	FILE* fp;
	errno_t err;
	if ((err = fopen_s(&fp, "C:\\Users\\StephenHe\\Desktop\\expression.txt", "r")) != NULL) {            //��ֻ����ʽ���ļ���ʧ�����˳�����
		printf("file can not open!");
		exit(0);
	}
	int n = 0;
	printf("�﷨����������£�\n\n");
	while (!feof(fp)) {					//�������ļ�β��ִ��ѭ��
		int num = 0;
		W E[MAXSIZE];					//�洢һ�б��ʽ
		GetBC(fp);
		if (!feof(fp)) {
			n++;
			fseek(fp, -1L, 1);
			printf("(%d)", n);
		}
		else {
			break;
		}
		while (1) {						//ֻ��һ�У���ĩ��־Ϊ������
			int flag = scan(fp, E, num);
			if (flag == 0)		break;
			num++;
		}
		printf("\n�����");
		syntax(E, num);
	}
	fclose(fp);                      //�ر��ļ�
	fp = NULL;						//����ָ��Ƿ��ڴ�
}
