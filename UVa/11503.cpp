#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int tc, fs;
int x, y;
string s1, s2;
int last;
vector <int> f (200001);
vector <int> nd (200001);

int find (int a)
{
	if (nd[a] == a)
		return a;
	return nd[a] = find (nd[a]);
}

void merge (int a, int b)
{
	f[find (b)] += (f[find (a)] + 1);
	nd[find (a)] = find (b); 
}

int main()
{
	//freopen ("Q.in", "r", stdin);
	//freopen ("A.out", "w", stdout);
	cin >> tc;
	for (int i = 0; i < tc && cin >> fs; i++)
	{
		map <string, int> m;
		last = 0;
		for (int j = 1; j <= 2*fs; j++)
		{
			f[j] = 0;
			nd[j] = j;
		}
		for (int j = 0; j < fs && cin >> s1 >> s2; j++)
		{
			if (m[s1] == 0)
			{
				last++;
				m[s1] = last;
			}
			if (m[s2] == 0)
			{
				last++;
				m[s2] = last;
			}
			x = m[s1];
			y = m[s2];
			if (find (x) != find (y))
				merge (find (x), find (y));
			cout << f[find (x)] + 1 << endl;
		}
	}
	
	return 0;
}