#include <iostream>
#include <vector>
#include <queue>
#include <cmath>


using namespace std;

int n, MIN_SZ;
vector <int> v;
vector <int> res;
bool b;

//dfs ---> TLE
void dfs (int x)
{
	v.push_back(x);
	if (x == n)
	{
		if (v.size() < MIN_SZ)
		{
			MIN_SZ = v.size();
			res = vector <int> (v.begin(), v.end());
		}
	}
	else
		for (int I = 0; I < v.size() && x + v[I] <= n; I++)
			dfs (x + v[I]);
	v.pop_back();
}

void df (int x, int dep)
{
	v.push_back(x);
	if (!dep)
	{
		if (x == n)
		{
			b = true;
			res = vector <int> (v.begin(), v.end());
			MIN_SZ = res.size();
		}
	}
	else if ((int)pow(2., dep)*x >= n)
	{
		for (int I = 0; !b && I < v.size() && x + v[I] <= n; I++)
			df (x + v[I], dep-1);
	}
	v.pop_back();
}

void df_id ()
{
	b = false;
	for (int I = 0; !b; I++)
		df (1, I);
}

int main ()
{
	while (cin >> n && n)
	{
		v.clear();
		res.clear();
		//MIN_SZ = n+1;
		df_id();
		//dfs(1);
		for (int I = 0; I < MIN_SZ; I++)
		{
			if (I)
				cout << " ";
			cout << res[I];
		}
		cout << endl;
	}
	return 0;
}