#include <iostream>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

int mat[100][100];
int mark[100];
int pos[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
int part, n, x, y;
bool b;
string str;

void dfs (int a, int b)
{
	mat[a][b] = -1;
	for (int i = 0; i < 4; i++)
	{
		int t1 = a + pos[i][0];
		int t2 = b + pos[i][1];
		if (t1 >= 0 && t1 < n && t2 >= 0 && t2 < n && mat[t1][t2] == part)
			dfs (t1, t2);
	}
}

int main ()
{
	while (cin >> n && n != 0)
	{
		for (int i = 0; i < n; i++)
			memset (mat[i], 0, sizeof mat[i]);
		memset (mark, 0, sizeof mark);
		getline (cin, str);
		for (int i = 1; i < n; i++)
		{
			getline (cin, str);
			stringstream ss (str);
			while (ss >> x >> y)
				mat[x-1][y-1] = i;
		}
		bool b = true;
		for (int i = 0; b && i < n; i++)
			for (int j = 0; j < n; j++)
				if (mat[i][j] >= 0)
				{
					part = mat[i][j];
					if (mark[part])
					{
						b = false;
						break;
					}
					else
					{
						mark[part]= 1;
						dfs (i, j);
					}
				}
		if (b)
			cout << "good" << endl;
		else
			cout << "wrong" << endl;
	}
	return 0;
}