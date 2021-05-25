#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str1 , str2;
int maxi;

string ZERO ( string str )
{
	int D = maxi - str.length();
	for ( int i = 0 ; i < D ; i++ )
		str = "0" + str;
	return str;
}

int Carry ( int n , int p )
{
	int sum;
	sum = ( ( str1[n] - '0' ) + ( str2[n] - '0' ) ) + p;
	if ( sum < 10 )
		return 0;
	else
		return 1;
}

int main()
{
	freopen ( "Primary Arithmetic.in" , "r" , stdin );
	while ( cin >> str1 >> str2 && (str1 != "0"  || str2 != "0") )
	{
		maxi = max ( str1.length() , str2.length() );
		str1 = ZERO ( str1 );
		str2 = ZERO ( str2 );
		int pcarry = 0;
		int counter = 0;
		for ( int i = maxi - 1 ; i >= 0 ; i-- )
		{ 
			pcarry = Carry ( i , pcarry );
			if ( pcarry == 1 )
				counter++;
		}
		switch ( counter )
		{
			case 0 :
			{
				cout << "No carry operation." << endl;
				break;
			}	
			case 1 :
			{
					cout << counter << " carry operation." << endl; 
					break;
			}
			default :
				cout << counter << " carry operations." << endl;
		}
	}
	return 0;
}
