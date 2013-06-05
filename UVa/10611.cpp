#include <iostream>
#include <cstdio>

using namespace std;

int a[50010], n, q, x, res;
int mark;

int BST (int l, int h, int val)
{
	if (l > h)
	{
		if (!mark)
			return h;
		else
			return l;
	}
	int mid = (l + h) / 2;
	if (a[mid] == val)
		return mid;
	else if (val < a[mid])
		return BST (l, mid-1, val);
	else
		return BST (mid+1, h, val);
}

int main ()
{
	cin >> n;
	for (int I = 0; I < n; I++)
		scanf ("%d", &a[I]);
	cin >> q;
	for (int I = 0; I < q; I++)
	{
		scanf ("%d", &x);
		mark = 0;
		res = BST (0, n-1, x-1);
		if (res == -1 || res == n)
			printf ("%c ", 'X');
		else
			printf ("%d ", a[res]);
		mark = 1;
		res = BST (0, n-1, x+1);
		if (res == -1 || res == n)
			printf ("%c\n", 'X');
		else
			printf ("%d\n", a[res]);
	}
	return 0;
}