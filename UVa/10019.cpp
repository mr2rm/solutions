#include <iostream>

using namespace std;

int main ()
{
	freopen ( "Funny Encryption Method.in" , "r" , stdin );
	int t , n , temp , Result;
	cin >> t;
	for ( int i = 0 ; i < t && cin >> n ; i++ )
	{
		temp = n;	Result = 0;
		while ( temp != 0 )
		{
			Result += temp % 2;
			temp /= 2;
		}
		cout << Result << " ";
		Result = 0;
		while ( n != 0 )
		{
			temp = n % 10;
			while ( temp != 0 )
			{
				Result += temp % 2;
				temp /= 2;
			}
			n /= 10;
		}
		cout << Result << endl;
	}
	return 0;
}