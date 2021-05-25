#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>

using namespace std;

int n, r, res;
int sz_byt, base_adr, sz;
string name, str;
map <string, pair <int, int> > name2bs_sz;
map <string, vector < pair <int, int> > > name2l_u;

int main ()
{
	cin >> n >> r;
	for (int I = 0; I < n; I++)
	{
		cin >> name >> base_adr >> sz_byt >> sz;
		name2bs_sz[name] = make_pair (base_adr, sz_byt);
		vector < pair <int, int> > l_u (sz);
		for (int J = 0; J < sz && cin >> l_u[J].first >> l_u[J].second; J++);
		name2l_u[name] = l_u;
	}
	for (int I = 0; I < r && cin >> str; I++)
	{
		sz = name2l_u[str].size();
		vector <int> v(sz);
		for (int J = 0; J < sz && cin >> v[J]; J++);
		vector <int> c(sz+1);
		for (int J = sz; J >= 0; J--)
		{
			if (!J)
			{
				res = name2bs_sz[str].first;
				for (int K = 1; K <= sz; K++)
					res -= (c[K]*name2l_u[str][K-1].first);
				c[J] = res;
			}
			else if (J == sz)
				c[J] = name2bs_sz[str].second;
			else
				c[J] = c[J+1]*(name2l_u[str][J].second - name2l_u[str][J].first + 1);
		}
		res = c[0];
		cout << str << "[";
		for (int J = 0; J < sz; J++)
		{
			if (J)
				cout << ", ";
			cout << v[J];
			res += (v[J]*c[J+1]);
		}
		cout << "] = " << res << endl;
	}
	return 0;
}