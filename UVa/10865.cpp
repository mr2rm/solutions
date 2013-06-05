#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
	pair <int, int> center;
	int n, x, y, cent;
	int s, o;
	vector < pair <int, int> > v;
	while (cin >> n && n)
	{
		v.clear();
		for (int I = 0; I < n && cin >> x >> y; I++)
			v.push_back (make_pair(x, y));
		cent = n / 2;
		center = v[cent];
		s = o = 0;
		for (int I = 0; I < n; I++)
			if ( (v[I].first > center.first && v[I].second > center.second) || (v[I].first < center.first && v[I].second < center.second) )
					s++;
			else if (v[I].first != center.first && v[I].second != center.second)
				o++;
		cout << s << " " << o << endl;
	}
	return 0;
}
