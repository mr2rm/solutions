#include <iostream>

using namespace std;

int main ()
{
	int n, x, y, m, t;
	while (cin >> t && t && cin >> n >> m)
	{
		for (int I = 0; I < t && cin >> x >> y; I++)
		{
			if (x == n || y == m)
				cout << "divisa" << endl;
			else
			{
				if (x < n)
				{
					if (y < m)	cout << "SO" << endl;
					else cout << "NO" << endl;
				}
				else
				{
					if (y < m)	cout << "SE" << endl;
					else cout << "NE" << endl;
				}
			}
		}
	}
	return 0;
}