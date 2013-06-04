#include <iostream>

using namespace std;

int main ()
{
	long long res, x, n, tmp;
	while (cin >> n)
	{
		tmp = n+1;
		tmp /= 2;
		res = 0;
		x = tmp*tmp;
		for (int I = 0; I < 3; I++, x--)
			res += 2*x - 1;
		cout << res << endl;
	}
	return 0;
}
