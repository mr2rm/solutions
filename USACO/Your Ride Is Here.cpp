/*
ID: mohamma58
PROG: ride
LANG: C++
*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int compute ( string s )
{
	int sum = 1;
	for ( int i = 0 ; i < s.length() ; i++ )
		sum *= ( s[i] - 'A' ) + 1;
	return ( sum % 47 );
}

int main ()
{
	ifstream fin ( "ride.in" );
	ofstream fout ( "ride.out" );
	string comet , group , str;
	int csum , gsum;
	while ( fin >> comet && getline ( fin , str ) && fin >> group )
	{
		csum = compute ( comet );
		gsum = compute ( group );
		if ( csum == gsum )
			fout << "GO" << endl;
		else
			fout << "STAY" << endl;
	}
	return 0;
}