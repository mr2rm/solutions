#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <cstdio>


using namespace std;

int n, k, g, p1, p2;
string m1, m2;
int win[110], lose[110];
int winner[3][3] = {{-1, 1, 0}, {0, -1, 1}, {1, 0, -1}};
map <string, int> mp;
double res;

int main ()
{
	mp["rock"] = 0;
	mp["scissors"] = 1;
	mp["paper"] = 2;
	for (int t = 0; cin >> n && n && cin >> k; t++)
	{
		if (t)
			cout << endl;
		memset (win, 0, sizeof win);
		memset (lose, 0, sizeof lose);
		g = k*n*(n-1)/2;
		for (int I = 0; I < g; I++)
		{
			cin >> p1 >> m1 >> p2 >> m2;
			if (winner[mp[m1]][mp[m2]] == 1)
			{
				win[p1]++;
				lose[p2]++;
			}
			else if (winner[mp[m2]][mp[m1]] == 1)
			{
				win[p2]++;
				lose[p1]++;
			}
		}
		for (int I = 1; I <= n; I++)
			if (lose[I]+win[I])
			{
				res = (double)win[I]/(double)(win[I]+lose[I]);
				printf ("%.3f\n", res);
			}
			else
				cout << "-" << endl;
	}
	return 0;
}