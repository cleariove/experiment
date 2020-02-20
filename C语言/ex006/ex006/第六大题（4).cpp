#include<iostream>
#include<iomanip>
using namespace std;
void subp ( )
{
	static int x=0,y=0; 		
	int a,b;
	a=x-y ; 
	b=x+y ; 
	cout << setw(5) << a << setw(5) << b << endl ;
	cout << setw(5) << x << setw(5) << y << endl ;
}
int x , y ;
void main()
{
	int a = 9,b = 3; 
	x=a-b ;  
	y=a+b ;
	subp();
	cout << setw(5) << a << setw(5) << b << endl ;
	cout << setw(5) << x << setw(5) << y << endl ;
}