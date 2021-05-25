#include <iostream>
#include <map>
#include <string>

using namespace std;

int main ()
{
	int rnd, res, sz;
	string s1, s2;
	map <char, bool> mp, mark;
	while (cin >> rnd && rnd != -1 && cin >> s1 >> s2)
	{
		mp.clear();
		mark.clear();
		for (int I = 0; I < (int)s1.length(); I++)
			mp[s1[I]] = true;
		sz = mp.size();
		res = 0;
		for (int I = 0; res < 7 && sz && I < (int)s2.length(); I++)
			if (mark[s2[I]])
				continue;
			else if (mp[s2[I]])
			{
				mark[s2[I]] = true;
				sz--;
			}
			else
				res++;
		cout << "Round " << rnd << endl;
		if (res == 7)
			cout << "You lose." << endl;
		else if (sz)
			cout << "You chickened out." << endl;
		else
			cout << "You win." << endl;
	}
	return 0;
}
