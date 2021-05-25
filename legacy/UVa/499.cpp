#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main ()
{
	freopen ( "What's The Frequency, Kenneth.in" , "r" , stdin );
	string str;
	while ( getline ( cin , str ) )
	{
		vector <int> v ( 256 , 0 );
		int maxi = 0;
		for ( int i = 0 ; i < str.length() ; i++ )	
			if ( ( str[i] >= 'A' && str[i] <= 'Z' ) || ( str[i] >= 'a' && str[i] <= 'z' ) )
			{
				v[str[i]]++;
				maxi = max ( v[str[i]] , maxi );
			}
		for ( int i = 'A' ; i <= 'Z' ; i++ )
			if ( v[i] == maxi )
				cout << (char)i;
		for ( int i = 'a' ; i <= 'z' ; i++ )
			if ( v[i] == maxi )
				cout << (char)i;
		cout << " " << maxi << endl;
	}
	return 0;
}