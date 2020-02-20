#include<iostream>
using namespace std;
void main()
{
	int m,n;
	m=1000;
	n=850;
	cout<<"\n("<<m<<','<<n<<')';
	while(m!=n)
	{
		while(m>n)
		{	m=m-n;
		cout<<'('<<m<<','<<n<<')';
		}
		while(m<n)
			{n=n-m;
		     cout<<'('<<m<<','<<n<<')';
		    }
		cout<<"\n"<<m;
	}
}