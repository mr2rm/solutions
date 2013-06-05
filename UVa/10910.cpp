#include <iostream>

using namespace std;

//dp1 ---> AC (khaiam-pascal)
//int dp1[141][141];

int dp2[71][71];

int main ()
{
	/*
	for (int i = 0; i < 141; i++)
		for (int j = 0; j <= i; j++)
			if (j == 0 || i == j)
				dp1[i][j] = 1;
			else
				dp1[i][j] = dp1[i-1][j] + dp1[i-1][j-1];
	*/
	
	for (int j = 1; j < 71; j++)
		for (int i = 0; i < 71; i++)
			if (j == 1)
				dp2[i][j] = 1;
			else
			{
				int sum = 0;
				for (int k = 0; k <= i; k++)
					sum += dp2[k][j-1];
				dp2[i][j] = sum;
			}
		
	int k;
	int N, T, P;
	cin >> k;
	for (; k != 0 && cin >> N >> T >> P; k--)
	{
		int tm = T - N*P;
		
		//cout << dp1[tm+N-1][N-1] << endl;
		
		cout << dp2[tm][N] << endl;
	}
	return 0;
}

