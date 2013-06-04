#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <string> v ( 5001 );

void Fib ( int x )
{
	int carry , temp;
	carry = 0;
	string zero ( v[x-1].length() - v[x-2].length() , '0' );
	string str = zero + v[x-2];
	string Res;
	for ( int i = v[x-1].length() - 1 ; i >= 0 ; i-- )
	{
		temp = ( v[x-1][i] - '0' ) + ( str[i] - '0' ) + carry;
		string t ( 1 , '0' + ( temp % 10 ) );
		Res =  t + Res;
		carry = temp / 10;
	}
	if ( carry == 1 ) Res = "1" + Res;
	v[x] = Res;
}


int main ()
{
	freopen ( "Fibonacci Freeze.in" , "r" , stdin );
	int n;
	v[0] = "0";
	v[1] = "1";
	for ( int i = 2 ; i <= 5000 ; i++ )
		Fib ( i );
	while ( cin >> n )
		cout << "The Fibonacci number for " << n << " is " << v[n] << endl;
	return 0;
}