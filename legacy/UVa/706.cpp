#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <string> v (10);

int main ()
{
	v[0] = " - | |   | | - ";
	v[1] = "     |     |   ";
	v[2] = " -   | - |   - ";
	v[3] = " -   | -   | - ";
	v[4] = "   | | -   |   ";
	v[5] = " - |   -   | - ";
	v[6] = " - |   - | | - ";
	v[7] = " -   |     |   ";
	v[8] = " - | | - | | - ";
	v[9] = " - | | -   | - ";
	int sz, tm;
	string n, str;
	while (cin >> sz >> n && sz)
	{
		for (int i = 0; i < 5; i++)
		{
			string s;
			tm = i * 3;
			for (int j = 0; j < n.length(); j++)
			{
				str = v[n[j]-'0'];
				str = string (str.begin()+tm, str.begin()+tm+3);
				s += str[0] + string (sz, str[1]) + str[2];
				if (j != n.length()-1)
					s += " ";
			}
			if (i % 2)
				for (int j = 0; j < sz; j++)
					cout << s << endl;
			else
				cout << s << endl;
		}
		cout << endl;
	}
	return 0;
}