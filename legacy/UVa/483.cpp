#include <iostream>
#include <string>

using namespace std;

/*int main ()
{
	//freopen ( "Word Scramble.in" , "r" , stdin );

	string str;
	while ( getline ( cin , str ) )
	{
		int i , j , k;
		i = j = 0;
		while ( i != str.length() )
		//1
		{
			for ( ; i < str.length() && str[i] == ' ' ; i++ );
			for ( j = i ; j < str.length() && str[j] != ' ' ; j++ );
			string s ( str.begin() + i , str.begin() + j );
			//reverse ( s.begin() , s.end() );
			/*{
			int n = s.length() / 2;
			int m = s.length() - 1;
			for ( int k = 0 ; k < n ; k++ )
				swap ( s[k] , s[ m - k ] );
			}*/
 			//str.replace ( i , j - i , s );
			/*i = j;
		}

		//2
		/*{
			for ( ; i < str.length() && ( str[i] == ' ' || str[i] == '/t' ) ; i++ );
			for ( j = i ; j < str.length() && ( str[j] != ' ' || str[i] == '/t' ) ; j++ );
			//reverse ( str.begin() + i , str.begin() + j );
			{
			k = j ; j--;
			for ( ; i < j  ; j-- , i++ )
				swap ( str[i] , str[j] );
			i = k;
			}
			//i = j;
		}*/
		
		/*cout << str << endl;
	}
	return 0;
}*/

int main ()
{
	//freopen ( "Word Scramble.in" , "r" , stdin );
	
	string str;

	while ( getline ( cin , str ) )
	{
		int i , j;
		i = j = 0;
		
		while ( i != str.length() )
		{
			for ( ; i < str.length() && ( str[i] == ' ' || str[i] == '\t' ) ; i++ );
			for ( j = i ; j < str.length() && !( str[j] == ' ' || str[j] == '\t' ) ; j++ );
			string s ( str.begin() + i , str.begin() + j );
			reverse ( s.begin() , s.end() );
			str.replace ( i , j - i , s );
			i = j;
		}
		
		cout << str << endl;
	}

	return 0;
}