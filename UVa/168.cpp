#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main ()
{
	int n, m;
	int A[1000][1000];
	int B[1000][1000];
	cin >> n >> m;
	for (int I = 0; I < n; I++)
		for (int J = 0; J < m; J++)
			cin >> A[I][J];
	for (int I = n-1; I >= 0; I--)
		for (int J = m-1; J >= 0; J--)
		{
			if (I == n-1 && J == m-1)
				B[n-1][m-1] = A[n-1][m-1];
			else if (I == n-1)
				B[I][J] = min (B[I][J+1], A[I][J]);
			else if (J == m-1)
				B[I][J] = min (B[I+1][J], A[I][J]);
			else
				B[I][J] = min (A[I][J], min (B[I][J+1], B[I+1][J]));
		}
	for (int I = 0; I < n; I++)
		for (int J = 0; J < m; J++)
		{
			cout << B[I][J];
			if (J != m-1)
				cout << " ";
			else
				cout << endl;
		}
	/*//TLE
	for (int I = 0; I < n; I++)
		for (int J = 0; J < m; J++)
		{
			for (Y = J; Y < m; Y++)
			{
				X = I+J-Y;
				if (X < 0)
					X = 0;
				for (; X < n; X++)
					B[I][J] = min (B[I][J], A[X][Y]);
			}
			cout << B[I][J];
			if (J != m-1)
				cout << " ";
			else
				cout << endl;
		}		
	*/
	return 0;
}