#include <iostream>
#include <cstring>
#include <utility>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct record
{
	int name, solved, penalty;
	record (int _name = 0, int _solved = 0, int _penalty = 0)
	{
		name = _name;
		solved = _solved;
		penalty = _penalty;
	}
	bool operator < (const record &two) const
	{
		if (solved != two.solved)
			return solved > two.solved;
		if (penalty != two.penalty)
			return penalty < two.penalty;
		return name < two.name;
	}
};

int pen[101], sol[101];
int SOLVE[101][10], PENALT[101][10];
map <int, bool> mp;
vector <record> v;
record rc;
char ch;
string str;

int main ()
{
	int t, time, sz, num, prob;
	cin >> t;
	cin.ignore();
	getline (cin, str);
	while (t--)
	{
		v.clear();
		mp.clear();
		memset (sol, 0, sizeof sol);
		memset (pen, 0, sizeof pen);
		memset (SOLVE, false, sizeof SOLVE);
		memset (PENALT, 0, sizeof PENALT);
		while (getline(cin, str) && str != "")
		{
			stringstream ss (str);
			ss >> num >> prob >> time >> ch;
			mp[num] = true;
			if (!SOLVE[num][prob])
			{
				if (ch == 'C')
				{
					SOLVE[num][prob] = true;
					sol[num]++;
					pen[num] += PENALT[num][prob] + time;
				}
				else if (ch == 'I')
					PENALT[num][prob] += 20;
			}
		}
		for (int I = 1; I <= 100; I++)
			if (mp[I])
			{
				rc.name = I;
				rc.penalty = pen[I];
				rc.solved = sol[I];
				v.push_back (rc);
			}
		sz = v.size();
		sort (v.begin(), v.end());
		for (int I = 0; I < sz; I++)
			cout << v[I].name << ' ' << v[I].solved << ' ' << v[I].penalty << endl;
		if (t)	cout << endl;
	}
	return 0;
}
