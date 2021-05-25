#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int main ()
{
	vector < pair <int, int> > v;
	int i, j;
	i = j = 1;
	while (v.size() < 10000000)
		if (j == 1)
		{
			for (; i > 0; i--, j++)
				v.push_back (make_pair (i, j));
			i++;
		}
		else
		{
			for (; j > 0; i++, j--)
				v.push_back (make_pair (i, j));
			j++;
		}
	while (cin >> n)
		cout << "TERM " << n << " IS " << v[n-1].first << "/" << v[n-1].second << endl;
	return 0;
}
