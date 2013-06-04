#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int mat[101][101];
int mark[101];
int n, r, o, c, t;

void dfs (int x)
{
	for (int i = 1; i <= n; i++)
		if (mat[x][i] == 1 && mark[i] == 0)
		{
			mark[i] = 1;
			dfs (i);
		}
}

int main()
{
	//freopen ("Vertex.in", "r", stdin);
	while (cin >> n && n !=0)
	{
		for (int i = 1; i <= n; i++)
			memset (mat[i], 0, sizeof mat[i]);
		while (cin >> r && r != 0)
			while (cin >> o && o != 0)
				mat[r][o] = 1;
		cin >> c;
		for (; c != 0 && cin >> t; c--)
		{
			vector <int> v;
			memset (mark, 0, sizeof mark);
			dfs (t);
			for (int i = 1; i <= n; i++)
				if (mark[i] == 0)
					v.push_back (i);
			cout << v.size();
			for (int i = 0; i < v.size(); i++)
				cout << " " << v[i];
			cout << endl;
		}
	}
	return 0;
}