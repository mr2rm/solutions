#include <iostream>

using namespace std;

int main ()
{
	freopen ( "C:\\Documents and Settings\\Administrator\\Desktop\\Uva\\Relational Operators.in" , "r" , stdin );
	int t , x , y;
	cin >> t;
	for ( int i = 0 ; i < t && cin >> x >> y ; i++ )
	{
		if ( x > y )	cout << ">" << endl;
		if ( x < y )	cout << "<" << endl;
		if ( x == y )	cout << "=" << endl;
	}
	return 0;
}