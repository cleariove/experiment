#include<iostream>
#include<string.h>
using namespace std;
void main()
{
	char a[20]="TER";
	char b[20]="COMP";
	int i;
	i=0;
	strcat(a,b);
    while(a[i++]!='\0') b[i]=a[i];
	cout<<b;
}