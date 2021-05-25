#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdio>

using namespace std;

int n, Res;
int u, v;
string str;
int components;
int mark[100];
int deg[100];
int mat[100][100];

void dfs (int x)
{
	mark[x] = 1;
	for (int i = 1; i <= n; i++)
		if (!mark[i] && mat[x][i])
			dfs (i);
}

int main ()
{
	freopen ("Network.in", "r", stdin);
	while (cin >> n && n != 0)
	{
		Res = 0;
		for (int i = 0; i < n; i++)
			memset (mat[i], 0, sizeof mat[i]);
		memset (deg, 0, sizeof deg);
		while (getline (cin, str) && str != "0")
		{
			stringstream ss (str);
			ss >> u;
			while (ss >> v)
			{
				mat[u][v] = 1;	deg[u]++;
				mat[v][u] = 1;	deg[v]++;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			components = 0;
			memset (mark, 0, sizeof mark);
			mark[i] = 1;
			for (int j = 1; j <= n; j++)
				if (!mark[j] && deg[j] != 0)
				{
					dfs (j);
					components++;
				}
			if (components > 1)
				Res++;
		}
		cout << Res << endl;
	}
	return 0;
}