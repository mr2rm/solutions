#include <iostream>
#include <algorithm>

using namespace std;

int n, maxi;

int maxcola (int borrow)
{
	int all, res;
	all = n + borrow;
	res = n;
	while (all >= 3)
	{
		res += (all / 3);
		all = (all / 3) + (all % 3);
	}
	if (!borrow || all == borrow)
		return res;
	else
		return -1;
}

int main ()
{
	while (cin >> n)
	{
		maxi = -1;
		for (int I = 0; I < 3; I++)
			maxi = max (maxi, maxcola(I));
		cout << maxi << endl;
	}
	return 0;
}