#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
	int f, r;
	double res;
	while (cin >> f && f && cin >> r)
	{
		vector <int> ft (f);
		vector <int> rt (r);
		vector <double> rat;
		for (int i = 0; i < f && cin >> ft[i]; i++);
		for (int j = 0; j < r && cin >> rt[j]; j++);
		for (int i = 0; i < f; i++)
			for (int j = 0; j < r; j++)
				rat.push_back ((double)rt[j]/ft[i]);
		sort (rat.begin(), rat.end());
		res = -1.;
		for (int i = 1; i < rat.size(); i++)
			res = max (rat[i]/rat[i-1], res);
		printf ("%.2f\n", res);
	}
	return 0;
}