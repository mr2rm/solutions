#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main ()
{
	int n, m;
	string str, sstr, tstr, sdig, tdig;
	bool b;
	for (int t = 1; cin >> n && n; t++)
	{
		sstr = tstr = tdig = sdig = "";
		cin.ignore();
		for (int I = 0; I < n; I++)
		{
			getline (cin, str);
			sstr += str;
			for (unsigned int J = 0; J < str.length(); J++)
				if (isdigit(str[J]))
					sdig += str[J];
		}
		cin >> m;
		cin.ignore();
		for (int I = 0; I < m; I++)
		{
			getline (cin, str);
			tstr += str;
			for (unsigned int J = 0; J < str.length(); J++)
				if (isdigit(str[J]))
					tdig += str[J];
		}
		cout << "Run #" << t << ": ";	
		if (n == m && sstr == tstr)
			cout << "Accepted" << endl;
		else if (sdig == tdig)
			cout << "Presentation Error" << endl;
		else
			cout << "Wrong Answer" << endl;
	}
	return 0;
}