#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main ()
{
	int n;
	bool b;
	string s1, s2, str;
	vector < pair <int, string> > v;
	while (cin >> n && n && cin >> s1 >> s2)
	{
		v.clear();
		b = true;
		do
		{
			str = s1 + s2;
			if (str == "righton")	break;
			v.push_back (make_pair(n, str));
		}
		while (cin >> n >> s1 >> s2);
		for (int I = 0; b && I < (int)v.size(); I++)
			if ( (v[I].first == n && v[I].second != "righton") ||
				 (v[I].first > n && v[I].second != "toohigh") ||
				 (v[I].first < n && v[I].second != "toolow")
				)
				b = false;
		if (b)
			cout << "Stan may be honest" << endl;
		else
			cout << "Stan is dishonest" << endl;
	}
	return 0;
}
