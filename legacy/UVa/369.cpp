#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//1//long long fact[101];
long long fact[101][101];
//2//long long fact[51];

int main()
{
	//1//long long can't store 100!
	/*
	fact[0] = fact[1] = 1;
	for (int i = 2; i < 101; i++)
		fact[i] = i * fact[i-1];
	*/
	
	//2//fails to store 100*99*98*...*51 in a long long
	/*
	fact[0] = 1;
	for (int i = 1; i < 51; i++)
		fact[i] = fact[i-1] * i;
	int n, m;
	while (cin >> n >> m && n != 0)
	{
		int maxi = max (m, n - m);
		int mini = min (m, n - m);
		long long temp = 1;
		for (int i = n; i > maxi; i--)
			temp *= i;
		cout << n << " things taken " << m << " at a time is " << temp / fact[mini] << " exactly." << endl;
	}
	*/
	
	//ACC for Khaiam-Paskal
	for (int i = 0; i < 101; i++)
		for (int j = 0; j <= i; j++)
			if (i == j || j == 0)
				fact[i][j] = 1;
			else
				fact[i][j] = fact[i-1][j-1] + fact[i-1][j];
	int n, m;
	while (cin >> n >> m && n != 0)
		cout << n << " things taken " << m << " at a time is " << fact[n][m] << " exactly." << endl;
		
	return 0;
}

/*
int main ()
{
	vector <long long> fact ( 101 );
	fact[0] = fact[1] = 1;
	for ( int i = 2 ; i < 101 ; i++ )
		fact[i] = i * fact[i-1];
	long long Res;
	int n , m;
	while ( cin >> n >> m && !( n == 0 && m == 0 ) )
	{
		Res = fact[n];
		long long temp = fact[n-m] * fact[m];
		Res /= temp;
		cout << n << " things taken " << m << " at a time is " << Res << " exactly." << endl;
	}
	return 0;
}
*/