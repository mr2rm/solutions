#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	int n, k, res, sz, t1, t2, tmp, ind;
	bool b;
	vector <int> v;
	while (cin >> n >> k && n + k)
	{
		res = 1;
		for (int I = 0; I < n; I++)
		{
			v.clear();
			for (int J = 1; J <= n; J++)
				v.push_back (J);
			sz = n;
			ind = I;
			while (sz > 1)
			{
				t1 = (ind + k - 1) % sz;
				if (v[t1] == 1)
                    break;
				v.erase (v.begin() + t1);
				sz--;
				t2 = t1;
				t2 %= sz;
				t2 = (t2 + k - 1) % sz;
				tmp = v[t2];
				v.erase (v.begin() + t2);
				if (t2 < t1)
				{
					t1--;
					if (t1 == -1)
						t1 = sz-1;
				}
				v.insert (v.begin() + t1, tmp);
				ind = (t1 + 1) % sz;
			}
			if (sz == 1 && v[0] == 1)
			{
				res = I + 1;
				break;
			}
		}
		cout << res << endl;
	}
	return 0;
}
