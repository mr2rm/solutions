#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
	int n, m, p;
	int dif;
	pair <int, int> res;
	vector <int> price;
	while (cin >> n)
	{
		price.clear ();
		for (int i = 0; i < n && cin >> p; i++)
			price.push_back (p);
		cin >> m;
		sort (price.begin(), price.end());
		dif = 1000002;
		for (int i = 0; i < n-1; i++)
			for (int j = i+1; j < n; j++)
				if (price[i]+price[j] == m && price[j]-price[i] < dif)
				{
					dif = price[j]-price[i];
					res.first = price[i];
					res.second = price[j];
				}
		cout << "Peter should buy books whose prices are " << res.first << " and "<< res.second << "." << endl << endl;
	}
	return 0;
}