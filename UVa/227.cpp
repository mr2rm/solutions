#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main ()
{
	vector <string> mat;
	string str;
	bool b, f;
	int x, y, tx, ty;
	for (int t = 1; getline(cin, str) && str != "Z"; t++)
	{
		mat.clear();
		mat.push_back(str);
		f = b = false;
		x = 0;
		for (int I = 0; I < 5 && !b; I++)
			if (str[I] == ' ')
			{
				y = I;
				b = true;
			}
		for (int I = 1; I < 5 && getline (cin, str); I++)
		{
			mat.push_back(str);
			for (int J = 0; J < 5 && !b; J++)
					if (str[J] == ' ')
					{
						x = I;
						y = J;
						b = true;
					}
		}
		while (getline(cin, str))
		{
			for (int I = 0; I < str.length() && !f; I++)
			{
				tx = x;
				ty = y;
				switch (str[I])
				{
					case 'A':
						tx--;
						break;
					case 'B':
						tx++;
						break;
					case 'R':
						ty++;
						break;
					case 'L':
						ty--;
						break;
				}
				if (tx >= 0 && tx < 5 && ty >= 0 && ty < 5)
				{
					swap (mat[tx][ty], mat[x][y]);
					x = tx;
					y = ty;
				}
				else
					f = true;
			}
			if (str.length() && str[str.length()-1] == '0')
				break;
		}
		if (t != 1)
			cout << endl;
		cout << "Puzzle #" << t << ":" << endl;
		if (f)
			cout << "This puzzle has no final configuration." << endl;
		else
		{
			for (int I = 0; I < 5; I++)
				for (int J = 0; J < 5; J++)
				{
					cout << mat[I][J];
					if (J != 4)
						cout << " ";
					else
						cout << endl;
				}
		}
	}
	return 0;
}