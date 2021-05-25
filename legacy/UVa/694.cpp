#include <iostream>
 
using namespace std;
 
int main ()
{
	freopen ( "The Collatz Sequence.in" , "r" , stdin );
	int l , result;
	long long a;
	for ( int c = 1 ; cin >> a >> l && a > 0 && l > 0 ; c++ )
	{
		cout << "case " << c << ": a = " << a << ", limit = " << l << ", number of terms = ";
		result = 0;
		while ( a != 1 && a <= l )
		{
			if ( a % 2 == 0 )       a /= 2;
			else    a = 3*a + 1;
			result++;
		} 
		a == 1 ? cout << result + 1 : cout << result;
		cout << endl;
	}
	return 0;
}