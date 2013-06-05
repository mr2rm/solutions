#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

int main ()
{
	int n, k, m;
	int sum, off_1, off_2;
	int ts_1, ts_2;
	int x, y;
	int mark[20];
	while (cin >> n >> k >> m && n+k+m)
	{
		memset (mark, 0, sizeof mark);
		sum = 0;
		off_1 = 1;
		off_2 = n;
		while (sum < n)
		{
			for (ts_1 = 0; ts_1 < k; off_1 = (off_1 == n ? 1 : off_1 + 1))
			{
				if (!mark[off_1])
					ts_1++;
				if (ts_1 == k)
					x = off_1;
			}
			for (ts_2 = 0; ts_2 < m; off_2 = (off_2 == 1 ? n : off_2 - 1))
			{
				if (!mark[off_2])
					ts_2++;
				if (ts_2 == m)
					y = off_2;
			}
			if (x == y)
			{
				mark[x] = 1;
				sum++;
				printf("%3d", x);
			}
			else
			{
				mark[x] = mark[y] = 1;
				sum += 2;
				printf ("%3d%3d", x, y);
			}
			if (sum == n)
				cout << endl;
			else
				cout << ",";
		}
	}
	return 0;
}
