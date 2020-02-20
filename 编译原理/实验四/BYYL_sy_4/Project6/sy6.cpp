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
	/*读取一行表达式*/
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
				/*ex[ ]中存放逆波兰式 */
				ch = str[i];
				i++;
				/*str[ ]中存放中缀表达式*/
			}
			i--;
			ex[t] = ',';
			t++;
			break;
		}
		ch = str[i];
		i++;
	}
	/*当中缀表达式扫描完毕，检查ω栈是否为空，若不空则一一退栈*/
	while (top != 0) {
		ex[t] = stack[top];
		t++;
		top--;
	}
	ex[t] = ';';
	for (j = 1; j < sum; j++)
		printf("%c", str[j]);
	printf("\n输出：");
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
				printf("除零错误\n");
				break;
				/*异常退出*/
			}
			top--;
			break;
			/*将数字字符转化为对应的数值*/
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
	if ((err = fopen_s(&fp, "C:\\Users\\StephenHe\\Desktop\\4.txt", "r")) != NULL) {            //以只读方式打开文件，失败则退出程序
		printf("file can not open!");
		exit(0);
	}
	n = 1;
	printf("逆波兰式的翻译和计算结果如下：\n");
	while (1) {
		acquire(fp);
		if (feof(fp))	break;
		getValue();
	}
	fclose(fp);
	fp = NULL;
}
