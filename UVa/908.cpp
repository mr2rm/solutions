#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <cstring>

using namespace std;

int n, k, m, x, y, c;
long long res1, res2, sz;
vector < pair < int, pair <int, int> > > edg;
int par[1000001];

int find (int p)
{
	if (!par[p])	return p;
	return par[p] = find (par[p]);
}

int main ()
{
	for (int t = 0; cin >> n; t++)
	{
		res2 = res1 = 0;
		edg.clear();	
		memset (par, 0, sizeof par);
		for (int I = 0; I < n-1; I++)
		{
			scanf ("%d%d%d", &x, &y, &c);
			res1 += c;
		}
		scanf ("%d", &k);
		for (int I = 0; I < k; I++)
		{
			scanf ("%d%d%d", &x, &y, &c);
			pair < int, pair <int, int> > p (c, make_pair (x, y));
			edg.push_back (p);
		}
		scanf ("%d", &m);
		for (int I = 0; I < m; I++)
		{
			scanf ("%d%d%d", &x, &y, &c);
			pair < int, pair <int, int> > p (c, make_pair (x, y));
			edg.push_back (p);
		}
		sort (edg.begin(), edg.end());
		sz = (long long)edg.size();
		for (long long I = 0; I < sz; I++)
		{
			c = edg[I].first;
			x = edg[I].second.first;
			y = edg[I].second.second;
			if (find (x) != find (y))
			{
				par[find (y)] = find (x);
				res2 += c;
			}
		}
		if (t)	cout << endl;
		printf ("%lld\n%lld\n", res1, res2);
	}
	return 0;
}