#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string str;
vector <string> v;
int res, cells;
int tx, ty;
int n, m;
int arr[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

void dfs (int x, int y)
{
	v[x][y] = '0';
	cells++;
	for (int i = 0; i < 8; i++)
	{
		tx = x + arr[i][0];
		ty = y + arr[i][1];
		if (tx >= 0 && tx < n && ty >= 0 && ty < m && v[tx][ty] == '1')
			dfs (tx, ty);
	}
}

int main ()
{
	int t;
	cin >> t;
	cin.ignore();
	getline (cin, str);
	for (int i = 0; i < t; i++)
	{
		v.clear();
		while (getline(cin, str) && str != "")
			v.push_back (str);
		n = v.size();
		m = v[0].length();
		res = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (v[i][j] == '1')
				{
					cells = 0;
					dfs (i, j);
					res = max (res, cells);
				}
		cout << res << endl;
		if (i != t-1)
			cout << endl;
	}
	return 0;
}