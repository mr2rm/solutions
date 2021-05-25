#include <iostream>
#include <cmath>

using namespace std;

void rightjustify ( int k )
{
	int c = 0;
	while ( k > 0 )
	{
		k = k / 10;
		c++;
	}
	c = 3 - c;
	for ( int i = 0 ; i < c ; i++ )
		cout << " ";
}

int main ()
{
	freopen ( "Factor and Factorials.in" , "r" , stdin );
	int n , s;
	int A[100];
	while ( cin >> n && n != 0 )
	{
		int C[100] = {0};
		int flag = 0 , countA = 1;
		A [0] = 2;
		C [0] = 1;
		for ( int i = 3 ; i <= n ; i++ )
		{
			for ( int j = 0 ; j < countA && A[j] <= sqrt( double(i) ) ; j++ )
				if ( i % A[j] == 0 )
				{
					flag = 1;
					C[j]++;
					s = i / A[j];
					for ( int k = 0 ; s != 1 ; k++ )
						while ( s % A[k] == 0 )
						{
							s /= A[k];
							C[k]++;
						}
					break;
				}
			if ( flag == 0 )
			{
				countA++;
				A[countA-1]=i;
				C[countA-1]=1;
			}
			flag = 0;
		}
		rightjustify ( n );
		cout << n << "! =";
		for ( int i = 0 ; i < countA ; i++ )
		{
			rightjustify ( C[i] ); 
			cout << C[i];
			if ( ( i + 1 ) % 15 == 0 && ( i + 2 ) <= countA )
				cout << endl << "      ";
		}
		cout << endl;
	}
	return 0;
}