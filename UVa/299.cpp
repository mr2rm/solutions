#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 1 *//*int main ()
{
	freopen ( "Train Swapping.in" , "r" , stdin );
	int N , L , S;
	vector<int> v;
	v.reserve ( 50 );
	cin >> N;
	for ( int k = 0 ; k < N && cin >> L ; k++ )
	{
		v = vector<int> ( L );
		for ( int i = 0 ; i < L ; i++ )
			cin >> v[i];
		S = 0;
		for ( int i = 0 ; i < L ; i++ )
			while ( v[i] != ( i + 1) )
				for ( int j = i ; v[j] != ( j + 1 ) ; j++ )
				{
					swap ( v[j] , v[j+1] );
					S++;
				}
		cout << "Optimal train swapping takes " << S << " swaps." << endl;
	}
	return 0;
}*/

/*2*/int main ()
{
	freopen ( "Train Swapping.in" , "r" , stdin );
	int N , L , S , amount;
	cin >> N;
	vector<int> v;
	v.reserve ( 51 );
	for ( int t = 0 ; t < N && cin >> L ; t++ )
	{
		v = vector<int> ( L );
		for ( int k = 0 ; k < L ; k++ )
			cin >> v[k];
		S = 0;
		if ( L != 0 )
		{
			vector<int>::iterator j;
			for ( vector<int>::iterator i = v.begin() ; i != ( v.end() - 1 ) ; i++ )
			{
				amount = ( i - v.begin() ) + 1;
				if ( *i != amount )
				{
					for ( j = i + 1 ; *j != amount ; j++ );
					S += ( j - i );
					v.erase ( j );
					i = v.insert ( i , amount );
				}
			}
		}
		cout << "Optimal train swapping takes " << S << " swaps." << endl;
	}
	return 0;
}