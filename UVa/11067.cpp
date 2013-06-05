#include <iostream>
#include <cstring>

using namespace std;

long int dp[101][101];

int main ()
{
	int w, h, n, x, y;
	while (cin >> w >> h && w != 0 && h != 0 && cin >> n)
	{
		memset (dp, 0, sizeof dp);
		for (; n != 0 && cin >> x >> y; n--)
			dp[x][y] = -1;
		for (int i = 0; i <= w; i++)
			for (int j = 0; j <= h; j++)
				if (i == 0 && j == 0)
					dp[i][j] = 1;
				else
					if (dp[i][j] == -1)
						dp[i][j] = 0;
					else
					{
						int t1 = i - 1;
						int t2 = j - 1;
						if (t1 >= 0)
							dp[i][j] += dp[t1][j];
						if (t2 >= 0)
							dp[i][j] += dp[i][t2];
					}
		switch (dp[w][h])
		{
			case 1:
				cout << "There is one path from Little Red Riding Hood's house to her grandmother's house." << endl;
				break;
			case 0:
				cout << "There is no path." << endl;
				break;
			default:
				cout << "There are " << dp[w][h] << " paths from Little Red Riding Hood's house to her grandmother's house." << endl;
		}
	}
	return 0;
}