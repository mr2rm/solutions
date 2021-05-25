#include <iostream>
#include <string>

using namespace std;

int main ()
{
	freopen ( "TeX Quotes.in" , "r" , stdin );
	string str;
	string arr[2] = { "``" , "''" } ;
	int index = 0;
	while ( getline ( cin , str ) )
	{
		for ( int i = 0 ; i < str.length() ; i++ )
			if ( str[i] == '"' )
			{
				string Temp1 ( str.begin() , str.begin() + i );
				string Temp2 ( str.begin() + i + 1 , str.end() );
				str = Temp1 + arr[index] + Temp2;
				index++;
				index %= 2;
			}
		cout << str << endl;
	}
	return 0;
}