#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
	int t, n;
	for (cin >> t; t && cin >> n; t--)
	{
		n *= 567;
		n /= 9;
		n += 7492;
		n *= 235;
		n /= 47;
		n -= 498;
		n /= 10;
		n %= 10;
		cout << fabs((double)n) << endl;
	}
	return 0;
}