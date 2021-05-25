#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

#define MAXI 100010042
using namespace std;

vector <bool> isprime (MAXI, true);

void sieve ()
{
	isprime[0] = isprime[1] = false;
	for (int I = 4; I < MAXI; I += 2)
		isprime[I] = false;
	for (int I = 3; I*I < MAXI; I += 2)
		if (isprime[I])
		{
			int step = 2*I;
			for (int J = I*I; J < MAXI; J += step)
				isprime[J] = false;
		}
}

int main ()
{
	sieve ();
	//cout << "yes" << endl;
	int a, b, cnt;
	long long tmp;
	double d;
	int arr[10001];
	for (int I = 0; I < 40; I++)
		arr[I] = I+1;
	for (int I = 40; I <= 10000; I++)
	{
		arr[I] = arr[I-1];
		tmp = I*I + I + 41;
		if (isprime[tmp])
			arr[I]++;
	}
	while (cin >> a >> b)
	{
		if (a && b)
			cnt = arr[b] - arr[a-1];
		else
			cnt = arr[b] - arr[a] + 1;
		d = (double)cnt*100./(double)(b-a+1);
		printf ("%.2lf\n", d+1e-9);
	}
	return 0;
}