#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

string str;
int n, m;
int in;
float fl;

string sum (string s1, string s2)
{
	int maxis = max (s1.length(), s2.length());
	string s01 (maxis - s1.length(), '0');	s1 = s01 + s1;
	string s02 (maxis - s2.length(), '0');	s2 = s02 + s2;
	int carry = 0;
	int t;
	for (int k = maxis - 1; k >= 0; k--)
	{
		t = (s1[k]-'0') + (s2[k]-'0') + carry;
		s1[k] = '0' + (t % 10);
		carry = t / 10;
	}
	if (carry != 0)
	{
		string car (1, ' ');
		car[0] = '0' + carry;
		s1 = car + s1;
	}
	return s1;
}

string bignum ()
{
	string s = "1";
	int t, carry;
	for (int i = 0; i < n; i++)
	{
		string ss = "0";
		for (int j = str.length() - 1; j >= 0; j--)
		{
			//multiply
			string ts (str.length()-j-1, '0');
			carry = 0;
			for (int k = s.length() - 1; k >= 0; k--)
			{
				t = (s[k] - '0') * (str[j] - '0');
				t += carry;
				ts.push_back ('0' + (t % 10));
				carry = t / 10;
			}
			if (carry != 0)	ts.push_back ('0' + carry);
			reverse (ts.begin(), ts.end());
			//sum
			ss = sum (ss, ts);
		}
		s = ss;
	}
	return s;
}

int main()
{
	while (cin >> fl >> n)
	{
		stringstream ss1;
		ss1 << fl;
		str = ss1.str();
		int i;
		for (i = 0; i < str.length(); i++)
			if (str[i] == '.')
				break;
		if (i != str.length())
		{
			str.erase (i, 1);
			m = str.length() - i;
			m *= n;
		}
		stringstream ss2 (str);
		ss2 >> in;
		stringstream ss3;
		ss3 << in;
		str = ss3.str();
		str = bignum ();
		if ( str.length() < m )
		{
			string st (m - str.length(), '0');
			str = st + str;
		}
		str.insert (str.end() - m, 1, '.');
		cout << str << endl;
	}
	return 0;
}