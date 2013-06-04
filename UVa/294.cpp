#include <iostream>

using namespace std;

int P , D;

void MAX ( int a , int b )
{
	if ( a > D )
	{
		D = a;
		P = b;
	}
}

void MOH ( int n )
{
	int sum = 0;
	for ( int i = 1 ; i <= n/i ; i++ )
			if ( n % i == 0)
			{
				if ( i != n/i)
					sum = sum + 2;
				else
					sum = sum + 1;
			}
	MAX ( sum , n );
}
int main()
{
	freopen( "Divisors.in" , "r" , stdin );
	int m;
	cin >> m;
	int L , U;
	for ( int i = 0 ; i < m ; i++ )
	{
		P = 0;
		D = 0;
		cin >> L >> U;
		for ( int j = L ; j <= U ; j++ )
			MOH ( j );
		cout << "Between " << L << " and " << U << ", "; 
		cout << P << " has a maximum of " << D << " divisors." << endl;
	}
	return 0;
}
