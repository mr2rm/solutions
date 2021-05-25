/*
ID: mohamma58
PROG: beads
LANG: C++
*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin ( "beads.in" );
	ofstream fout ( "beads.out" );
	int n;
	string s;
	int Result , Sum , index;
    while ( fin >> n >> s )
	{
		Result = 0;
		bool b;
		char ch;
		for ( int i = 0 ; Result != n && i < n ; i++ )
		{
			b = true;	Sum = 0;	ch = 'n';
			for ( int j = i ; b && ( ch == 'n' || s[j] == 'w' || s[j] == ch ) ; j-- , j = ( j < 0 ? n - 1 : j ) )
			{
				index = j;
				if ( s[j] != 'w' && ch == 'n' )	ch = s[j];
				if ( j == i + 1 )	b = false;
				Sum++;
			}
			if ( b )
			{
				ch = 'n';
				for ( int j = ( i + 1 == n ? 0 : i + 1 ) ; j != index && ( ch == 'n' || s[j] == 'w' || s[j] == ch ) ; j++ , j = ( j == n ? 0 : j ) )
				{
					if ( s[j] != 'w' && ch == 'n' )	ch = s[j];
					Sum++;
				}
			}
			Result = max ( Sum , Result );
			if ( !b )	break;
		}
		fout << Result << endl;
	}
    return 0;
}
