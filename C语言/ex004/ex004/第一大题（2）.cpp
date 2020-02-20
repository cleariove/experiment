#include<iostream>
using namespace std;
void main()
{
	int m,n,k;
	m=1000;
	n=45;
	cout<<"\n("<<m<<':'<<n<<')';
	k=0;
	while(m>=n)
	{
		m=m-n;
		k=k+1;
	}
	cout<<k<<"---"<<m;
}