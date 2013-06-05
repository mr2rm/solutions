#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main ()
{
	int t, n, m, f, x, y, ind;
	int street[50010], avenue[50010];
	cin >> t;
	while (t-- && cin >> n >> m >> f)
	{
		for (int I = 0; I < f; I++)
		{
			scanf ("%d%d", &x, &y);
			street[I] = x;
			avenue[I] = y;
		}
		sort (street, street + f);
		sort (avenue, avenue + f);
		ind = f/2;
		if (f % 2)
			printf ("(Street: %d, Avenue: %d)\n", street[ind], avenue[ind]);
		else
			printf ("(Street: %d, Avenue: %d)\n", street[ind-1], avenue[ind-1]);
	}
	return 0;
}
