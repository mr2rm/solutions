#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main ()
{
	int a, b;
	while (cin >> a >> b && a != 0)
	{
		int x = max (a, b) - min (a, b);
		int Res = 0;
		for (int i = 1; i <= sqrt((double)x); i++)
			if (x % i == 0)
				if (x/i != i)	Res += 2;
				else	Res++;
		cout << Res << endl;
	}
	return 0;
}