#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int h, w, components;
int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int mark[50][50];
int markX[50][50];
vector <string> image (50);

void dfsX (int x, int y)
{
	markX[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int tx = x + arr[i][0];
		int ty = y + arr[i][1];
		if (tx >= 0 && tx < h && ty >= 0 && ty < w && image[tx][ty] == 'X' && !markX[tx][ty])
			dfsX (tx, ty);
	}
}

void dfs (int x, int y)
{
	if (image[x][y] == 'X' && !markX[x][y])
	{
		dfsX (x, y);
		components++;
	}
    mark[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int tx = x + arr[i][0];
		int ty = y + arr[i][1];
		if (tx >= 0 && tx < h && ty >= 0 && ty < w && image[tx][ty] != '.'&& !mark[tx][ty])
			dfs (tx, ty);
	}
}

int main ()
{
	int t = 0;
	while (cin >> w >> h && w != 0 && h != 0)
	{
		for (int i = 0; i < h; i++)
		{
			cin >> image[i];
			memset (mark[i], 0, sizeof mark[i]);
			memset (markX[i], 0, sizeof markX[i]);
		}
		vector <int> Res;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (image[i][j] != '.' && !mark[i][j])
				{
					components = 0;
					dfs (i, j);
					Res.push_back (components);
				}
		sort (Res.begin(), Res.end());
		t++;
		cout << "Throw " << t << endl;
		if (Res.size() == 0)
			Res.push_back (0);
		for (int i = 0; i < Res.size(); i++)
		{
			if (i > 0)
				cout << " ";
			cout << Res[i];
		}
		cout << endl << endl;
	}
	return 0;
}
