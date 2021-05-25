#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main ()
{
	int t, sz, tmp;
	string str, res;
	for (cin >> t && cin.ignore(); t && getline (cin, str); t--)
	{
		sz = str.length();
		tmp = sqrt ((double)sz);
		if (tmp*tmp == sz)
		{
			res = "";
			for (int I = 0; I < tmp; I++)
				for (int J = I; J < (int)str.length(); J += tmp)
					res += str[J];
			cout << res << endl;
		}
		else
			cout << "INVALID" << endl;
	}
	return 0;
}