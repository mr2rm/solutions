#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main ()
{
	freopen ( "Perfection.in" , "r" , stdin );
	int n , x , temp;
	cout << "PERFECTION OUTPUT" << endl;
	while ( cin >> n && n != 0 )
	{
		x = ( n == 1 ? 0 : 1 );
		for ( int i = 2 ; i <= sqrt ( (double)n ) ; i++ )
		{
			if ( n % i == 0 )
			{
				temp = n / i;
				x += i;
				if ( temp != i )
					x += temp;
			}
		}
		temp = 5 - ( (int)log10 ( (double)n ) + 1 );
		string str ( temp , ' ' );
		cout << str << n << "  ";
		if ( x < n )	cout << "DEFICIENT" << endl;
		if ( x > n )	cout << "ABUNDANT" << endl;
		if ( x == n )	cout << "PERFECT" << endl;

	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}