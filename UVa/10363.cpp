#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool x, o, res;
char mat[3][3];
int t, cntx, cnto;

void win ()
{
	for (int I = 0; I < 3; I++)
	{
		if (mat[I][0] == mat[I][1] && mat[I][1] == mat[I][2])
			if (mat[I][0] == 'X')
				x = true;
			else if (mat[I][0] == 'O')
				o = true;
		if (mat[0][I] == mat[1][I] && mat[1][I] == mat[2][I])
			if (mat[0][I] == 'X')
				x = true;
			else if (mat[0][I] == 'O')
				o = true;
	}
	if (mat[0][0] == mat[1][1] && mat[1][1] == mat[2][2])
		if (mat[1][1] == 'X')
			x = true;
		else if (mat[1][1] == 'O')
			o = true;
	if (mat[2][0] == mat[1][1] && mat[1][1] == mat[0][2])
		if (mat[1][1] == 'X')
			x = true;
		else if (mat[1][1] == 'O')
			o = true;
}

int main ()
{
	for (cin >> t; t; t--)
	{
		cntx = cnto = 0;
		x = o = false;
		for (int I = 0; I < 3; I++)
			for (int J = 0; J < 3; J++)
			{
				cin >> mat[I][J];
				if (mat[I][J] == 'X')
					cntx++;
				else if (mat[I][J] == 'O')
					cnto++;
			}
		win ();
		res = true;
		if (x && o)
			res = false;
		else if (x)
		{
			if (cntx-1 != cnto)
				res = false;
		}
		else if (o)
		{
			if (cntx != cnto)
				res = false;
		}
		else if (!(cntx == cnto || cntx-1 == cnto))
			res = false;
		if (res)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}