#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

int main ()
{
	int n, p, r, r_res;
	double d, d_res;
	set <string> s;
	string str, name, res;
	for (int t = 1; cin >> n >> p && n; t++)
	{
		cin.ignore();
		s.clear();
		for (int I = 0; I < n && getline (cin, str); I++)
			s.insert(str);
		n = s.size();
		r_res = -1;
		for (int I = 0; I < p; I++)
		{
			getline (cin, name);
			cin >> d >> r;
			cin.ignore();
			for (int J = 0; J < r && getline(cin, str); J++);
			if (r > r_res)
			{
				r_res = r;
				d_res = d;
				res = name;
			}
			else if (r == r_res && d < d_res)
			{
				d_res = d;
				res = name;
			}
		}
		if (t > 1) 
			cout << endl;
		cout << "RFP #" << t << endl << res << endl;
	}
	return 0;
}