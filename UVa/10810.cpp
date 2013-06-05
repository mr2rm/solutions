#include <iostream>
#include <algorithm>
#include <cstdio>

#define sz 500010
using namespace std;

int n, a[sz], b[sz], c[sz];
long long cnt;

void merge (int l, int h, int m)
{
	int ind, I, J;
	int bsz, csz;
	bsz = m - l;
	csz = h - m;
	for (I = l, ind = 0; I < m; I++)
		b[ind++] = a[I];
	for (J = m, ind = 0; J < h; J++)
		c[ind++] = a[J];
	I = J = 0;
	ind = l;
	while (I < bsz && J < csz)
	{
		if (b[I] < c[J])
			a[ind++] = b[I++];
		else
		{
			a[ind++] = c[J++];
			cnt += bsz - I;
		}
	}
	while (I < bsz)		a[ind++] = b[I++];
	while (J < csz)		a[ind++] = c[J++];
}

void mergesort (int l, int h)
{
	if (l == h-1)	return;
	int m = (l + h) / 2;
	mergesort (l, m);
	mergesort (m, h);
	merge (l, h, m);
}

int main ()
{
	while (cin >> n && n)
	{
		for (int I = 0; I < n; I++)
			scanf ("%d", &a[I]);
		cnt = 0;
		mergesort (0, n);
		cout << cnt << endl;
	}
	return 0;
}