#include <iostream>
#include <cmath>

using namespace std;

#define eps 1e-6
#define e( x , y ) fabs( x - y ) <= eps

int main ()
{
	freopen ( "The Snail.in" , "r" , stdin );
	double H , U , D , F , high;
	int day;
	while ( cin >> H >> U >> D >> F && H != 0 )
	{
		high = 0;
		day = 1;
		F = ( F / 100 ) * U;
		high += U;
		while ( ( ( high + eps ) < H || e( high , H ) ) && ( high > eps || e( high , 0 ) ) )
		{
			high -= D;
			if ( ( high + eps ) < 0 )
				break;
			day++;
			U -= F;
			if ( U >= 0 )
				high += U;
		}
		if ( ( high + eps ) < 0 )
			cout << "failure on day " << day << endl; 
		else
			cout << "success on day " << day << endl;
	}
	return 0;
}

