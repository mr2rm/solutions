/*
ID: mohamma58
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main ()
{
	ifstream fin ( "gift1.in" );
	ofstream fout ( "gift1.out" );
	int n; 
	fin >> n;
	vector<string> str ( n );
	vector<int> d ( n , 0 );
	for ( int i = 0 ; i < n ; i++ )
		fin >> str[i];
	string s , ps;
	int money , body , index , p , pindex;
	while ( fin >> s )
	{
		for ( index = 0 ; index < n ; index++ )
			if ( str[index] == s )
				break;
		fin >> money >> body;
		if ( body == 0 )
			d[index] += money;
		else
		{
			d[index] -= money;
			d[index] += ( money % body );
			p = money / body;
			for ( int i = 0 ; i < body && fin >> ps ; i++ )
			{
				for ( pindex = 0 ; pindex < n ; pindex++ )
					if ( str[pindex] == ps )
						break;
				d[pindex] += p;
			}
		}
	}
	for ( int i = 0 ; i < n ; i++ )
		fout << str[i] << " " << d[i] << endl;
	return 0;
}