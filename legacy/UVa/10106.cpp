#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main ()
{
	freopen ( "Product.in" , "r" , stdin );
	string x , y;
	int carry , index , temp , t;
	while ( cin >> x >> y )
	{
		string Result ( x.length() + y.length() , '0' );
		index = Result.length() - 1;
		for ( int i = y.length() - 1 ; i >= 0 ; i-- , index-- )
		{
			t = y[i] - '0';	carry = 0;
			int k = index;
			for ( int j = x.length() - 1 ; j >= 0 ; j-- , k-- )
			{
				temp = t * ( x[j] - '0' );
				temp += carry + ( Result[k] - '0' );
				carry = temp / 10;	Result[k] = '0' + ( temp % 10 );
			}
			for ( ; carry != 0 ; k-- )
			{
				temp = ( Result[k] - '0' ) + carry;
				Result[k] = '0' + ( temp % 10 );
				carry = temp / 10;
			}
		}
		for ( index = 0 ; Result[index] == '0' && index < Result.length() - 1 ; index++ );
		string str ( Result.begin() + index , Result.end() );
		cout << str << endl;
	}
	return 0;
}