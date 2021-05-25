#include <iostream>
#include <list>
#include <utility>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdio>

#define PII pair <int, int>
#define inf 1000000

using namespace std;

int gcd (int a, int b)
{
	if (a % b)
		return gcd (b, a % b);
	else
		return b;
}

int main ()
{
	int x, y, g;
	long long a, b;
	PII p1, p2;
	set < PII > pt;
	set < PII >::iterator itI, itJ;
	set < pair < PII, PII > > ln;
	set < pair < PII, PII > >::iterator it;
	vector < vector < PII > > res;
	while (cin >> x >> y && x+y)
	{
		pt.clear();	ln.clear();	res.clear();
		pt.insert (make_pair (x, y));
		while (cin >> x >> y && x+y)
			pt.insert (make_pair (x, y));
		for (itI = pt.begin(); itI != pt.end(); itI++)
			for (itJ = itI, itJ++; itJ != pt.end(); itJ++)
			{
				x = (*itJ).first - (*itI).first;
				if (!x)
				{
					p1.first = p1.second = inf;
					p2.first = (*itI).first;
					p2.second = inf;
				}
				else
				{
					p1.first = (*itJ).second - (*itI).second;
					p2.first = ((*itI).second * (*itJ).first) - ((*itI).first * (*itJ).second);
					p1.second = p2.second = x;
					if (p1.first)
					{
						g = gcd (max(p1.first, x), min(p1.first, x));
						p1.first /= g;
						p1.second /= g;
					}
					else
						p1.second = inf;
					if (p2.first)
					{
						g = gcd (max(p2.first, x), min(p2.first, x));
						p2.first /= g;
						p2.second /= g;
					}
					else
						p2.second = inf;
				}
				ln.insert (make_pair(p1, p2));
			}
		for (it = ln.begin(); it != ln.end(); it++)
		{
			vector < PII > v;
			if ((*it).first.first == inf && (*it).first.second == inf)
			{
				x = (*it).second.first;
				for (itI = pt.begin(); itI != pt.end(); itI++)
					if ((*itI).first == x)
						v.push_back (*itI);
			}
			else
			{
				for (itI = pt.begin(); itI != pt.end(); itI++)
				{
					a = (*it).first.first * (*it).second.second * (*itI).first;
					b = (*it).first.second * (((*it).second.second * (*itI).second) - (*it).second.first);
					if (a == b)
						v.push_back (*itI);
				}
			}
			if (v.size() > 2)
				res.push_back (v);
		}
		if (res.size())
		{
			sort (res.begin(), res.end());
			cout << "The following lines were found:" << endl;
			for (int I = 0; I < (int)res.size(); I++)
			{
				for (int J = 0; J < (int)res[I].size(); J++)
					printf ("(%4d,%4d)", res[I][J].first, res[I][J].second);
				cout << endl;
			}
		}
		else
			cout << "No lines were found" << endl;
	}
	return 0;
}