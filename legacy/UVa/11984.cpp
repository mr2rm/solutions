#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

int main ()
{
	int T, c, d;
	double res;
	cin >> T;
	for (int I = 1; I <= T && cin >> c >> d; I++)
	{
		res = c + (d * 5.) / 9.;
		printf ("Case %d: %.2f\n", I, res);
	}
	return 0;
}
