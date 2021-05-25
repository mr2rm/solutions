/*
ID: Blackwizard
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int bisq[125001] = {0};

int main ()
{
	freopen ("ariprog.in", "r", stdin);
	freopen ("ariprog.out", "w", stdout);
	int n, m;
	int cnt;
	bool is_none = true;
	cin >> n >> m;
	//memset (bisq, 0, sizeof bisq);
	for (int p = 0; p <= m; p++)
		for (int q = p; q <= m; q++)
			bisq[p*p + q*q] = 1;
	int MAXI = 2*m*m / (n-1);
	for (int b = 1; b <= MAXI; b++)
		for (int a = 0; a <= 2*m*m - b*(n-1); a++)
		{
			cnt = 0;
			for (int I = a; cnt < n && bisq[I]; I += b, cnt++);
			if (cnt == n)
			{
				cout << a << " " << b << endl;
				if (is_none)
					is_none = false;
			}
		}
	if (is_none)
		cout << "NONE" << endl;
	return 0;
}
