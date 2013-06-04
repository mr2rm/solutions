#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main ()
{
	freopen ( "Skew Binary.in" , "r" , stdin );
	string n;
	int Result;
	while ( cin >> n && n != "0" )
	{
		//reverse ( n.begin() , n.end() );
		Result = 0;
		for ( int i = 0 ; i < n.length() ; i++ )
			//Result += ( n[i] - '0' ) * ( pow ( 2. , i + 1 ) - 1 );
			Result += ( n[i] - '0' ) * ( pow ( 2. , (double)n.length() - i ) - 1 );
		cout << Result << endl;
	}
	return 0;
}