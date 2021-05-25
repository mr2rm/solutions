#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <int> v (1000000, 0);

int main ()
{
	bool b;
	int n, t, m;
	for (int i = 2; i < 1000000; i++)
	{
		t = sqrt ((double)i);
		b = true;
		for (int j = 2; j <= t; j++)
			if (v[j] && i % j == 0)
			{
				b = false;
				break;
			}
		if (b)	
			v[i] = 1;
	}
	while (cin >> n && n != 0)
	{
		m = n / 2;
		b = false;
		for (int i = 2; i <= m; i++)
			if (v[i] && v[n-i])
			{
				cout << n << " = " << i << " + " << n - i << endl;
				b = true;
				break;
			}
		if (!b)
			cout << "Goldbach's conjecture is wrong." << endl;
	}
	return 0;
}
