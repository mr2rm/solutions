#include <iostream>
#include <string>

#define IF ( ( str[i] >= 'a' && str[i] <= 'z' ) || ( str[i] >= 'A' && str[i] <= 'Z' ) )

using namespace std;

int main ()
{
	freopen ( "Kindergarten Counting Game.in" , "r" , stdin );
	string str;
	int Result;
	bool b;
	while ( getline ( cin , str ) )
	{
		Result = 0;
		b = false;
		for ( int i = 0 ; i < str.length() ; i++ )
		{
			if ( !b && IF )
				b = true;
			if ( b && ( !IF || i == str.length() - 1 ) )
			{
				b = false;
				Result++;
			}
		}
		cout << Result << endl;
	}
	return 0;
}