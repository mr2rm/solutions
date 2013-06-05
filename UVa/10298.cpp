#include <iostream>
#include <string>

using namespace std;

int main ()
{
	string str;
	int sz, res;
	bool b;
	while (cin >> str && str != ".")
	{
		sz = str.length();
		res = 1;
		for (int I = 1; I < sz; I++)
			if (sz % I == 0)
			{
				string s (str.begin(), str.begin()+I);
				b = true;
				for (int J = I; b && J < sz; J += I)
				{
					string st (str.begin()+J, str.begin()+J+I);
					if (st != s)
						b = false;
				}
				if (b)
				{
					res = sz / I;
					break;
				}
			}
		cout << res << endl;
	}
	return 0;
}