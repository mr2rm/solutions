/*
ID: mohamma58
PROG: dualpal
LANG: C++
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

int main ()
{
	freopen ("dualpal.in", "r", stdin);
	freopen ("dualpal.out", "w", stdout);
	int n, s;
	cin >> n >> s;
	for (int i = s + 1; n != 0; i++)
	{
		int counter = 0;
		for (int j = 2; j <= 10 && counter < 2; j++)
		{
			int t = i;
			string str;
			while (t)
			{
				str.push_back ('0' + (t % j));
				t /= j;
			}
			string rstr = str;
			reverse (rstr.begin(), rstr.end());
			if (str == rstr)
				counter++;
		}
		if (counter >= 2)
		{
			cout << i << endl;
			n--;
		}
	}
	return 0;
}