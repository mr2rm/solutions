#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main ()
{
	freopen ( "Palindromes.in" , "r" , stdin );
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