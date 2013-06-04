#include <iostream>
#include <string>

using namespace std;

int main ()
{
	freopen ( "Marevelous Mazes.in" , "r" , stdin );
	string str;
	int t;
	while ( getline ( cin , str ) )
	{
		t = 0;
		for ( int i = 0 ; i < str.length() ; i++ )
		{
			if ( str[i] == '!' )	cout << endl;
			if ( str[i] == 'b' )	
			{
				string s ( t , ' ' );
				cout << s;
				t = 0;
			}
			if ( str[i] >= '0' && str[i] <= '9' )
				t += str[i] - '0';
			if ( ( str[i] >= 'A' && str[i] <= 'Z' ) || str[i] == '*' )
			{
				string s ( t , str[i] );
				cout << s;
				t = 0;
			}
		}
		cout << endl;
	}
	return 0;
}