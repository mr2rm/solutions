#include <iostream>

using namespace std;

int main ()
{
	freopen ( "The 3n+1 Problem.in" , "r" , stdin );
	int i , j;
	int counter , temp , Result;
	while ( cin >> i >> j )
	{
		Result = 0;
		cout << i << " " << j << " ";
		int mini = min ( i , j );
		int maxi = max ( i , j ); 
		for ( int k = mini ; k <= maxi ; k++ )
		{
			temp = k;
			for ( counter = 1 ; temp != 1 ; counter++ )
				if ( temp % 2 == 0 )
					temp /= 2;
				else
					temp = 3 * temp + 1;
			Result = max ( Result , counter );
		}
		cout << Result << endl;
	}
	return 0;
}