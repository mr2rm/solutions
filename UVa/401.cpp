#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/*
map <char, char> mp;

bool palin (string str)
{
	string s = str;
	reverse (s.begin(), s.end());
	if (s == str)
		return true;
	return false;
}

bool mirror (string str)
{
	int sz = str.length();
	int mid = sz / 2;
	if (sz % 2)
	{
		if (mp[str[mid]] == ' ')
			return false;
		str[mid] = mp[str[mid]];
	}
	for (int I = 0; I < mid; I++)
		str[I] = mp[str[I]];
	return palin (str);
}


int main ()
{
	string s1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
	string s2 = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
	for (int I = 0; I < 35; I++)
		mp[s1[I]] = s2[I];
	string str, s;
	bool b1, b2;
	while (cin >> str)
	{
		b1 = palin (str);
		b2 = mirror (str);
		cout << str;
		if (b1 && b2)
			cout << " -- is a mirrored palindrome.";
		else if (b1)
			cout << " -- is a regular palindrome.";
		else if (b2)
			cout << " -- is a mirrored string.";
		else
			cout << " -- is not a palindrome.";
		cout << endl << endl;
	}
	return 0;
}
*/

int main ()
{
	string str;
	int size , temp;
	string Org ( "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789" );
	string Rev ( "A   3  HIL JM O   2TUVWXY51SE Z  8 " );
	char arr[256];
	for ( int i = 0 ; i < Org.length() ; i++ )
		arr[Org[i]] = Rev[i];
	vector <string> Results ( 4 );
	Results[0] = "is not a palindrome.";
	Results[1] = "is a regular palindrome.";
	Results[2] = "is a mirrored string.";
	Results[3] = "is a mirrored palindrome.";
	while ( cin >> str )
	{
		size = str.size();
		/*
		int Res[2] = { 0 , 0 };
		string s1 = str;
		reverse ( s1.begin() , s1.end() );
		if ( s1 == str )	Res[0] = 1;
		string s2 ( size , ' ' );
		for ( int i = 0 ; i < size ; i++ )
			s2[i] = arr[str[i]];
		reverse ( s2.begin() , s2.end() );
		if ( s2 == str )	Res[1] = 1;
		*/
		
		int Res[2] = { 1 , 1 };
		temp = size / 2;
		temp = ( size % 2 == 0 ? temp : temp + 1 ); 
		for ( int i = 0 ; i < temp ; i++ )
		{
			if ( Res[0] == 1 && str[i] != str[size-1-i] )	Res[0] = 0;
			if ( Res[1] == 1 && arr[str[i]] != str[size-1-i] ) Res[1] = 0; 
		}
		
		temp = Res[0] + ( 2 * Res[1] );
		cout << str << " -- " << Results[temp] << endl << endl;
	}
	return 0;
}