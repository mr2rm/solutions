#include <iostream>
#include <string>
#include <map>

using namespace std;

int main ()
{
	string str, res, s;
	map <string, int> mp;
	int maxi, n;
	while (cin >> n >> str)
	{
		mp.clear();
		res = "";
		maxi = -1;
		for (unsigned int I = 0; I + n <= str.length(); I++)
		{
			s = str.substr (I, n);
			mp[s]++;
			if (mp[s] > maxi)
			{
				maxi = mp[s];
				res = s;
			}
		}
		cout << res << endl;
	}
	return 0;
}
