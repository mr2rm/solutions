#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
	int a, b, c;
	while (cin >> a >> b >> c && a + b + c)
	{
		if (a > b)
			swap (a, b);
		if (b > c)
			swap (b, c);
		a *= a;
		b *= b;
		c *= c;
		if (c == a + b)
			cout << "right" << endl;
		else
			cout << "wrong" << endl;
	}
	return 0;
}