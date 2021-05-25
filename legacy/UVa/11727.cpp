#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	vector <int> v (3);
	cin >> t;
	for (int i = 1; i <= t && cin >> v[0] >> v[1] >> v[2]; i++)
	{
		sort (v.begin(), v.end());
		cout << "Case " << i << ": " << v[1] << endl;
	}
	return 0;
}