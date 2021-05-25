#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

#define PSI pair <string, int>
using namespace std;

bool cmp (const PSI &p1, const PSI &p2)
{
	return p1.second > p2.second;
}

int main ()
{
	map <string, string> mp1;
	map <string, int> mp2;
	int t, n, maxi;
	string s1, s2, str;
	cin >> t;
	while (t--)
	{
		mp1.clear();
		mp2.clear();

		cin >> n;
		cin.ignore(100, '\n');
		for (int I = 0; I < n; I++)
		{
			getline(cin, s1);
			getline(cin, s2);
			mp1[s1] = s2;
			mp2[s1] = 0;
		}

		cin >> n;
		cin.ignore(100, '\n');
		for (int I = 0; I < n; I++)
		{
			getline (cin, str);
			if (mp1.find(str) != mp1.end())
				mp2[str]++;
		}

		vector < PSI > v (mp2.begin(), mp2.end());
		sort (v.begin(), v.end(), cmp);
		maxi = v[0].second;
		if (v[1].second == maxi)
			cout << "tie" << endl;
		else
			cout << mp1[v[0].first] << endl;
		if (t)	cout << endl;
	}
	return 0;
}