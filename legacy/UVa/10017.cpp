#include <iostream>
#include <vector>

using namespace std;

vector < vector <int> > peg (3);
int numdisk, nummove, sz;
int test = 0;

void print()
{
	cout << endl <<"A=>";
	for (int I = 0; I < peg[0].size(); I++)
	{
		if (!I)	
			cout << "  ";
		cout << " " << peg[0][I];
	}
	cout << endl << "B=>";
	for (int I = 0; I < peg[1].size(); I++)
	{
		if (!I)	
			cout << "  ";
		cout << " " << peg[1][I];
	}
	cout << endl << "C=>";
	for (int I = 0; I < peg[2].size(); I++)
	{
		if (!I)	
			cout << "  ";
		cout << " " << peg[2][I];
	}
	cout << endl;
}

void hanoi (int disk, int start, int end)
{
	if (!nummove)
		return;
	if (disk == 1)
	{
		sz = peg[start].size()-1;
		peg[end].push_back(peg[start][sz]);
		peg[start].pop_back();
		nummove--;
		print();
	}
	else
	{
		int with;
		for (int I = 0; I < 3; I++)
			if (I != start && I != end)
			{
				with = I;
				break;
			}
		hanoi (disk-1, start, with);
		hanoi (1, start, end);
		hanoi (disk-1, with, end);
	}
}

int main ()
{
	while (cin >> numdisk >> nummove && numdisk)
	{
		test++;
		for (int I = 0; I < 3; I++)
		{
			peg[I].clear();
			if (!I)
				for (int J = numdisk; J > 0; J--)
					peg[I].push_back(J);	
		}
		cout << "Problem #" << test << endl;
		print();
		hanoi (numdisk, 0, 2);
		cout << endl;
	}
	return 0;
}