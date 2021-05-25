#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector < string > empty (8, string (8, '.'));
vector < string > v;
int dir[8][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};

bool check (char ch, int upper, int sel)
{
	switch (sel)
	{
		case 0:
			if (!upper) {if (ch == 'Q' || ch == 'R')	return true;}
			else if (ch == 'q' || ch == 'r')	return true;
			break;
		case 1:
			if (!upper) {if (ch == 'Q' || ch == 'B')	return true;}
			else if (ch == 'q' || ch == 'b')	return true;
			break;
		case 2:
			if (!upper) {if (ch == 'N') return true;}
			else if (ch == 'n')	return true;
	}
	return false;
}

bool fun (int a, int b, int upper)
{
	int I, J, tx, ty;
	for (I = b+1; I < 8 && v[a][I] == '.'; I++);
	if (I != 8 && check (v[a][I], upper, 0))	return true;
	for (I = b-1; I >= 0 && v[a][I] == '.'; I--);
	if (I != -1 && check (v[a][I], upper, 0))	return true;
	for (I = a+1; I < 8 && v[I][b] == '.'; I++);
	if (I != 8 && check (v[I][b], upper, 0))	return true;
	for (I = a-1; I >= 0 && v[I][b] == '.'; I--);
	if (I != -1 && check (v[I][b], upper, 0))	return true;
	for (I = a-1, J = b-1; I >= 0 && J >= 0 && v[I][J] == '.'; I--, J--);
	if (I != -1 && J != -1)
	{
		if (I == a-1 && J == b-1 && upper && v[I][J] == 'p')	return true;
		if (check (v[I][J], upper, 1))	return true;
	}
	for (I = a-1, J = b+1; I >= 0 && J < 8 && v[I][J] == '.'; I--, J++);
	if (I != -1 && J != 8)
	{
		if (I == a-1 && J == b+1 && upper && v[I][J] == 'p')	return true;
		if (check (v[I][J], upper, 1))	return true;
	}
	for (I = a+1, J = b-1; I < 8 && J >= 0 && v[I][J] == '.'; I++, J--);
	if (I != 8 && J != -1)
	{
		if (I == a+1 && J == b-1 && !upper && v[I][J] == 'P')	return true;
		if (check (v[I][J], upper, 1))	return true;
	}
	for (I = a+1, J = b+1; I < 8 && J < 8 && v[I][J] == '.'; I++, J++);
	if (I != 8 && J != 8)
	{
		if (I == a+1 && J == b+1 && !upper && v[I][J] == 'P')	return true;
		if (check (v[I][J], upper, 1))	return true;
	}
	for (int I = 0; I < 8; I++)
	{
		tx = a + dir[I][0];
		ty = b + dir[I][1];
		if (tx >= 0 && tx < 8 && ty >= 0 && ty < 8 && check (v[tx][ty], upper, 2))
			return true;
	}
	return false;
}

int main ()
{
	bool b;
	string str;
	for (int t = 1; cin >> str; t++)
	{
		b = false;
		v.clear();
		v.push_back (str);
		for (int I = 0; I < 7 && cin >> str; I++)
			v.push_back (str);
		if (v == empty)	break;
		cout << "Game #" << t << ": ";
		for (int I = 0; I < 8; I++)
			for (int J = 0; J < 8; J++)
				if (v[I][J] == 'k' && fun (I, J, 0))
				{
					b = true;
					cout << "black king is in check." << endl;
					break;
				}
				else if (v[I][J] == 'K' && fun (I, J, 1))
				{
					b = true;
					cout << "white king is in check." << endl;
					break;
				}
		if (!b)	cout << "no king is in check." << endl;
	}
	return 0;
}
