#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	freopen ( "Power Crisis.in" , "r" , stdin );
	int n , m , index;
	bool Result;
	while ( cin >> n && n != 0 )
	{	
		Result = false;
		for ( m = 1 ; !Result ; m++ )
		{
			vector <bool> b ( n , false );
			vector <int> v;
			index = 0;	b[index] = true;	v.push_back ( index );
			while ( v.size() != n )
			{
				for ( int sum = 0 ; sum != m ; index = ( index + 1 ) % n )
					if ( b[index] == false )
						sum++;
				index = ( index == 0 ? n - 1 : index - 1 );
				b[index] = true;
				v.push_back( index );
			}
			if ( v[n-1] == 12 )
				Result = true;
		}
		cout << m - 1 << endl;
	}
	return 0;
}