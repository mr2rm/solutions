#include <iostream>
#include <string>
#include <map>
#include <cstdio>

using namespace std;

map <char, int> mp;

int main ()
{
	string str;
	mp['B'] = mp['P'] = mp['F'] = mp['V'] = 1;
	mp['C'] = mp['S'] = mp['K'] = mp['G'] = mp['J'] = mp['Q'] = mp['X'] = mp['Z'] = 2;
	mp['D'] = mp['T'] = 3;
	mp['L'] = 4;
	mp['M'] = mp['N'] = 5;
	mp['R'] = 6;
	int ind;
	string sp1 (9, ' ');
	string sp2 (21, ' ');
	cout << sp1 << "NAME" << sp2 << "SOUNDEX CODE" << endl;
	while (cin >> str)
	{
		string res (3, '0');
		ind = 0;
		for (int I = 1; ind != 3 && I < str.length(); I++)
			if (mp[str[I]] && mp[str[I-1]] != mp[str[I]])
			{
				res[ind] = '0' + mp[str[I]];
				ind++;
			}
		res = str[0] + res;
		sp2 = string (25-str.length(), ' ');
		cout << sp1 << str << sp2 << res << endl;
	}
	printf ("%32s\n", "END OF OUTPUT");
	return 0;
}