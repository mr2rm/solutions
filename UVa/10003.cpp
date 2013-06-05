#include <iostream>
#include <algorithm>

using namespace std;

int cuts[52];
int dp[52][52];

int main ()
{
	int l, n;
	while (cin >> l && l != 0 && cin >> n)
	{
		cuts[0] = 0;
		cuts[n+1] = l;
		for (int i = 1; i <= n && cin >> cuts[i]; i++);
		for (int jj = 1; jj < n+2; jj++)
			for (int i = 0, j = jj; j < n+2; j++, i++)
				if (j - 1 == i)
					dp[i][j] = 0;
				else
				{
					dp[i][j] = cuts[j] - cuts[i];
					int mini = 5000;
					for (int k = i + 1; k < j; k++)
						mini = min (mini, dp[i][k] + dp[k][j]);
					dp[i][j] += mini;
				}
		cout << "The minimum cutting is " << dp[0][n+1] << ".\n";
	}
	return 0;
}