#include <iostream>

using namespace std;

int main ()
{
	freopen ( "Beat the Spread!.in" , "r" , stdin );
	int n , s , d;
	cin >> n;
	int x , y;
	for ( int i = 0 ; i < n && cin >> s >> d ; i++ )
	{
		/*
		if ( ( s + d ) % 2 == 0 )
		{
			x = ( s + d ) / 2;
			y = s - x;
			if ( y >= 0 )
			{
				cout << max ( x , y ) << " " << min ( x , y ) << endl;
				continue;
			}
		}
		cout << "impossible" << endl;
		*/
		/*
		if ( s >= d && ( s + d ) % 2 == 0 )
		{
			x = ( s + d ) / 2;
			y = s - x;
			cout << max ( x , y ) << " " << min ( x , y ) << endl;
		}
		else
			cout << "impossible" << endl;
		*/
	}
	return 0;
}