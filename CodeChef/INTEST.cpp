#include <iostream>
#include <cstdio>
 
using namespace std;
 
int main ()
{
	int n, k, cnt, x;
	scanf ("%d %d", &n, &k);
	cnt = 0;
	for (int I = 0; I < n; I++)
	{
		scanf ("%d", &x);
		if (x % k == 0)
			cnt++;
	}
	printf ("%d\n", cnt);
	return 0;
}