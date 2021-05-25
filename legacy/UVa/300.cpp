#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main ()
{
	string haab[19] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
	string days[20] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
	int d, y, m, sum, T;
	string mon, da;
	cin >> T;
	cout << T << endl;
	for (int t = 0; t < T && cin >> da >> mon >> y; t++)
	{
		da.erase(da.length()-1, 1);
		stringstream ss (da);
		ss >> d;
		for (int I = 0; I < 19; I++)
			if (haab[I] == mon)
			{
				m = I;
				break;
			}
		sum = y*365 + m*20 + d;
		y = sum / 260;
		d = (sum % 13) + 1;
		m = sum % 20;
		mon = days[m];
		cout << d << " " << mon << " " << y << endl;
	}
	return 0;
}