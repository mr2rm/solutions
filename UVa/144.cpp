#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

int main ()
{
	int n, k, lim, rem, x;
	int grant[30];
	while (cin >> n >> k && n + k)
	{
		memset (grant, 0, sizeof grant);
		queue <int> q;
		for (int I = 1; I <= n; I++)
			q.push (I);
		rem = lim = 0;
		while (!q.empty())
		{
			x = q.front();
			q.pop();
			if (rem)
			{
				if (rem < 40 - grant[x])
				{
					grant[x] += rem;
					rem = 0;
					q.push(x);
				}
				else
				{
					rem -= 40 - grant[x];
					grant[x] = 40;
					printf ("%3d", x);
				}
			}
			else
			{
				lim = (lim % k) + 1;
				if (lim < 40 - grant[x])
				{
					grant[x] += lim;
					q.push(x);
				}
				else
				{
					rem += lim - (40 - grant[x]);
					grant[x] = 40;
					printf ("%3d", x);
				}
			}
		}
		cout << endl;
	}
	return 0;
}
