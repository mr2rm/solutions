#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> v;
int n;

bool IsJolly ()
{
	vector<int> mark ( n , 0 );
	for ( int i = 0 ; i < n - 1 ; i++ )
	{
		int f = fabs ( (double) ( v[i] - v[i+1] ) );
		if ( f > n - 1 )
			return false;
		else
		{
			mark[f]++;
			if ( mark[f] > 1 )
				return false;
		}
	}
	return true;
}

int main ()
{
	freopen ( "Jolly Jumpers.in" , "r" , stdin );
	v.reserve ( 3000 );
	while ( cin >> n )
	{
		v = vector<int> (n);
		for ( int i = 0 ; i < n ; i++ )
			cin >> v[i];
		if ( IsJolly () == true )
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;
	}
	return 0;
}