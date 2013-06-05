#include <iostream>
#include <set>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n;
int arr[12];
set <string> s;

int main ()
{
	while (cin >> t >> n && n != 0)
	{
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		s.clear ();
		int maxi = pow (2., n);
		for (int i = 0; i < maxi; i++)
		{
			int sum = 0;
			bool b = true;
			string str;
			for (int j = 0; j < n; j++)
			{
				int temp = i & (1 << j);
				if (temp != 0)
				{
					sum += arr[j];
					if (b)
						b = false;
					else
						str += "+";
					stringstream ss;
					ss << arr[j];
					str += ss.str ();
				}
			}
			if (sum == t)
				s.insert (str);
		}
		cout << "Sums of " << t << ":" << endl;
		if (s.size () == 0)
			cout << "NONE" << endl;
		else
		{
			vector <string> v (s.begin(), s.end());
			reverse (v.begin(), v.end());
			for (int i = 0; i < v.size(); i++)
				cout << v[i] << endl;
		}
	}
	return 0;
}