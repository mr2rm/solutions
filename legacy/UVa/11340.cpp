#include <iostream>
#include <string>
#include <map>
#include <cstdio>

using namespace std;

int main ()
{
	int t, n, cost, res;
	map <char, int> mp;
	char ch;
	string str;
	for (cin >> t; t; t--)
	{
		mp.clear();
		res = 0;
		for (cin >> n; n && cin >> ch >> cost; n--)
			mp[ch] = cost;
		cin >> n;
		for (cin.ignore(); n && getline(cin, str); n--)
			for (int I = 0; I < str.length(); I++)
				res += mp[str[I]];
		printf ("%d.%02d$\n", res/100, res%100);
	}
	return 0;
}