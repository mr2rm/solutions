#include <iostream>
#include <set>

using namespace std;

int main ()
{
	int n, m, c, k, x;
	set <int> s, res;
	set <int>::iterator it;
	cin >> n;
	while (n--)
	{
		cin >> m >> c;
		s.clear();
		s.insert(0);
		for (int I = 0; I < c; I++)
		{
			cin >> k;
			res.clear();
			for (int J = 0; J < k; J++)
			{
				cin >> x;
				for (it = s.begin(); it != s.end(); it++)
					if (*it + x <= m)
						res.insert (*it + x);
			}
			s = res;
		}
		if (res.size())
			cout << *res.rbegin() << endl;
		else
			cout << "no solution" << endl;
	}
	return 0;
}