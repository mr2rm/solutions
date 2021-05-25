#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
int r, c, stars, res;
string str;
vector <string> mat;

void dfs (int x, int y)
{
	mat[x][y] = '.';
	stars++;
	for (int i = 0; i < 8; i++)
	{
		int tx = arr[i][0] + x;
		int ty = arr[i][1] + y;
		if (tx >= 0 && tx < r && ty >= 0 && ty < c && mat[tx][ty] == '*')
			dfs (tx, ty);
	}
}

int main ()
{
	while (cin >> r >> c && r != 0 && c != 0)
	{
		mat.clear ();
		for (int i = 0; i < r && cin >> str; i++)
			mat.push_back (str);
		res = 0;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				if (mat[i][j] == '*')
				{
					stars = 0;
					dfs (i, j);
					if (stars == 1)
						res++;
				}
		cout << res << endl;
	}
	return 0;
}

//adhoc ---> ACC
/*
int main ()
{
	int r, c;
	while (cin >> r >> c && r != 0 && c != 0)
	{
		vector <string> mat;
		string str;
		for (int i = 0; i < r && cin >> str; i++)
			mat.push_back (str);
		int res = 0;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				if (mat[i][j] == '*')
				{
					bool b = true;
					for (int k = 0; k < 8; k++)
					{
						int tr = i + arr[k][0];
						int tc = j + arr[k][1];
						if (tr >= 0 && tr < r && tc >= 0 && tc < c && mat[tr][tc] == '*')
						{
							b = false;
							break;
						}
					}
					if (b)
						res++;
				}
		cout << res << endl;
	}
	return 0;
}
*/