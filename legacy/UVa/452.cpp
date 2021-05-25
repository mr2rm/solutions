#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <sstream>

using namespace std;

int tc;
vector <char> v;
char ch;
string str;
int mat[30][30];
vector <int> mark;

void dfs (int x)
{
	if (mark[x] != -1)
		return;
	int Res = 0;
	for (int i = 0; i < v.size(); i++)
		if (v[i]-'A' != x && mat[x][v[i]-'A'] == 1)
		{	
			dfs (v[i]-'A');
			Res = max (Res, mark[v[i]-'A']);
		}
	mark[x] = (Res + mat[x][x]);
}

int main()
{
	//freopen ("TC.in", "r", stdin);
	cin >> tc;
	getline (cin, str);
	getline (cin, str);
	for (; tc > 0; tc--)
	{
		v.clear();
		for (int i = 0; i < 30; i++)
			memset (mat[i], 0, sizeof mat[i]);
		mark = vector <int> (30, -1);
		while (getline (cin, str))
		{
			if (tc != 1 && str == "")
				break;
			stringstream ss (str);
			ss >> ch;	v.push_back (ch);
			ss >> mat[ch-'A'][ch-'A'];
			string s;
			ss >> s;
			for (int i = 0; i < s.length(); i++)
				mat[ch-'A'][s[i]-'A'] = 1;
		}
		for (int i = 0; i < v.size(); i++)
			if (mark[v[i]-'A'] == -1)
				dfs (v[i]-'A');
		sort (mark.begin(), mark.end());
		cout << mark[29] << endl;
		if (tc != 1)	cout << endl;
	}
	return 0;
}