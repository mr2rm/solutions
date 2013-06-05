#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int mark[2500][2500];

int main ()
{
	int w, h, n;
	int x1, y1, x2, y2;
	int minx, miny, maxx, maxy;
	int res;
	while (cin >> w >> h >> n && n+h+w)
	{
		res = 0;
		memset (mark, 0, sizeof mark);
		for (int I = 0; I < n; I++)
		{
			cin >> x1 >> y1;
			cin >> x2 >> y2;
			minx = min (x1, x2);	maxx = max (x1, x2);
			miny = min (y1, y2);	maxy = max (y1, y2);
			for (int i = minx-1; i < maxx; i++)
				for (int j = miny-1; j < maxy; j++)
					mark[i][j] = 1;
		}
		for (int I = 0; I < w; I++)
			for (int J = 0; J < h; J++)
				if (!mark[I][J])
					res++;
		switch (res)
		{
			case 0:
				cout << "There is no empty spots." << endl;
				break;
			case 1:
				cout << "There is one empty spot." << endl;
				break;
			default:
				cout << "There are " << res << " empty spots." << endl;
		}
	}
	return 0;
}

