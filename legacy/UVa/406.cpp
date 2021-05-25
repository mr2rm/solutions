#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

void PreComputing ()
{
	v.reserve ( 1000 );
	bool b;
	for ( int i = 1 ; i <= 1000 ; i++ )
	{
		b = true;
		for ( int j = 2 ; j <= sqrt ( (double)i ) ; j++ )
			if ( i % j == 0 )
			{
				b = false;
				break;
			}
		if ( b == true )
			v.push_back ( i );
	}
}

int main ()
{
	freopen ( "Prime Cuts.in" , "r" , stdin );
	PreComputing ();
	int index , m , n , c;
	vector<int>::iterator it;
	while ( cin >> n >> c )
	{
		cout << n << " " << c << ":";
		it = upper_bound ( v.begin() , v.end() , n );
		index = ( it - v.begin() );
		if ( !( index <= (2 * c) ) )
			if ( index % 2 != 0 )
			{
				index /= 2;
				if ( c != 1 )
				{
					index -= ceil ( (double)c / 2 );
					m = index - 1 + ( 2 * c );
					for ( int i = index ; i < m ; i++ ) 
						cout << " " << v[i];
				}
				else
					cout << " " << v[index];
			}
			else 
			{	
				index /= 2;
				index -= c;
				m = index + ( 2 * c );
				for ( int i = index ; i < m ; i++ )
					cout << " " << v[i];
			}
		else
			for ( int i = 0 ; i < index ; i++ )
				cout << " " << v[i];
		cout << endl << endl;
	}
	return 0;
}
