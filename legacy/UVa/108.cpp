#include <iostream>

using namespace std;

int N;
int d[101][101];
int nd[101];

int MaxiSum ()
{
	int msum , pmax;
	for ( int i = 1 ; i <= N ; i++ )
	{
		if ( i == 1 )
		{
			msum = nd[i];
			pmax = 0;
		}
		if ( pmax + nd[i] > msum )
			msum = pmax + nd[i];
		pmax += nd[i];
		if ( pmax < 0 )
			pmax = 0;
	}
	return msum;
}

int main ()
{
	//freopen ( "Maximum Sum.in" , "r" , stdin );
	int x , maxi , sum;
	while ( cin >> N )
	{
		for ( int i = 0 ; i <= N ; i++ )
			for ( int j = 0 ; j <= N ; j++ )
				if ( i == 0 || j == 0 )
					d[i][j] = 0;
				else
				{
					cin >> x;
					d[i][j] = d[i-1][j] + x;
				}
		maxi = d[1][1];
		for ( int i = 1 ; i <= N ; i++ )
			for ( int k = 0 ; k < i ; k++ )
			{
				for ( int j = 0 ; j <= N ; j++ )
					nd[j] = d[i][j] - d[k][j];
				sum = MaxiSum ();
				if ( sum > maxi )
					maxi = sum;
			}
		cout << maxi << endl;
	}
	return 0;
}