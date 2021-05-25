#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int dp[101][10][1024];
int res;

int main ()
{
	memset (dp, 0, sizeof dp);
	
	for (int j = 1; j <= 9; j++)
		dp[1][j][1<<j] = 1;
	
	for (int i = 1; i < 100; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 1; k < 1024; k++)
			{
				int nx = j+1;
				int pr = j-1;
				if (nx < 10)
				{
					res = dp[i+1][nx][k|(1<<nx)];
					dp[i+1][nx][k|(1<<nx)] = (res + dp[i][j][k]) % 1000000007;
				}
				if (pr >= 0)
				{
					res = dp[i+1][pr][k|(1<<pr)];
					dp[i+1][pr][k|(1<<pr)] = (res + dp[i][j][k]) % 1000000007;
				}
			}
			
	int n, m, t;
	cin >> t;
	for (; t != 0 && cin >> n >> m; t--)
	{
		res = 0;
		int all = (int)pow (2., n) - 1;
		for (int i = n; i <= m; i++)
			for (int j = 0; j < n; j++)
				res = (res + dp[i][j][all]) % 1000000007;
		cout << res << endl;
	}
	return 0;
}
