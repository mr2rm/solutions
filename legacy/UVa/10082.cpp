#include <iostream>
#include <string>

using namespace std;

int main ()
{
	freopen ( "WERTYU.in" , "r" , stdin );
	string str ( "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./" );
	string s;
	while ( getline ( cin , s ) )
	{
		for ( int i = 0 ; i < s.length() ; i++ )
			if ( s[i] != ' ' )
				for ( int j = 0 ; j < str.length() ; j++ )
					if ( s[i] == str[j] )
					{
						s[i] = str[j-1];
						break;
					}
		cout << s << endl;
	}
	return 0;
}