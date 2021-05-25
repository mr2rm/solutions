#include <iostream>
#include <cmath>

using namespace std;

unsigned int B[32];
unsigned long long B32;

int BS ( int x , int y , unsigned long long n )
{
	if ( n == 0 )
		return 0;
	if ( n >= B32 )
		return 32;
	if ( n > B[31] && n < B32 )
		return 31;
	int mid = ( x + y ) / 2;
	if ( n == B[mid] || ( B[mid] < n && n < B[mid+1] ) )
		return mid;
	if ( n > B[mid] )
		return BS ( mid + 1 , y , n );
	else
		return BS ( x , mid - 1 , n );
}

//Vaghti OverFlow Mishe Tashih Mikone//
/*int main ()											
{
	freopen ( "To Carry or not to Carry.in" , "r" , stdin );
	unsigned int a , b;
	for ( int i = 0 ; i < 32 ; i++ )				//PreComputing
		B[i] = pow ( 2. , (double) i );
	B32 = pow ( 2. , 32. );
	while ( cin >> a >> b )
	{
		int foa = BS ( 0 , 31 , a );
		int fob = BS ( 0 , 31 , b );
		int maxi = max ( foa , fob );
		unsigned long long sum = a + b;
		int fos = BS ( 0 , 31 , sum );
		if ( fos > maxi )
		{
			if ( fos == 32 )
				cout << sum - B32 << endl;
			else
				cout << sum - B[fos] << endl;
		}
		else 
			cout << sum << endl;
	}
	return 0;
}*/

int main ()
{
	freopen ( "To Carry or not to Carry.in" , "r" , stdin );
	unsigned int a , b , result;
	while ( cin >> a >> b )
	{
		result = a ^ b;
		cout << result << endl;
	}
	return 0;
}