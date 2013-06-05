#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

int n, m, a, x, y, c, t, cmp, sz;
vector < pair < int, pair <int, int> > > edg;
int mark[10010];
long long res;

int find (int p)
{
	if (!mark[p])	return p;
	return mark[p] = find (mark[p]);
}

int main ()
{
	scanf ("%d", &t);
	for (int test = 1; test <= t; test++)
	{
		scanf ("%d%d%d", &n, &m, &a);
		edg.clear();
		cmp = n;
		res = 0;
		memset (mark, 0, sizeof mark);
		for (int I = 0; I < m; I++)
		{
			scanf ("%d%d%d", &x, &y, &c);
			pair < int, pair <int, int> > p (c, make_pair (x, y));
			edg.push_back (p);
		}
		sort (edg.begin(), edg.end());
		sz = edg.size();
		for (int I = 0; I < sz; I++)
		{
			x = edg[I].second.first;
			y = edg[I].second.second;
			c = edg[I].first;
			if (c >= a)
				break;
			if (find (x) != find (y))
			{
				mark[find (y)] = find (x);
				res += c;
				cmp--;
			}
		}
		res += cmp * a;
		printf ("Case #%d: %lld %d\n", test, res, cmp);
	}
	return 0;
}