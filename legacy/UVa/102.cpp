#include <iostream>
#include <string>

using namespace std;

string myfunc ( int x , int y , int z )
{
	string str;
	int a[3] = { x , y , z };
	for ( int i = 0 ; i < 3 ; i++ )
		switch ( a[i] )
		{
			case 0:
				str = str + "B";
				break;
			case 1:
				str = str + "G";
				break;
			default:
				str = str + "C";
		}
	return str;
}

int main ()
{
	//freopen ( "Ecological Bin Packing.in" , "r" , stdin );
	int arr[3][3];

	while ( cin >> arr[0][0] )
	{
		int sum[3] = { 0 };
		sum[0] += arr[0][0];
		int minmove = -1;
		string ANS ( "GGG" );

		for ( int i = 0 ; i < 3 ; i++ )
			for ( int j = 0 ; j < 3 ; j++ )
				if ( !( i == 0 && j == 0 ) )
				{
					cin >> arr[i][j];
					sum[j] += arr[i][j];
				}
		
		for ( int i = 0 ; i < 3 ; i++ )
			for ( int j = 0 ; j < 3 ; j++ )
				if ( j != i )
					for ( int k = 0 ; k < 3 ; k++ )
						if ( k != j && k != i )
						{
							string temp = myfunc ( i , j , k );
							int tsum = ( sum[i] - arr[0][i] ) + ( sum[j] - arr[1][j] ) + ( sum[k] - arr[2][k] );
							if ( minmove == -1 || tsum < minmove )
							{
								minmove = tsum;
								ANS = temp;
							}
							if ( tsum == minmove && temp < ANS )
								ANS = temp;
						}
		cout << ANS << " " << minmove << endl;
	}
	return 0;
}