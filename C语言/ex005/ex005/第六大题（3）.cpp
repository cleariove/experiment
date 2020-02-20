#include<iostream>
using namespace std;
#include<iomanip>
void main()
{
	int i=0,n,j,base,num[20];
	cin>>n>>base;
	do{
		i++;
		num[i]=n%base;
		n=n/base;
	}while(n!=0);
	for(j=i;j>=1;j--)
		cout<<num[j];
}