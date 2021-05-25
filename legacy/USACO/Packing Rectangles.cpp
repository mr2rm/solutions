/*
ID: Blackwizard
PROG: packrec
LANG: C++
*/
#include <iostream>
#include <utility>
#include <vector>
#include <cstring>
#include <set>
#include <cstdio>

#define fir first
#define sec second

using namespace std;

vector < pair <int, int> > rec(4);
//set < pair < int , pair <int, int> > > res;
set < pair <int, int> > ans;
int mark[4] = {0};
int h[4] = {0};
int w[4] = {0};
int res;

void lay_1 (int x, int w, int h)
{
	if (x == 4)
	{
		if (w*h < res)
		{
			ans.clear();
			res = w*h;
		}
		if (w*h == res)
			ans.insert(make_pair (min(w, h), max(w, h)));
	}
	else
		for (int I = 0; I < 4; I++)
			if (!mark[I])
			{
				mark[I] = 1;
				lay_1 (x+1, w + rec[I].fir, max(h, rec[I].sec));
				lay_1 (x+1, w + rec[I].sec, max(h, rec[I].fir));
				mark[I] = 0;
			}
}

void lay_2 (int x, int w, int h)
{
	if (x == 4)
	{
		if (w*h < res)
		{
			ans.clear();
			res = w*h;
		}
		if (w*h == res)
			ans.insert(make_pair (min(w, h), max(w, h)));
	}
	else
		for (int I = 0; I < 4; I++)
			if (!mark[I])
			{
				mark[I] = 1;
				if (x < 3)
				{
					lay_2 (x+1, w + rec[I].fir, max(h, rec[I].sec));
					lay_2 (x+1, w + rec[I].sec, max(h, rec[I].fir));
				}
				else
				{
					lay_2 (x+1, max(w, rec[I].fir), h + rec[I].sec);
					lay_2 (x+1, max(w, rec[I].sec), h + rec[I].fir);
				}
				mark[I] = 0;
			}
}

void lay_3 (int x, int w, int h)
{
	if (x == 4)
	{
		if (w*h < res)
		{
			ans.clear();
			res = w*h;
		}
		if (w*h == res)
			ans.insert(make_pair (min(w, h), max(w, h)));
	}
	else
		for (int I = 0; I < 4; I++)
			if (!mark[I])
			{
				mark[I] = 1;
				if (x < 2)
				{
					lay_3 (x+1, w + rec[I].fir, max(h, rec[I].sec));
					lay_3 (x+1, w + rec[I].sec, max(h, rec[I].fir));
				}
				else if (x == 2)
				{
					lay_3 (x+1, max(w, rec[I].fir), h + rec[I].sec);
					lay_3 (x+1, max(w, rec[I].sec), h + rec[I].fir);
				}
				else
				{
					lay_3 (x+1, w + rec[I].fir, max(h, rec[I].sec));
					lay_3 (x+1, w + rec[I].sec, max(h, rec[I].fir));
				}
				mark[I] = 0;
			}
}

void lay_4 (int x, int w, int h)
{
	if (x == 4)
	{
		if (w*h < res)
		{
			ans.clear();
			res = w*h;
		}
		if (w*h == res)
			ans.insert(make_pair (min(w, h), max(w, h)));
	}
	else
		for (int I = 0; I < 4; I++)
			if (!mark[I])
			{
				mark[I] = 1;
				if (x < 2)
				{
					lay_4 (x+1, max(w, rec[I].fir), h + rec[I].sec);
					lay_4 (x+1, max(w, rec[I].sec), h + rec[I].fir);
				}
				else
				{
					lay_4 (x+1, w + rec[I].fir, max(h, rec[I].sec));
					lay_4 (x+1, w + rec[I].sec, max(h, rec[I].fir));
				}
				mark[I] = 0;
			}
}

void lay_5 (int x)
{
	if (x == 4)
	{
		int H = max(h[0] + h[2], h[1] + h[3]);
		int W;
		if (h[2] >= h[1] + h[3])
			W = max(w[0], w[2] + max(w[1], w[3]));
		else if (h[3] < h[2])
			W = max(w[0] + w[1], max(w[1] + w[2], w[2] + w[3]));
		else if (h[3] > h[2])
		{
			if (h[0] + h[2] <= h[3])
				W = max(w[1], max(w[2], w[0]) + w[3]);
			else
				W = max(w[0] + w[1], max(w[0] + w[3], w[3] + w[2]));
		}
		else
			W = max(w[2] + w[3], w[0] + w[1]);
		if (W*H < res)
		{
			ans.clear();
			res = W*H;
		}
		if (W*H == res)
			ans.insert(make_pair (min(W, H), max(W, H)));
	}
	else
		for (int I = 0; I < 4; I++)
			if (!mark[I])
			{
				mark[I] = 1;
				h[x] = rec[I].fir;
				w[x] = rec[I].sec;
				lay_5 (x+1);
				swap (h[x], w[x]);
				lay_5 (x+1);
				mark[I] = 0;
			}
}

int main ()
{
	freopen ("packrec.in", "r", stdin);
	freopen ("packrec.out", "w", stdout);
	for (int I = 0; I < 4 && cin >> rec[I].fir >> rec[I].sec; I++);
	res = 1000000;
	lay_1 (0, 0, 0);
	lay_2 (0, 0, 0);
	lay_3 (0, 0, 0);
	lay_4 (0, 0, 0);
	lay_5 (0);
	cout << res << endl;
	for (set < pair <int, int> >::iterator it = ans.begin(); it != ans.end(); it++)
		cout << (*it).fir << " " << (*it).sec << endl;
	return 0;
}
