#include <iostream>
#include <sstream>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cstring>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>

#define eps 1e-6
using namespace std;

int skew (double x, double y)
{
	int tmp, t, res;
	tmp = 2*(x-1) / sqrt(3.);
	tmp++;
	t = y;
	if (y - t < 0.5)	t--;
	//cout << tmp << " " << t << endl;
	res = (int)(tmp/2) * (t + (int)y);
	if (tmp % 2)
		res += y;
	return res;
}

int main(void)
{
	double x, y;
	int res, grid;
	while (cin >> x >> y)
	{
		res = (int)x * (int)y;
		grid = res;
		if (x - eps >= 1. && y - eps >= 1.)
		{
			res = max (skew(x, y), res);
			res = max (skew(y, x), res);
		}
		cout << res;
		if (res == grid)
			cout << " grid" << endl;
		else
			cout << " skew" << endl;
	}
	return 0;
}
