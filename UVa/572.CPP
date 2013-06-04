#include <iostream>
#include <string.h>

using namespace std;

char mat[100][100];
int mark[100][100];
int arr[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
int r , c;
int component , counter;

void dfs (int x, int y)
{
	mark[x][y] = 1;
	counter++;
	for (int i = 0; counter <= 100 && i < 8; i++)
	{
		int nx = x + arr[i][0];
		int ny = y + arr[i][1];
		if ((nx >= 0 && ny >= 0 && nx < r && ny < c) && mat[nx][ny] == '@' && mark[nx][ny] == 0)
			dfs (nx, ny);
	}
}

int main ()
{
	//freopen ( "Oil Deposits.in" , "r" , stdin );
	while (cin >> r >> c && r != 0)
	{
		component = 0;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				cin >> mat[i][j];
		for (int i = 0; i < r; i++)
			memset (mark[i], 0, sizeof mark[i]);
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				if (mat[i][j] == '@' && mark[i][j] == 0)
				{
					counter = 0;
					dfs (i, j);
					component++;
				}
		cout << component << endl;
	}
	return 0;
}