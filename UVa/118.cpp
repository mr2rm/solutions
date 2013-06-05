#include <iostream>
#include <string>
#include <cstring>
#include <utility>
#include <map>

using namespace std;

int mat[51][51];
string orientation = "NESW";
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m, tx, ty;
char ori;
map < pair <char, char>, char > mp_turn;
map < char, pair <char, char> > mp_move;
string str;

void do_map ()
{
	int tmp;
	for (int I = 0; I < 4; I++)
	{
		tmp = I - 1;
		if (tmp == -1)	tmp = 3;
		mp_turn[make_pair(orientation[I], 'L')] = orientation[tmp];
		tmp = I + 1;
		tmp %= 4;
		mp_turn[make_pair(orientation[I], 'R')] = orientation[tmp];
		mp_move[orientation[I]] = make_pair (dir[I][0], dir[I][1]);
	}
}

int main()
{
	do_map();
	memset (mat, 0, sizeof mat);
	cin >> n >> m;
	pair <int, int> pos;
	bool is_off;
	while (cin >> pos.first >> pos.second >> ori >> str)
	{
		is_off = false;
		for (int I = 0; I < (int)str.length(); I++)
			if (str[I] == 'F')
			{
				tx = pos.first + mp_move[ori].first;
				ty = pos.second + mp_move[ori].second;
				if (tx >= 0 && tx <= n && ty >= 0 && ty <= m)
				{
					pos.first = tx;
					pos.second = ty;
				}
				else if (!mat[pos.first][pos.second])
				{
					mat[pos.first][pos.second] = 1;
					is_off = true;
					break;
				}
			}
			else
				ori = mp_turn[make_pair(ori, str[I])];
		cout << pos.first << " " << pos.second << " " << ori;
		if (is_off)
			cout << " LOST";
		cout << endl;
	}
	return 0;
}
