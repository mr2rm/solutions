#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

int main ()
{
	int n, x, sum;
	long long res;
	while (cin >> n && n)
	{
		priority_queue <int, vector <int>, greater <int> > pq;
		res = 0;
		for (int I = 0; I < n; I++)
		{
			scanf ("%d", &x);
			pq.push (x);
		}
		while (pq.size() > 1)
		{
			sum = pq.top();		pq.pop();
			sum += pq.top();	pq.pop();
			pq.push (sum);
			res += sum;
		}
		cout << res << endl;
	}
	return 0;
}
