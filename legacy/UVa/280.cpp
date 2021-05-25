#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/*
int n, s, x, t, cnt;
int mat[110][110], mark[110];

void dfs (int node)
{
	for (int I = 1; I <= n; I++)
		if (mat[node][I] && !mark[I])
		{
			cnt++;
			mark[I] = 1;
			dfs (I);
		}
}

int main ()
{
	while (cin >> n && n)
	{
		memset (mat, 0, sizeof mat);
		while (cin >> s && s)
			while (cin >> x && x)
				mat[s][x] = 1;
		cin >> t;
		for (int I = 0; I < t && cin >> x; I++)
		{
			memset (mark, 0, sizeof mark);
			cnt = 0;
			dfs (x);
			cnt = n - cnt;
			cout << cnt;
			for (int J = 1; J <= n; J++)
				if (!mark[J])
					cout << " " << J;
			cout << endl;
		}
	}
	return 0;
}
*/

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