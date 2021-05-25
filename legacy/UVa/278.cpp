#include <iostream>

using namespace std;

int main ()
{
	int n, m, t, res;
	char p;
	for (cin >> t; t && cin >> p >> m >> n; t--)
	{
		if (p == 'r' || p == 'Q')
			res = min (m, n);
		else if (p == 'k')
		{
			res = m * n;
			if (res % 2)
			{
				res /= 2;
				res++;
			}
			else
				res /= 2;
		}
		else
		{
			if (m % 2)
			{
				m /= 2;
				m++;
			}
			else
				m /= 2;
			if (n % 2)
			{
				n /= 2;
				n++;
			}
			else
				n /= 2;
			res = m * n;
		}
		cout << res << endl;
	}
	return 0;
}