#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main ()
{
	int t, n, c, maxi;
	cin >> t;
	for(int I = 1; I <= t && cin >> n; I++)
	{
		maxi = -1;
		for (int J = 0; J < n && cin >> c; J++)
			if (c > maxi)
				maxi = c;
		cout << "Case " << I << ": " << maxi << endl;
	}
	return 0;
}