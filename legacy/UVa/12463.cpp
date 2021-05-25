#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b, c, d, e;
	while (cin >> a >> b >> c >> d >> e && a != 0)
	{
		int Res = a * b * c * pow (d, 2.) * pow (e, 2.);
		cout << Res << endl;
	}
	return 0;
}