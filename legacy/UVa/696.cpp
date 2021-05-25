#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int m, n, res, tmp;
	while (cin >> m >> n && m + n)
	{
		if (!m || !n)
			res = 0;
		else if (m == 1 || n == 1)
			res = m*n;
		else if (m == 2 || n == 2)
		{
			tmp = (m*n) / 4;
			res = 4*ceil(tmp/2.);
			if (tmp % 2 == 0)
				res += (m*n) % 4;
		}
		else
			res = (m*n + 1) / 2;
		cout << res << " knights may be placed on a " << m << " row " << n << " column board." << endl;
	}
	return 0;
}