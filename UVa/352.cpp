#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int n, t, component;
vector <string> mat ( 25 );
int mark[25][25];
int arr[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

void dfs (int x, int y)
{
	mark[x][y] = 1;
	for (int i = 0; i < 8; i++)
	{
		int nx = x + arr[i][0];
		int ny = y + arr[i][1];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n && mat[nx][ny] == '1' && mark[nx][ny] == 0)
			dfs (nx, ny);
	}
}

int main()
{
	//freopen ("The Seasonal War.in", "r", stdin);
	t = 0;
	while (cin >> n)
	{
		t++;
		component = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> mat[i];
			memset (mark[i], 0, sizeof mark[i]);
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (mat[i][j] == '1' && mark[i][j] == 0)
				{
					dfs ( i , j );
					component++;
				}
		cout << "Image number " << t << " contains " << component << " war eagles." << endl;
	}
	return 0;
}