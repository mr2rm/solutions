#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main ()
{
	string str;
	int cc, ss, mm, hh;
	int trad;
	while (cin >> str)
	{
		hh = (str[0]-'0')*10 + (str[1]-'0');
		mm = (str[2]-'0')*10 + (str[3]-'0');
		ss = (str[4]-'0')*10 + (str[5]-'0');
		cc = (str[6]-'0')*10 + (str[7]-'0');
		trad = ((hh*60 + mm)*60 + ss)*100 + cc;
		trad = (double)trad*125./108.;
		printf ("%07d\n", trad);
	}
	return 0;
}
