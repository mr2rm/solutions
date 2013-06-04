#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	freopen ( "Hartals.in" , "r" , stdin );
	int t , n , p , h , Result;
	cin >> t;
	for ( int i = 0 ; i < t && cin >> n >> p ; i++ )
	{
		vector <bool> v ( n , false );
		Result = 0;
		for ( int j = 0 ; j < p && cin >> h ; j++ )
		{
			for ( int k = h - 1 ; k < n ; k += h )
				if ( !( k % 7 == 5 || k % 7 == 6 ) && v[k] == false )
				{
					v[k] = true;
					Result++;
				}
		}
		cout << Result << endl;
	}
	return 0;
}
