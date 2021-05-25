#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int n, t;
int arr[20];
int res;

int main ()
{
	while (cin >> n >> t)
	{
		for (int i = 0; i < t; i++)
			cin >> arr[i];
		int maxi = pow (2., t);
		res = -1;
		vector <int> R;
		vector <int> T;
		for (int i = 0; i < maxi; i++)
		{
			int sum = 0;
			T.clear ();
			for (int j = 0; j < t; j++)
			{
				int temp = i & (1 << j);
				if (temp != 0)
				{
					sum += arr[j];
					T.push_back (arr[j]);
				}
			}
			if (sum <= n && sum > res)
			{
				res = sum;
				R = vector <int> (T.begin(), T.end());
			}
		}
		for (int i = 0; i < R.size(); i++)
			cout << R[i] << " ";
		cout << "sum:" << res << endl;	
	}
	return 0;
}