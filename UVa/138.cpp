#include <iostream>

using namespace std;

int main ()
{
	int j , x = 3 , t , n = 4;
	for ( int i = 0 ; i < 10 ; i++ )
	{
		do
		{ 
			t = n + 1;
			x += ( n - 1 );
			for ( j = n + 2 ; x > t ; j++ )
				t+=j;
			n++;
		}
		while ( x != t );
		cout.width(10); 
		cout << ( n - 1 );
		cout.width(10);
		cout << ( j - 1 ) << endl;

	}
	return 0;
}