#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int coin[6] = {5, 10, 20, 50, 100, 200};
int dp1[501] = {-1};
int n, p, mini, tm, temp, sum;
string str;

int main ()
{
	dp1[0] = 0;
	for (int i = 5; i < 501; i += 5)
	{
		mini = 1000;
		for (int j = 0; j < 6 && i >= coin[j]; j++)
		{
			tm = i - coin[j];
			mini = min (mini, dp1[tm]);
		}
		dp1[i] = mini + 1;
	}
	while (1)
	{
		vector <int> v;
		for (int i = 0; i < 6 && cin >> n; i++)
			for (; n > 0; n--)
				v.push_back (coin[i]);

		sum = v.size();
		if (!sum)
			break;
		cin >> str;
		p = (str[0] - '0') * 100;
		for (int i = 2; i < str.length(); i++)
			if (i == 2)
				p += (str[i] - '0') * 10;
			else
				p += (str[i] - '0');
		vector < vector <int> > dp2 (sum, vector <int> (501, -1));
		dp2[0][v[0]] = 1;
		dp2[0][0] = 0;
		temp = v[0];
		for (int i = 1; i < sum; i++)
		{
			temp += v[i];
			for (int j = 0; j <= temp && j <= 500; j+= 5)
				if (j == 0)
					dp2[i][j] = 0;
				else
				{
					int t1 = dp2[i-1][j];
					tm = j - v[i];
					int t2 = tm < 0 ? -1 : dp2[i-1][tm];
					if (t1 != -1)
						dp2[i][j] = t1;
					if (t2 != -1)
					{
						t2++;
						dp2[i][j] = dp2[i][j] != -1 ? min (dp2[i][j], t2) : t2;
					}
				}
		}
		mini = 1000;
		for (int j = p; j <= 500 && j <= temp; j += 5)
			if (dp2[sum-1][j] != -1)
			{
				tm = j - p;
				mini = min (mini, dp2[sum-1][j] + dp1[tm]);
			}
		printf ("%3d\n", mini);
	}
	return 0;
}