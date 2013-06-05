#include <iostream>
#include <string>

using namespace std;

bool leap (string str)
{
	int sz = str.length();
	int x;
	string s = string (str.begin() + sz - 2, str.end());
	if (s == "00")
		s = string (str.begin() + sz - 4, str.begin() + sz - 2);
	x = (s[0]-'0') * 10 + (s[1]-'0');
	if (x % 4 == 0)
		return true;
	return false;
}

bool bul (string str)
{
	int sz = str.length();
	int x;
	if (str[sz-1] == '0' || str[sz-1] == '5')
	{
		x = 0;
		for (int I = 0; I < sz; I++)
			x += (I % 2 ? -1 : 1) * (str[I]-'0');
		if (x % 11 == 0)
			return true;
	}
	return false;
}

bool hul (string str)
{
	int sz = str.length();
	int x;
	if (str[sz-1] == '0' || str[sz-1] == '5')
	{
		x = 0;
		for (int I = 0; I < sz; I++)
			x += (str[I]-'0');
		if (x % 3 == 0)
			return true;
	}
	return false;
}

int main ()
{
	bool ly, hf, bf;
	string str;
	for (int I = 0; cin >> str; I++)
	{
		if (I)
			cout << endl;
		ly = leap (str);
		bf = false;
		if (ly)	
			bf = bul (str);
		hf = hul (str);
		if (ly || hf)
		{
			if (ly)
				cout << "This is leap year." << endl;
			if (hf)
				cout << "This is huluculu festival year." << endl;
			if (bf)
				cout << "This is bulukulu festival year." << endl;
		}
		else
			cout << "This is an ordinary year." << endl;
	}
	return 0;
}
