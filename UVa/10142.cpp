#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <map>
#include <utility>
#include <algorithm>

#define PII pair <int, int>
using namespace std;

int main ()
{
	int t, n, x, cnt, tmp;
	int mark[22], last[1010];
	string str;
	vector <string> name;
	vector < vector <int> > v;
	cin >> t;
	for (int i = 0; i < t && cin >> n; i++)
	{
		if (i)	cout << endl;
		name.clear();
		v.clear();
		memset (mark, 0, sizeof mark);
		memset (last, 0, sizeof last);
		cin.ignore();
		for (int I = 0; I < n && getline(cin, str); I++)
			name.push_back (str);
		while (getline(cin, str) && str != "")
		{
			stringstream ss (str);
			vector <int> vv;
			while (ss >> x)
				vv.push_back (x);
			v.push_back (vv);
		}
		while (1)
		{
			map <int, int> mp;
			cnt = 0;
			for (int I = 0; I < (int)v.size(); I++)
			{
				for (; last[I] < (int)v[I].size() && mark[v[I][last[I]]]; last[I]++);
				if (last[I] < (int)v[I].size())
				{
					mp[v[I][last[I]]]++;
					cnt++;
				}
			}
			vector < PII > vpii;
			for (map <int, int>::iterator it = mp.begin(); it != mp.end(); it++)
				vpii.push_back (make_pair((*it).second, (*it).first));
			sort (vpii.begin(), vpii.end());
			tmp = cnt / 2;
			if (vpii.back().first > tmp)
			{
				cout << name[vpii.back().second-1] << endl;
				break;
			}
			else if (vpii.back().first == vpii.front().first)
			{
				for (int I = 0; I < (int)vpii.size(); I++)
					cout << name[vpii[I].second-1] << endl;
				break;
			}
			else
			{
				tmp = vpii[0].first;
				for (int I = 0; I < (int)vpii.size() && vpii[I].first == tmp; I++)
					mark[vpii[I].second] = 1;
			}
		}
	}
	return 0;
}
