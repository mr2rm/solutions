#include <iostream>
#include <string>
#include <map>

using namespace std;

int main ()
{
	string str, s;
	map <char, int> mp;
	int p = 'A';
	int step;
	for (int I = 0; I < 10; I++)
		if (I < 2)
			mp[(char)'0'+I] = I;
		else
		{
			step = 3;
			if (I == 7 || I == 9)
				step = step + 1;
			for (int J = 0; J < step; J++, p++)
				mp[(char)p] = I;
		}
	while (cin >> str)
	{
		for (int I = 0; I < str.length(); I++)
			if (str[I] == '-')
				cout << "-";
			else
				cout << mp[str[I]];
		cout << endl;
	}
	return 0;
}