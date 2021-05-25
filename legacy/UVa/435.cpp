#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string str;
int res[20];
int party[20];
int t, n, sum, major;

void powerindex(int ind)
{
	if (ind == n)
	{
		int tsum = 0;
		for (int I = 0; I < n; I++)
			if (str[I] == '1')
				tsum += party[I];
		if (tsum >= major)
		{
			for (int I = 0; I < n; I++)
				if (str[I] == '1' && tsum - party[I] < major)
					res[I]++;
		}
	}
	else
	{
		str[ind] = '0';
		powerindex(ind+1);
		str[ind] = '1';
		powerindex(ind+1);
	}
}

int main ()
{
	for (cin >> t; t && cin >> n; t--)
	{
		sum = 0;
		for (int I = 0; I < n && cin >> party[I]; I++)
			sum += party[I];
		major = (sum / 2.) + 0.5;
		str = string (n, '0');
		memset (res, 0, sizeof res);
		powerindex(0);
		for (int I = 0; I < n; I++)
			cout << "party " << I+1 << " has power index " << res[I] << endl;
		cout << endl;
	}
	return 0;
}