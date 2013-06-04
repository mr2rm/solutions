#include <iostream>
#include <cmath>
#include <vector> 

using namespace std ;

vector<int> SCS(1000);

int Average ( int s )
{
	int sum = 0 ;
	for ( int i = 0 ; i < s ; i++ )
		sum += SCS[i] ;
	return floor ( (double)( sum / s ) ) ;
}

double AboveAverage ( int a , int s )
{
	int AAc = 0 ;
	for ( int i = 0 ; i < s ; i++ )
		if ( SCS[i] > a )
			AAc++ ;
	return ( (double)(AAc*100) / (double)s ) ;
}

int main()
{
	freopen ( "Above Average.in" , "r" , stdin );
	int A , C , N ,sum;
	cin >> C;
	cout.flags ( ios::fixed | ios::showpoint );
	cout.precision ( 3 );
	for ( int i = 1 ; i <= C && cin >> N  ; i++ )
	{
		sum = 0;
		for ( int j = 0 ; j < N ; j++ )
			cin >> SCS[j];
		A = Average ( N );
		cout << AboveAverage ( A , N ) << "%" << endl;
	}
	return 0;
}