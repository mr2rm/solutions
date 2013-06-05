#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
#include <string>
#include <cstdio>

using namespace std;

int markc[9];
int markr[9];
set <string> s;
string str (9, 'X');

void queen (int row)
{
	if (row == 9)
	{
		s.insert (str);
		return;
	}
	if (markr[row] == 0)
	{
		markr[row] = 1;
		for (int i = 1; i < 9; i++)
			if (markc[i] == 0)
			{
				bool mov = false;
				for (int j = 1; j < 9; j++)
					if (markc[j] != 0 && abs((str[j]-'0')-row) == abs(i-j))
					{
						mov = true;
						break;
					}
				if (!mov)
				{
					markc[i] = 1;
					str[i] = ('0' + row);
					queen (row+1);
					markc[i] = 0;
				}
			}
		markr[row] = 0;
	}
	else
		queen (row+1);
}

int main ()
{
	int t;
	int x, y;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		memset (markc, 0, sizeof markc);
		memset (markr, 0, sizeof markr);
		s.clear ();
		cin >> x >> y;
		markr[x] = -1;
		markc[y] = -1;
		str[y] = ('0' + x);
		cout << "SOLN       COLUMN" << endl;
		cout << " #      1 2 3 4 5 6 7 8" << endl;
		cout << endl;
		queen (1);
		int sol = 1;
		for (set <string>::iterator it = s.begin(); it != s.end(); it++)
		{
			printf ("%2d     ", sol++);
			string s = *it;
			for (int i = 1; i <= 8; i++)
			{
				cout << " ";
				cout << s[i];
			}
			cout << endl;
		}
		if (i != t)
			cout << endl;
	}
	return 0;
}