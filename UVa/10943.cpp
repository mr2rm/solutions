#include <iostream>

using namespace std;

//dp1 ---> AC (Khaiam-Pascal)
//int dp1[200][200];

int dp2[101][101];

int main ()
{
	//dp2
	for (int i = 1; i < 101; i++)
		for (int j = 0; j < 101; j++)
			if (i == 1)
				dp2[i][j] = 1;
			else
			{
				int sum = 0;
				for (int k = 0; k <= j; k++)
					sum += dp2[i-1][k];
				dp2[i][j] = sum % 1000000;
			}

	/*//dp1
	for (int i = 0; i < 200; i++)
		for (int j = 0; j <= i; j++)
			if (j == 0 || i == j)
				dp1[i][j] = 1;
			else
			{
				int temp = dp1[i-1][j-1] + dp1[i-1][j];
				dp1[i][j] = (temp % 1000000);
			}
	*/
	int n, k;
	while (cin >> n >> k && n != 0 && k != 0)
	{
		/*//dp1
		int y = k - 1;
		int x = n + y;
		cout << dp1[x][y] << endl;
		*/

		//dp2
		cout << dp2[k][n] << endl;
	}
	return 0;
}