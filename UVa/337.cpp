#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int n, x, y, mode;
string str;
vector < string > v;
int lnsz[10];

void act (char ch)
{
	switch (ch)
	{
		case 'b':
			y = 0;
			break;
		case 'c':
			memset (lnsz, 0, sizeof lnsz);
			v = vector < string > (10, string (10, ' '));
			break;
		case 'd':
			if (x != 9)	x++;
			break;
		case 'e':
			lnsz[x] = y;
			v[x].erase(v[x].begin()+y, v[x].end());
			v[x] += string (10 - y, ' ');
			break;
		case 'h':
			x = y = 0;
			break;
		case 'i':
			mode = 1;
			break;
		case 'l':
			if (y)	y--;
			break;
		case 'o':
			mode = 0;
			break;
		case 'r':
			if (y != 9)	y++;
			break;
		case 'u':
			if (x)	x--;
			break;
	}
	return ;
}

int main()
{
	for (int t = 1; cin >> n && n; t++)
	{
		cin.ignore();
		v = vector < string > (10, string (10, ' '));
		memset (lnsz, 0, sizeof lnsz);
		mode = x = y = 0;
		for (int I = 0; I < n && getline(cin, str); I++)
			for (int J = 0; J < str.length(); J++)
				if (str[J] == '^' && str[J+1] != '^')
				{
					if (isdigit(str[J+1]))
					{
						x = str[J+1] - '0';
						y = str[J+2] - '0';
						J++;
					}
					else
						act (str[J+1]);
					J++;
				}
				else
				{
					if (str[J] == '^')	J++;
					if (!mode)
						v[x][y] = str[J];
					else if (lnsz[x] != 10)
					{
						lnsz[x]++;
						v[x].insert(v[x].begin()+y, str[J]);
					}
					if (y != 9)	y++;
				}

		cout << "Case " << t << endl;
		cout << '+';
		for (int J = 0; J < 10; J++)
			cout << '-';
		cout << '+' << endl;
		for (int J = 0; J < 10; J++)
		{
			cout << '|';
			for (int K = 0; K < 10; K++)
				cout << v[J][K];
			cout << '|' << endl;
		}
		cout << '+';
		for (int J = 0; J < 10; J++)
			cout << '-';
		cout << '+' << endl;
	}
	return 0;
}