#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int d[2001][2001];

int main ()
{
	freopen ( "Edit Distance.in" , "r" , stdin );
	int T;
	string A , B;
	cin >> T;
	for ( int i = 0 ; i < T && cin >> A >> B ; i++ )
	{
		for ( int i = 0 ; i <= A.length() ; i++ )
			for ( int j = 0 ; j <= B.length() ; j++ )
				if ( i == 0 || j == 0 )
					d[i][j] = i + j;
				else
					if ( A[i-1] == B[j-1] )
						d[i][j] = d[i-1][j-1];
					else
						d[i][j] = min ( d[i-1][j-1] , min ( d[i][j-1] , d[i-1][j] ) ) + 1;
		cout << d[A.length()][B.length()] << endl;
	}
	return 0;
}