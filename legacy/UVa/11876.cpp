#include <iostream>
#include <cmath>

using namespace std;

int dp[1000000];
int t, sq, x, I, n, cnt, a, b, p, q;

int BST (int l, int h, int val)
{
	if (l == h)
		return l;
	int mid = (l + h) / 2;
	if (dp[mid] == val)
		return mid;
	else if (val < dp[mid])
		return BST (l, mid-1, val);
	else
		return BST (mid+1, h, val);
}

int main ()
{
	dp[0] = 1;
	for (I = 1; dp[I-1] < 1000000; I++)
	{
		x = dp[I-1];
		sq = (int)sqrt ((double)x);
		cnt = 2;
		for (int J = 2; J <= sq; J++)
			if (x % J == 0)
				cnt += 2;
		if (sq*sq == x)	cnt--;
		dp[I] = cnt + dp[I-1];
	}
	n = I-1;
	if (dp[I-1] > 1000000)	
		n--;
	cin >> t;
	for (I = 1; I <= t && cin >> a >> b; I++)
	{
		p = BST (0, n, a);
		if (dp[p] < a)	
			p++;
		q = BST (0, n, b);
		if (dp[q] > b)	
			q--;
		cout << "Case " << I << ": " << q-p+1 << endl;
	}
	return 0;
}