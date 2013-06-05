#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main ()
{
	int n, m, c;
	int x, sum, res;
	int cons[20];
	int on[20];
	bool blown;
	for (int t = 1; cin >> n >> m >> c && n+m+c; t++)
	{
		memset (on, 0, sizeof on);
		blown = false;
		sum = res = 0;
		for (int I = 0; I < n && cin >> cons[I]; I++);
		for (int I = 0; I < m && cin >> x; I++)
			if (!blown)
			{
				x--;
				if (!on[x])
				{
					on[x] = 1;
					if (sum + cons[x] > c)
						blown = true;
					else
					{
						sum += cons[x];
						res = max (sum, res);
					}
				}
				else
				{
					on[x] = 0;
					sum -= cons[x];
				}
			}
		cout << "Sequence " << t << endl;
		if (blown)
			cout << "Fuse was blown." << endl;
		else
			cout << "Fuse was not blown." << endl << "Maximal power consumption was " << res << " amperes." << endl;
		cout << endl;
	}
	return 0;
}
