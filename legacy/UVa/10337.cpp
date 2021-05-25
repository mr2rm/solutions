#include <iostream>
#include <cstring>

using namespace std;

int w[10][100000];
int dp[10][100001];

int main ()
{
	int t, x, n;
	cin >> t;
	for (; t != 0 && cin >> x; t--)
	{
		int n = x/100;
		
		for (int i = 9; i >= 0; i--)
			for (int j = 0; j < n; j++)
				cin >> w[i][j];
		
		for (int i = 0; i < 10; i++)		
			memset (dp[i], -1, sizeof dp[i]);
		
		dp[0][0] = 0;
		
		for (int j = 1; j <= n; j++)
			for (int i = 0; i < 10; i++)
				if (i <= j && i+j <= n)
				{
					int mini = 1000;
					for (int k = -1; k <= 1; k++)
					{
						int pi = i + k;
						if (pi >= 0 && pi <= 9 && dp[pi][j-1] != -1)
						{
							int f;
							switch (k)
							{
							case -1:
								f = 60;
								break;
							case 0:
								f = 30;
								break;
							case 1:
								f = 20;
								break;
							}
							f += ( dp[pi][j-1] + (-1)*(w[pi][j-1]) );
							mini = min (f, mini);
						}
					}
					dp[i][j] = mini;
				}
				else
					break;
		cout << dp[0][n] << endl << endl;
	}
	return 0;
}