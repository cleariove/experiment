#include<iostream>
#include<stdio.h> 
#include<math.h>

using namespace std;
#define max 100 
char ex[max];
int n;

char GetBC(FILE* fp) {							
	char ch;
	do {
		ch = fgetc(fp);
	} while (ch == ' ' || ch == '\t' || ch == '\n');
	return ch;
}

void acquire(FILE* fp) {
	char str[max];
	char stack[max];
	char ch;
	int sum, i, j, t, top = 0;
	i = 0;
	/*��ȡһ�б��ʽ*/
	GetBC(fp);
	if (feof(fp))
		return;
	else {
		fseek(fp, -1L, 1);
		printf("\n(%d)", n);
		n++;
	}
	do {
		i++;
		str[i] = GetBC(fp);
	} while (str[i] != ';' && i != max);
	sum = i;
	t = 1;
	i = 1;
	ch = str[i];
	i++;
	while (ch != ';') {
		switch (ch) {
		case '(':
			top++; stack[top] = ch;
			break;
		case ')':
			while (stack[top] != '(') {
				ex[t] = stack[top];
				top--;
				t++;
			}
			top--;
			break;
		case '+':
		case '-':
			while (top != 0 && stack[top] != '(') {
				ex[t] = stack[top];
				top--;
				t++;
			}
			top++;
			stack[top] = ch;
			break;
		case '*':
		case '/':
			while (stack[top] == '*' || stack[top] == '/') {
				ex[t] = stack[top];
				top--;
				t++;
			}
			top++;
			stack[top] = ch;
			break;
		case ' ':
			break;
		default:
			while (ch >= '0'&&ch <= '9') {
				ex[t] = ch;
				t++;
				/*ex[ ]�д���沨��ʽ */
				ch = str[i];
				i++;
				/*str[ ]�д����׺���ʽ*/
			}
			i--;
			ex[t] = ',';
			t++;
			break;
		}
		ch = str[i];
		i++;
	}
	/*����׺���ʽɨ����ϣ�����ջ�Ƿ�Ϊ�գ���������һһ��ջ*/
	while (top != 0) {
		ex[t] = stack[top];
		t++;
		top--;
	}
	ex[t] = ';';
	for (j = 1; j < sum; j++)
		printf("%c", str[j]);
	printf("\n�����");
	for (j = 1; j < t; j++)
		printf("%c", ex[j]);
}
void getValue() {
	float stack[max], d;
	char ch;
	int t = 1, top = 0;
	ch = ex[t];
	t++;
	while (ch != ';') {
		switch (ch) {
		case '+':
			stack[top - 1] = stack[top - 1] + stack[top];
			top--;
			break;
		case '-':
			stack[top - 1] = stack[top - 1] - stack[top];
			top--;
			break;
		case '*':
			stack[top - 1] = stack[top - 1] * stack[top];
			top--;
			break;
		case '/':
			if (stack[top] != 0)
				stack[top - 1] = stack[top - 1] / stack[top];
			else {
				printf("�������\n");
				break;
				/*�쳣�˳�*/
			}
			top--;
			break;
			/*�������ַ�ת��Ϊ��Ӧ����ֵ*/
		default:
			d = 0;
			while (ch >= '0'&&ch <= '9') {
				d = 10 * d + ch - '0';
				ch = ex[t];
				t++;
			}
			top++;
			stack[top] = d;
		}
		ch = ex[t];
		t++;
	}
	printf("\t%g\n", stack[top]);
}
void main() {
	FILE* fp;
	errno_t err;
	if ((err = fopen_s(&fp, "C:\\Users\\StephenHe\\Desktop\\4.txt", "r")) != NULL) {            //��ֻ����ʽ���ļ���ʧ�����˳�����
		printf("file can not open!");
		exit(0);
	}
	n = 1;
	printf("�沨��ʽ�ķ���ͼ��������£�\n");
	while (1) {
		acquire(fp);
		if (feof(fp))	break;
		getValue();
	}
	fclose(fp);
	fp = NULL;
}
