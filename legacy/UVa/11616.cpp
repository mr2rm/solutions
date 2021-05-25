#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

map <string, int> mpn;
string s[13]= {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
int n[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
string str, res, tstr;
int x, ind;

int main ()
{
	for (int I = 0; I < 13; I++)
		mpn[s[I]] = n[I];
	while (cin >> str)
	{
		x = 0;
		if (isalpha(str[0]))
		{
			for (int I = 0; I < str.length(); I++)
			{
				if (I+1 < str.length())
				{
					tstr = str[I];
					tstr += str[I+1];
				}
				if (I+1 < str.length() && mpn[tstr])
				{
					x += mpn[tstr];
					I++;
				}
				else
				{
					tstr = str[I];
					x += mpn[tstr];
				}
			}
			cout << x << endl;
		}
		else
		{
			for (int I = 0; I < str.length(); I++)
				x = (x * 10) + (str[I]-'0');
			ind = 12;
			while (x)
			{
				for (; n[ind] > x; ind--);
				x -= n[ind];
				cout << s[ind];
			}
			cout << endl;
		}
	}
	return 0;
}