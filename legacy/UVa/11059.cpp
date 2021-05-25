#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
	long long p, res;
	int n, arr[20];
	for (int t = 1; cin >> n; t++)
	{
		res = -1;
		for (int I = 0; I < n && cin >> arr[I]; I++);
		for (int I = 0; I < n; I++)
		{
			p = 1;
			for (int J = I; J < n; J++)
			{
				p *= arr[J];
				if (p > res)
					res = p;
			}
		}
		if (res < 0)	res = 0;
		cout << "Case #" << t << ": The maximum product is " << res << "." << endl << endl;
	}
	return 0;
}