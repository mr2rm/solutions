#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main ()
{
	int n, sz;
	int b, sg, sb;
	int x, y, temp;
	for (cin >> n; n && cin >> b >> sg >> sb; n--)
	{
		priority_queue <int> gg, bb;
		vector <int> gv, bv;
		for (int i = 0; i < sg && cin >> temp; i++)
			gg.push(temp);
		for (int j = 0; j < sb && cin >> temp; j++)
			bb.push(temp);
		while (1)
		{
			if (!gg.size() || !bb.size())
				break;
			sz = b;
			if (gg.size() < b || bb.size() < b)
				sz = min (gg.size(), bb.size());
			gv.clear();
			bv.clear();
			for (; sz; sz--)
			{
				x = gg.top();
				y = bb.top();
				if (x > y)
					gv.push_back(x-y);
				else if (x < y)
					bv.push_back(y-x);
				gg.pop();
				bb.pop();
			}
			for (int i = 0; i < gv.size(); i++)
				gg.push(gv[i]);
			for (int j = 0; j < bv.size(); j++)
				bb.push(bv[j]);
		}
		temp = gg.size()+bb.size();
		if (!temp)
			cout << "green and blue died" << endl;
		else if (!gg.size())
		{
			cout << "blue wins" << endl;
			while (bb.size())
			{
				cout << bb.top() << endl;
				bb.pop();
			}
		}
		else
		{
			cout << "green wins" << endl;
			while (gg.size())
			{
				cout << gg.top() << endl;
				gg.pop();
			}
		}
		if (n > 1)
			cout << endl;
	}
	return 0;
}