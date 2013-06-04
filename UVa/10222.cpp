#include <iostream>
#include <string>

using namespace std;

int main ()
{
	string str;
	string allchar ( "qwertyuiop[]asdfghjkl;'\\zxcvbnm,./" );
	int arr[256] = {-1};
	arr[' '] = ' ';
	for ( int i = 2 ; i < allchar.length() ; i++ )
	{
		arr[allchar[i]] = allchar[i-2];
		if ( allchar[i] >= 'a' && allchar[i] <= 'z' )
			arr[allchar[i]-32] = allchar[i-2];
	}
	while ( getline ( cin , str ) )
	{
		for ( int i = 0 ; i < str.length() ; i++ )
			if ( arr[str[i]] != -1 )
				cout << (char)arr[str[i]];
		cout << endl;
	}
	return 0;
}