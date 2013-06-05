#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>

#define PII pair <int, int>
using namespace std;

int main ()
{
	int n, maxi, res, tmp, last;
	string str, t1, t2;
	set < PII > s;
	set < PII >::iterator it;
	PII p;
	for (int t = 1; cin >> n; t++)
	{
		cin.ignore();
		s.clear();
		for (int I = 0; I < n; I++)
		{
			getline (cin, str);
			stringstream ss (str);
			ss >> t1 >> t2;
			p.first = 10*(t1[0]-'0') + (t1[1]-'0');
			p.first *= 60;
			p.first += 10*(t1[3]-'0') + (t1[4]-'0');
			p.second = 10*(t2[0]-'0') + (t2[1]-'0');
			p.second *= 60;
			p.second += 10*(t2[3]-'0') + (t2[4]-'0');
			s.insert (p);
		}
		p.first = 1080;
		p.second = -1;
		s.insert (p);
		maxi = 0;
		res = last = 600;
		for (it = s.begin(); it != s.end(); it++)
		{
			tmp = (*it).first - last;
			if (tmp > maxi)
			{	
				maxi = tmp;
				res = last;
			}
			last = (*it).second;
		}
		cout << "Day #" << t << ": the longest nap starts at ";
		printf ("%02d:%02d", res / 60, res % 60);
		cout << " and will last for ";
		if (maxi < 60)
			cout << maxi << " minutes." << endl;
		else
			cout << maxi / 60 << " hours and " << maxi % 60 << " minutes." << endl;
	}
	return 0;
}
