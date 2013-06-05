#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

int main ()
{
	string s, pn;
	char cs;
	int start, end, tmp;
	int h, m, ind, cost, x;
	int sched[][3] = {{10, 6, 2}, {25, 15, 5}, {53, 33, 13}, {87, 47, 17}, {144, 80, 30}};
	int arr[] = {0, 8*60, 18*60, 22*60, 24*60};
	int index[] = {2, 0, 1, 2, 0};
	int charge[3];
	while (getline(cin, s) && s != "#")
	{
		stringstream ss (s);
		ss >> cs >> pn;
		ss >> h >> m;
		start = h*60 + m;
		ss >> h >> m;
		end = h*60 + m;
		x = cs-'A';
		for (ind = 0; ind < 5; ind++)
			if (start >= arr[ind] && start < arr[ind+1])
				break;
		memset (charge, 0, sizeof charge);
		cost = 0;
		if(end <= start)
		{
			for (int I = ind; I < 4; I++)
			{
				tmp = arr[I+1] - start;
				charge[index[I]] += tmp;
				cost += sched[x][index[I]] * tmp;
				start = arr[I+1];
			}
			ind = start = 0;
		}
		for (int I = ind; I < 4 && start < end; I++)
		{
			if (arr[I+1] <= end)
				tmp = arr[I+1] - start;
			else
				tmp = end - start;
			charge[index[I]] += tmp;
			cost += sched[x][index[I]] * tmp;
			start = arr[I+1];
		}
		cout << "  " << pn;
		printf ("%6d%6d%6d%3c%8.2lf\n", charge[0], charge[1], charge[2], cs, (float)cost / 100.);
	}
	return 0;
}
