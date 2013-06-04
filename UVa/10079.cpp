#include <iostream>

using namespace std;

int main ()
{
	//freopen ( "Pizza Cutting.in" , "r" , stdin );

	long long n;
	while ( cin >> n && n >= 0 )	cout << ( n * ( n + 1 ) / 2 ) + 1 << endl;
	return 0;
}