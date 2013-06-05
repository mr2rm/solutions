#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

string str1 = "CDSH";
string str2 = "23456789TJQKA";
map <char, int> mp1, mp2;
string dir = "NESW";
char ch;
int nx, ind;
string mat[4][13];
string str, s;

bool cmp (string st1, string st2)
{
	if (mp1[st1[0]] != mp1[st2[0]])
		return mp1[st1[0]] < mp1[st2[0]];
	return mp2[st1[1]] < mp2[st2[1]];
}

int main ()
{
	for (int I = 0; I < str1.length(); I++)
		mp1[str1[I]] = I;
	for (int J = 0; J < str2.length(); J++)
		mp2[str2[J]] = J;
	while (cin >> ch && ch != '#')
	{
		for (int I = 0; I < 4; I++)
			if (ch == dir[I])
			{
				nx = I+1;
				nx %= 4;
				break;
			}
		ind = 0;
		cin >> str >> s;
		str = str + s;
        for (int J = 0; J < str.length(); J += 2, nx++, nx %= 4)
        {
            s = string (str.begin()+J, str.begin()+J+2);
            mat[nx][ind] = s;
            if (J % 8 == 6)
                ind++;
        }
		for (int I = 0; I < 4; I++)
			sort (mat[I], mat[I]+13, cmp);
		nx = 2;
		for (int I = 0; I < 4; I++, nx++, nx %= 4)
		{
			cout << dir[nx] << ":";
			for (int J = 0; J < 13; J++)
				cout << " " << mat[nx][J];
			cout << endl;
		}
	}
	return 0;
}
