#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	vector <long long> fact ( 101 );
	fact[0] = fact[1] = 1;
	for ( int i = 2 ; i < 101 ; i++ )
		fact[i] = i * fact[i-1];
	long long Res;
	int n , m;
	while ( cin >> n >> m && !( n == 0 && m == 0 ) )
	{
		Res = fact[n];
		long long temp = fact[n-m] * fact[m];
		Res /= temp;
		cout << n << " things taken " << m << " at a time is " << Res << " exactly." << endl;
	}
	return 0;
}
