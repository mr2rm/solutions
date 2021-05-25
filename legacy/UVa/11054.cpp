#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
	int x, n;
	long long cap, res;
	while (cin >> n && n)
	{
		cin >> cap;
		res = 0;
		for (int I = 1; I < n && cin >> x; I++)
		{
			res += abs (cap);
			cap += x;
		}
		cout << res << endl;
	}
	return 0;
}