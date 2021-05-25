#include <iostream>
#include <map>
#include <utility>
#include <cstring>

using namespace std;

int main ()
{
	int m, n, w, b, x, y, val, c, dir, life, tx, ty, res, sum;
	int mat[55][55];
	memset (mat, 0, sizeof mat);
	pair <int, int> pt[55][55];
	cin >> m >> n >> w >> b;
	for (int I = 0; I < b && cin >> x >> y >> val >> c; I++)
	{
		mat[x][y] = 1;
		pt[x][y].first = val;
		pt[x][y].second = c;
	}
	sum = 0;
	while (cin >> x >> y >> dir >> life)
	{
		res = 0;
		while (life > 1)
		{
			tx = x;
			ty = y;
			switch (dir)
			{
				case 0:
					tx++;
					break;
				case 1:
					ty++;
					break;
				case 2:
					tx--;
					break;
				default:
					ty--;
			}
			life--;
			if (tx > 1 && tx < m && ty > 1 && ty < n)
			{
				if (mat[tx][ty] == 1)
				{
					life -= pt[tx][ty].second;
					res += pt[tx][ty].first;
					dir--;
					if (dir == -1)
						dir = 3;
				}
				else
				{
					x = tx;
					y = ty;
				}
			}
			else
			{
				life -= w;
				dir--;
				if (dir == -1)
					dir = 3;
			}
		}
		sum += res;
		cout << res << endl;
	}
	cout << sum << endl;
	return 0;
}
