#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

long long dp[30001] = {0};
int money[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
int temp;

int main ()
{
	// WA --->  with iteration
	/*
	dp[0] = 1;
	for (int i = 5; i < 30001; i+= 5)
		for (int j = 0; j < 11; j++)
		{
			temp = i - money[j];
			if (temp >= 0)
				dp[i] += dp[temp];
			else
				break;
		}	
	*/
	dp[0] = 1;
	for (int j = 0; j < 11; j++)
		for (int i = money[j]; i < 30001; i += 5)
		{
			temp = i - money[j];
			dp[i] += dp[temp];
		}
	string str;
	double d;
	int n;
	int d1, d2;
	while (scanf ("%d.%d", &d1, &d2))
	{
		n = d1 * 100;
		n += d2;
		if (!n)
			break;
		else
			printf("%6.2lf%17lld\n", n/100., dp[n]); 
	}
	/*
	while (cin >> str && str != "0.00")
	{
		stringstream ss (str);
		ss >> d;
		n = d * 100;
		printf("%6.2lf%17lld\n", d, dp[n]); 
		//printf( "%6.2f" , f );
		//printf ("%17ull\n", dp[n]);
	}
	*/
	return 0;
}