#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

long long mat[20][20];
int n, m;

void f1 (int i, int j)
{
	long long t1, t2;
	t1 = t2 = 0;
	for (int k = i + 1; k <= n; k++)
		t1 = max(t1, mat[k][1] + mat[k][j]);
	for (int k = 1;	k < j; k++)
		t2 = max(t2, mat[i][k] + mat[n][k]);
	mat[i][j] = t1 + t2;
}

void f2 (int i, int j)
{
	long long t = 0;
	for (int k = i; k < j; k++)
		t = max(t, mat[i][k] + mat[k+1][j]);
	mat[i][j] = t;
}

int main ()
{
	while (cin >> n >> m)
	{
		mat[n][1] = m;
		for (int i = n; i >= 0; i--)
			for (int j = 0; j <= n; j++)
			{
				if (i == n && j == 1)
					continue;
				if (i >= j)
					f1(i, j);
				else
					f2(i, j);
			}
		cout << mat[1][n] << endl;
	}
	return 0;
}