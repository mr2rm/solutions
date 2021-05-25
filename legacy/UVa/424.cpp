#include <iostream>
#include <vector>
#include <string>

using namespace std;

string str;
vector<int> v( 105 );
int diffrence = 0;

void Bignum1 ()
{
	int sum , carry = 0;
	int j = 104;
	for ( int i = str.size() - 1 ; i >= 0 ; i-- , j-- )
	{
		sum = ( str[i] - '0' ) + v[j] + carry;
		if ( sum >= 10 )
		{
			carry = 1;
			sum -= 10;
		}
		else
			carry = 0;
		v[j] = sum;
	}
}

void Bignum2 ( int index , int carr )
{
	if ( index == -1 )
		v[ v.size() - str.size() - 1 ] += carr;
	else
	{
		int sum = ( str[index] - '0' ) + v[ index + diffrence ] + carr;
		if ( sum >= 10 )
		{
			v[ index + diffrence ] = ( sum - 10 );
			Bignum2 ( index - 1 , 1 );
		}
		else
		{
			v[ index + diffrence ] = sum;
			Bignum2 ( index - 1 , 0 );
		}
	}
	return;
}



int main ()
{
	int i;
	while ( cin >> str && str != "0" )
	{
		//Bignum1 ();
		diffrence = 105 - str.size();
		Bignum2 ( str.size()-1 , 0 );
	}
	for ( i = 0 ; i < 105 ; i++ )
		if ( v[i] != 0 )
			break;
	for ( int j = i ; j < 105 ; j++ )
		cout << v[j];
	cout << endl;
	return 0;
}

