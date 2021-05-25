#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a, b;
	while (cin >> a >> b && a != -1 )
	{
		int x = max (a, b);
		int y = min (a, b);
		int res1 = x - y;
		int res2 = y - x + 100;
		cout << min (res1, res2) << endl;
	}
	return 0;
}