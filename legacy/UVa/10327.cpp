#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
	int n;
	while (cin >> n)
	{
		vector <int> v (n);
		for (int i = 0;i < n; i++)
			cin >> v[i];
		int Res = 0;
		for (int c = 1; c <= n-1; c++)
			for (int i = 0; i < n-1; i++)
				if (v[i] > v[i+1])
				{
					swap (v[i], v[i+1]);
					Res++;
				}
		cout << "Minimum exchange operations : " << Res << endl;
	}
	return 0;
}
