#include <iostream>

using namespace std;

int main ()
{
    //freopen ( "Life, the Universe, and Everything.in" , "r" , stdin );
	int a;
    while ( cin >> a )
	{
		if ( a == 42 )
			return 0;
		else
			cout << a << endl;
	}
}
