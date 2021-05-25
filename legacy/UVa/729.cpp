#include <string>
#include <iostream>
#include <set>
#include <cmath>

using namespace std;

set <string> s;
string str;
int n, h;

void recursive (int i, int cnt1)
{
	if (i == n)
	{
		//use for classic check the number of 1's without cnt1
		/*
		int sum = 0;
		for (int j = 0; j < n; j++)
			if (str[j] == '1')
				sum++;
		if (sum == h)
			s.insert (str);
		*/
		if (cnt1 == h)
			s.insert (str);
		return;
	}

	//for backtracking
	if (cnt1 > h)
		return;

	str[i] = '0';
	recursive (i+1, cnt1);
	str[i] = '1';
	recursive (i+1, cnt1+1);
}

void binary ()
{
	int m = pow (2., n);
	for (int i = 0; i < m; i++)
	{
		int temp = i;
		string st (n, '0');
		for (int j = 0; j < n && temp != 0; j++)
		{
			int tt = pow (2., n-1-j);
			if (temp >= tt)
			{
				temp -= tt;
				st[j] = '1';
			}
		}
		int sum = 0;
		for (int j = 0; j < n; j++)
			if (st[j] == '1')
				sum++;
		if (sum == h)
			s.insert (st);
	}
}

int main ()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t && cin >> n >> h; i++)
	{
		s.clear ();
		str.resize (n, ' ');
		recursive (0, 0);
		//binary ();
		for (set <string>::iterator it = s.begin(); it != s.end(); it++)
			cout << *it << endl;
		if (i != t)
			cout << endl;
	}
	return 0;
}