#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	int t, n;
	int high, low;
	cin >> t;
	for (int i = 1; i <= t && cin >> n; i++)
	{
		high = low = 0;
		vector <int> v (n);
		for (int j = 0; j < n && cin >> v[j]; j++);
		for (int j = 0; j < n - 1; j++)
		{
			if (v[j+1] - v[j] > 0)
				high++;
			else if (v[j+1] - v[j] < 0)
				low++;
		}
		cout << "Case " << i << ": " << high << " " << low << endl;
	}
	return 0;
}