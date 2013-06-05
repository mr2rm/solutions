#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main ()
{
	int n, x, maxi, res;
	map < vector <int> , int > mp;
	map < vector <int> , int >::iterator it;
	vector <int> v;
	while (cin >> n && n)
	{
		mp.clear();
		maxi = res = 0;
		for (int I = 0; I < n; I++)
		{
			v.clear();
			for (int J = 0; J < 5 && cin >> x; J++)
				v.push_back (x);
			sort (v.begin(), v.end());
			mp[v]++;
			if (mp[v] > maxi)
				maxi = mp[v];
		}
		for (it = mp.begin(); it != mp.end(); it++)
			if ((*it).second == maxi)
				res += (*it).second;
		cout << res << endl;
	}
	return 0;
}