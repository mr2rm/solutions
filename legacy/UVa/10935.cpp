#include <queue>
#include <iostream>

using namespace std;

int main ()
{
	int n;
	while (cin >> n && n)
	{
		queue <int> q;
		for (int I = 1; I <= n; I++)
			q.push (I);
		cout << "Discarded cards:";
		while (q.size() > 1)
		{
			cout << ' ' << q.front();
			q.pop();
			if (q.size() > 1)
			{
				cout << ',';
				q.push (q.front());
				q.pop();
			}
		}
		cout << endl << "Remaining card: " << q.front() << endl;
	}
	return 0;
}
