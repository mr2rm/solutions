#include <iostream>

using namespace std;

int main ()
{
	long long d[51];
	for ( int i = 1 ; i < 51 ; i++ )
	{
		if ( i == 1 || i == 2 )
			d[i] = i;
		else
			d[i] = d[i-1] + d[i-2];
	}
	int t;
	while ( cin >> t && t != 0 )
	{
		cout << d[t] << endl;
	}
	return 0;
}