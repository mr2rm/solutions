#include <iostream>

using namespace std;

int main ()
{
	unsigned long long d[1003];
	d[0] = 0;
	for ( int i = 1 ; i < 1003 ; i++ )
		if ( i == 1 || i == 2 )
			d[i] = i - 1;
		else
			d[i] = ( ( 2 * d[i-1] ) + d[i-2] + d[i-3] );
	int t;
	while ( cin >> t )
		cout << d[t+2] << endl;
	return 0;
}