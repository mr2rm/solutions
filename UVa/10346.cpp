#include <iostream>

using namespace std;

int main ()
{
	freopen ( "Peter’s Smokes.in" , "r" , stdin );
	int x , y , Result;
	while ( cin >> x >> y )
	{
		Result = x;
		while ( x >= y )
		{
			Result += x / y;
			x = ( x / y ) + ( x % y );
		}
		cout << Result << endl;
	}
	return  0;
}