#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

int b, w, d;
int x, y;
int tx, ty;
vector <string> maze;
vector < vector <int> > mat;
string str;
int dir[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int rcell[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int res[5];

bool iswall (int _x, int _y)
{
	if (_x >= 0 && _x < b && _y >= 0 && _y < w)
		if (maze[_x][_y] == '1')
			return true;
		else return false;
	else return true;
}

int main ()
{
	while (cin >> b >> w && b && w)
	{
		maze.clear();
		mat = vector < vector <int> > (b, vector <int> (w, 0));
		memset (res, 0, sizeof res);
		for (int I = 0; I < b; I++)
		{
			cin >> str;
			maze.push_back (str);
		}
		d = 0;
		x = b-1;
		y = 0;
		do
		{
			tx = x + dir[d][0];
			ty = y + dir[d][1];
			if (tx >= 0 && tx < b && ty >= 0 && ty < w && maze[tx][ty] == '0')
			{
				if (iswall(tx+rcell[d][0], ty+rcell[d][1]) || (tx == b-1 && ty == 0))
				{
					x = tx;
					y = ty;
				}
				else
				{	
					mat[tx][ty]++;
					x = tx + rcell[d][0];
					y = ty + rcell[d][1];
					d--;
					if (d == -1)
						d = 3;
				}
				mat[x][y]++;
				//cout << x << " " << y << " " << d << endl;
			}
			else
			{
				do
				{
					d++;
					d %= 4;
				}
				while (!iswall(x+rcell[d][0], y+rcell[d][1]));
			}
		}
		while (!(x == b-1 && y == 0 && mat[x][y] == 1));
		for (int I = 0; I < b; I++)
			for (int J = 0; J < w; J++)
				if (mat[I][J] || maze[I][J] == '0')
					res[mat[I][J]]++;
		for (int I = 0; I < 5; I++)
			printf ("%3d", res[I]);
		cout << endl;
	}
	return 0;
}