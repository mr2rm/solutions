#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main ()
{
	vector <string> v;
	string str;
	int mxsz, c, n, r, m;
	while (cin >> n)
	{
		v.clear();
		mxsz = -1;
		for (int I = 0; I < n && cin >> str; I++)
		{
			v.push_back(str);
			mxsz = max((int)str.length(), mxsz);
		}
		sort (v.begin(), v.end());
		c = 62 / (mxsz + 2);
		r = n / c;
		if (n % c)	r++;
		cout << string (60, '-') << endl;
		for (int I = 0; I < r; I++)
		{
			for (int J = I; J < n; J += r)
			{
				cout << v[J];
				if (J + r < n)
					cout << string (mxsz + 2 - v[J].size(), ' ');
				else
					cout << string (mxsz - v[J].size(), ' ');
			}
			cout << endl;
		}
	}
	return 0;
}