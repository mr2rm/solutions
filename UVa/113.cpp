#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main ()
{
	freopen ( "Power of Cryptography.in" , "r" , stdin );
	double p , k;
	int n;
	while ( cin >> n >> p )
		printf ( "%.0lf\n" , pow ( p , 1./n ) );
	return 0;
}