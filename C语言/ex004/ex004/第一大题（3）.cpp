#include<iostream>
using namespace std;
void main()
{
	int i;
	for(i=1;i<=5;i++)
	{
		if(i%2)
			cout<<'*';
		else
		continue;
		cout<<'#';
	}
	cout<<"$\n";
}