#include <iostream>
using namespace std;
int k = 1;
void main()
{
	int i = 4;
    void fun (int m);
    fun(i) ;
	cout << "(1)" << i << ',' << k << endl ;
	}
void fun( int m )
{
	m += k;
	k += m;
	{
		char k = 'B';
		cout << "(2)" << char(k-'A') << endl ;
    }
	cout << "(3)" << m << ',' << k << endl ;
}
