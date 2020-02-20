#include<iostream>
using namespace std;
void main()
{
	int a=1,b=10;
	do
	{
		b-=a;
		a++;
	}
	while(b--<=0);
	cout<<"a="<<a<<"b="<<b<<endl;
}