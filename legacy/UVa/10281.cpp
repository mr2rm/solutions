#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

string str;
int st, tt, sp;
double tmp, res;

int now ()
{
	int sum = 0;
	sum += ((str[1] - '0') + (str[0] - '0') * 10)*3600;
	sum += ((str[4] - '0') + (str[3] - '0') * 10)*60;
	sum += ((str[7] - '0') + (str[6] - '0') * 10);
	return sum;
}

int main ()
{
	st = 0;
	while (getline (cin, str))
	{
		if (str.length() == 8)
		{
			tt = now() - st;
			tmp = (double)tt * sp / 3600.;
			tmp += res;
			cout << str;
			printf (" %.2lf ", tmp);
			cout << "km" << endl;
		}
		else
		{
			tt = now();
			res += (double)sp * (tt - st) / 3600.;
			st = tt;
			sp = 0;
			string s (str.begin()+9, str.end());
			for (int I = 0; I < s.length(); I++)
				sp = (sp * 10) + (s[I] - '0');
		}
	}
	return 0;
}