#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
	int n, d, r, res, temp;
	while (cin >> n >> d >> r && n)
	{
		vector <int> mr (n);
		vector <int> ar (n);
		for (int i = 0; i < n && cin >> mr[i]; i++);
		for (int j = 0; j < n && cin >> ar[j]; j++);
		sort (mr.begin(), mr.end());
		sort (ar.begin(), ar.end());
		reverse (ar.begin(), ar.end());
		res = 0;
		for (int i = 0; i < n; i++)
		{
			temp = mr[i] + ar[i];
			if (temp > d)
				res += temp-d;
		}
		cout << res*r << endl;
	}
	return 0;
}