#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

struct edge
{
	int p, q, w;
	edge (int _p = 0, int _q = 0, int _w = 0)
	{
		p = _p;
		q = _q;
		w = _w;
	}
	bool operator < (const edge x) const
	{
		return w < x.w;
	}
};

int m, n;
int mst, sum;
vector <edge> e;
vector <int> nd (200000);

int find (int x)
{
	if (nd[x] == x)
		return x;
	return nd[x] = find (nd[x]);
}

void merge (int x, int y)
{
	nd[find (x)] = find (y);
}

int main()
{
	//freopen ("MST.in", "r", stdin);
	while (cin >> m >> n && m != 0)
	{
		e.clear();
		mst = 0;
		sum = 0;
		for (int i = 0; i < m; i++)
			nd[i] = i;
		for (int i = 0; i < n; i++)
		{
			edge te;
			cin >> te.p >> te.q >> te.w;
			e.push_back (te);
		}
		sort (e.begin(), e.end());
		for (int i = 0; i < n; i++)
		{
			sum += e[i].w;
			if (find (e[i].p) != find (e[i].q))
			{
				merge (find(e[i].p), find (e[i].q));
				mst += e[i].w;
			}
		}
		cout << sum - mst << endl;
	}
	return 0;
}