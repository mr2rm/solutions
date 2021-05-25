#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector <string> mat;
int mark[250][250];
string str, name;
int m, n;
int x_1, y_1, x_2, y_2;
int tx, ty;
char c, t, rc;
int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int x, int y)
{
	mark[x][y] = 1;
	mat[x][y] = c;
	for (int i = 0; i < 4; i++)
	{
		tx = x + arr[i][0];
		ty = y + arr[i][1];
		if (tx >= 0 && tx < n && ty >= 0 && ty < m && !mark[tx][ty] && mat[tx][ty] == rc)
			dfs (tx, ty);
	}
}

int main ()
{
	while (getline (cin, str) && str != "X")
	{
		stringstream ss (str);
		if (str.length())
		{
			ss >> t;
			switch (t)
			{
			case 'I':
				{
					ss >> m;	ss >> n;
					mat = vector <string> (n, string (m, 'O'));
				}
				break;
			case 'C':
				mat = vector <string> (n, string (m, 'O'));
				break;
			case 'L':
				{
					ss >> y_1;	ss >> x_1;	ss >> c;
					mat[x_1 - 1][y_1 - 1] = c;
				}
				break;
			case 'V':
				{
					ss >> y_1;	ss >> x_1;	ss >> x_2;	ss >> c;
					if (x_1 > x_2)
						swap (x_1, x_2);
					for (int i = x_1; i <= x_2; i++)
						mat[i-1][y_1 - 1] = c;
				}
				break;
			case 'H':
				{
					ss >> y_1;	ss >> y_2;	ss >> x_1;	ss >> c;
					if (y_1 > y_2)
						swap (y_1, y_2);
					for (int i = y_1; i <= y_2; i++)
						mat[x_1 - 1][i-1] = c;
				}
				break;
			case 'K':
				{
					ss >> y_1;	ss >> x_1;	ss >> y_2;	ss >> x_2;	ss >> c;
					for (int i = x_1; i <= x_2; i++)
						for (int j = y_1; j <= y_2; j++)
							mat[i-1][j-1] = c;
				}
				break;
			case 'F':
				{
					ss >> y_1;	ss >> x_1;	ss >> c;
					memset (mark, 0, sizeof mark);
					rc = mat[x_1 - 1][y_1 - 1];
					dfs (x_1 - 1, y_1 - 1);
				}
				break;
			case 'S':
				{
					ss >> name;
					cout << name << endl;
					for (int i = 0; i < n; i++)
						cout << mat[i] << endl;
				}
				break;
			}
		}
	}
	return 0;
}