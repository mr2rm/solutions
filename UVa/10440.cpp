#include <iostream>

using namespace std;

int main ()
{
	int n, t, m, c, time, trip, cap;
	int cars[1440];
	for (cin >> c; c != 0 && cin >> n >> t >> m; c--)
	{
		for (int i = 0; i < m && cin >> cars[i]; i++);
		cap = n;
		trip = time = 0;
		for (int i = 0; i < m; i++)
		{
			if (!cap)
			{
				time += 2*t;
				trip ++;
				cap = n;
			}
			if (i == m-1)
			{
				time += t;
				trip++;
			}
			else if (time + 2*t <= cars[i+1])
			{
				time += 2*t;
				trip ++;
				cap = n;
			}
			else
			{
				time = cars[i];
				cap--;
			}
		}
		cout << time << " " << trip << endl;
	}
	return 0;
}
