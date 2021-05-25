#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int main ()
{
	string str, last, s;
	int cnt, res, x;
	map <char, int> mp;
	mp['A'] = 1;
	mp['T'] = 10;
	mp['J'] = 11;
	mp['Q'] = 12;
	mp['K'] = 13;
	while (getline(cin, str) && str != "#")
	{
		vector < vector <string> > deck (13, vector <string> (4));
		res = 0;
		cnt = 3;
		do
		{
			stringstream ss (str);
			for (int I = 12; I >= 0 && ss >> deck[I][cnt]; I--);
			cnt--;
		}
		while (cnt >= 0 && getline(cin, str));
		x = 12;
		while (deck[x].size())
		{
			s = deck[x].back();
			last = s;
			deck[x].pop_back();
			if (mp[s[0]])
				x = mp[s[0]];
			else
				x = s[0]-'0';
			x--;
			res++;
		}
		printf ("%02d,", res);	cout << last << endl;
	}
	return 0;
}
