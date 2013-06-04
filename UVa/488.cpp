#include <iostream>
#include <string>

using namespace std;

int main ()
{
	freopen ( "Triangle Wave.in" , "r" , stdin );
	int n , A , F;
	string str;
	cin >> n;
	for ( int x = 1 ; x <= n && getline ( cin , str ) && cin >> A >> F ; x++ )
		for ( int i = 1 ; i <= F ; i++ )
		{
			for ( int j = 1 ; j <= A ; j++ )
			{
				for ( int k = 0 ; k < j ; k++ )
					cout << j;
				cout << endl;
			}
			for ( int j = A-1 ; j >= 1 ; j-- )
			{
				for ( int k = 0 ; k < j ; k++ )
					cout << j;
				cout << endl;
			}
			if ( !( x == n && i == F ) )	cout << endl;
		}
	return 0;
}