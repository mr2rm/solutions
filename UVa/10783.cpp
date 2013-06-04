#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int OddSum ( int m , int n )
{
	int sum = 0 ;
	if ( m % 2 == 0 )
		m++ ;
	for ( int i = m ; i <= n ; i+=2 )
		sum += i ;
	return sum ;
}

int main ()
{
	freopen( "Odd Sum.in" , "r" , stdin );
	int a , b , T ;
	cin >> T ;
	for ( int i = 1 ; i <= T && cin >> a >> b ; i++ )
		cout << "Case " << i << ": " << OddSum ( a , b ) << endl ;	
	return 0 ;
}
