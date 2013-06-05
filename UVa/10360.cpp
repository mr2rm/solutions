#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>

using namespace std;

struct three
{
	pair <int, int> p;
	int size;
	three(pair <int, int> _p = make_pair(0, 0), int _size = 0)
	{
		p.first = _p.first;
		p.second = _p.second;
		size = _size;
	}
	bool operator < (const three &sec)const
	{
		return p < sec.p;
	}
};

int senario, maxrat;
int d, n;
int x, y, rat;
int sx, ex, sy, ey;
pair <int, int> start, endi, res;
int mat[1026][1026];

int main ()
{
	for(cin >> senario; senario; senario--)
	{
		cin >> d >> n;
		vector <three> ratpop(n);
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			ratpop[i].p = make_pair(x, y);
			cin >> ratpop[i].size;
		}
		sort (ratpop.begin(), ratpop.end());
		start = ratpop[0].p;
		endi = ratpop[n-1].p;
		memset (mat, 0, sizeof mat);
		for (int i = 0; i < n; i++)
		{
			sx = ratpop[i].p.first-d;
			if (sx < 0)
				sx = 0;
			ex = ratpop[i].p.first+d;
			if (ex > 1024)
				ex = 1024;
			sy = ratpop[i].p.second-d;
			if (sy < 0)
				sy = 0;
			ey = ratpop[i].p.second+d;
			if (ey > 1024)
				ey = 1024;
			rat = ratpop[i].size;
			for (int I = sx; I <= ex; I++)
				for (int J = sy; J <= ey; J++)
					mat[I][J] += rat;
		}
		maxrat = -1;
		sx = start.first-d;	ex = endi.first+d;
		if (sx < 0)
			sx = 0;
		if (ex > 1024)
			ex = 1024;
		for (int i = sx; i <= ex; i++)
			for (int j = 0; j < 1025; j++)
				if (mat[i][j] > maxrat)
				{
					maxrat = mat[i][j];
					res.first = i;
					res.second = j;
				}
		cout << res.first << " " << res.second << " " << maxrat << endl;
	}
	return 0;
}

/*//TLE
int main ()
{
	int sumrat;
	for (cin >> senario; senario && cin >> d >> n; senario--)
	{
		vector <three> ratpop (n);
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			ratpop[i].p = make_pair(x, y);
			cin >> ratpop[i].size;
		}
		sort (ratpop.begin(), ratpop.end());
		start = ratpop[0].p;
		end = ratpop[n-1].p;
		maxrat = -1;
		for (int i = start.first; i <= end.first; i++)
			for (int j = 0; j <= 1024; j++)
			{
				sumrat = 0;
				for (int k = 0; k < n; k++)
					if (max(abs(i-ratpop[k].p.first), abs(j-ratpop[k].p.second)) <= d)
						sumrat += ratpop[k].size;
				if (sumrat > maxrat)
				{
					res.first = i;
					res.second = j;
					maxrat = sumrat;
				}
			}
		cout << res.first << " " << res.second << " " << maxrat << endl;
	}
	return 0;
}
*/