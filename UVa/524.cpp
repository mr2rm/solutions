#include <iostream>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

int n;
int mark[17];
int primes[32] = {0};
int arr[16];

void prime (int x)
{
	primes[0] = 1;
	primes[1] = 1;
	int maxi = (int)sqrt ((double)x);
	for (int i = 2; i <= maxi; i++)
		if (!primes[i])
			for (int j = i*i; j <= x; j += i)
				primes[j] = 1;
}

void primering (int x)
{
	if (x == n)
	{
		int index = arr[0] + arr[n-1];
		if (!primes[index])
		{
			cout << "1";
			for (int i = 1; i < n; i++)
				cout << " " << arr[i];
			cout << endl;
		}
		return;
	}
	for (int i = 2; i <= n; i++)
		if (!mark[i] && !primes[i+arr[x-1]])
		{
			mark[i] = 1;
			arr[x] = i;
			primering (x+1);
			mark[i] = 0;
		}
}

int main ()
{
	freopen ("test.in", "r", stdin);
	prime (31);
	arr[0] = 1;
	int test = 0;
	while (cin >> n)
	{
		if (test != 0)
			cout << endl;
		test++;
		memset (mark, 0, sizeof mark);
		mark[1] = 1;
		cout << "Case " << test << ":" << endl;
		primering (1);
	}
	return 0;
}