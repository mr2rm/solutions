#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int n, m, arr[10010];

bool cmp (int a, int b)
{
	bool odd_a = a % 2;
	bool odd_b = b % 2;
	int mod_a = a % m;
	int mod_b = b % m;
	if (mod_a == mod_b)
	{
		if (odd_a && odd_b)
			return a > b;
		else if (!odd_a && !odd_b)
			return a < b;
		else if (odd_a)
			return true;
		else
			return false;
	}
	return mod_a < mod_b;
}

int main ()
{
	while (cin >> n >> m)
	{
		cout << n << ' ' << m << endl;
		if (n+m == 0)	break;
		for (int I = 0; I < n; I++)
			scanf ("%d", &arr[I]);
		sort (arr, arr+n, cmp);
		for (int I = 0; I < n; I++)
			printf ("%d\n", arr[I]);
	}
	return 0;
}
