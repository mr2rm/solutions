#include <iostream>
#include <string>

using namespace std;

int main ()
{
	freopen ( "The Decoder.in" , "r" , stdin );
	string str;
	while ( getline ( cin , str ) )
	{
		string Result ( str.length() , ' ' );
		for ( int i = 0 ; i < str.size() ; i++ )
			Result[i] = str[i] - 7;
		cout << Result << endl;
	}
	return 0;
}