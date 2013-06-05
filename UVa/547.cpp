#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

vector <string> dp1 (3001);
int dp2[3001] = {0};

void dpfunc (int x)
{
	if (dp2[x])
		return;
	int maxi = sqrt ((double)x);
	int sum = 0;
	stringstream ss;
	for (int i = 1; i <= maxi; i++)
		if (x % i == 0)
		{
			ss << i;
			int tm = x / i;
			if (tm != i)
				ss << tm;
		}
	string str = ss.str();
	for (int i = 0; i < str.length(); i++)
		sum += str[i]-'0';
	stringstream sx;
	sx << x;
	if (sum == x)
	{
		dp1[x] = " " + sx.str();
		dp2[x] = 1;
	}
	else
	{
		dpfunc (sum);
		dp1[x] = " " + sx.str() + dp1[sum];
		dp2[x] = dp2[sum] + 1;
	}
}

int main ()
{
	dp1[0] = " 0";
	dp1[1] = " 1";
	dp2[0] = dp2[1] = 1;
	for (int i = 2; i < 3001; i++)
		dpfunc (i);
	int n, m;
	for (int t = 1; cin >> n >> m; t++)
	{
		cout << "Input" << t << ": " << n << " " << m << endl;
		int s = min (n, m);
		int e = max (n, m);
		int lst = -1;
		int lst_in;
		for (int i = s; i <= e; i++)
			if (dp2[i] > lst)
			{
				lst = dp2[i];
				lst_in = i;
			}
		cout << "Output" << t << ":" << dp1[lst_in] << endl;
	}
	return 0;
}

//bruteforce ---> TLE
/*
int main ()
{
	int n, m, temp, sum;
	for (int t = 1; cin >> n >> m; t++)
	{
		cout << "Input" << t << ": " << n << " " << m << endl;
		n = min (n, m);
		m = max (n, m);
		int lst = -1;
		string res;
		for (int i = n; i <= m; i++)
		{
			vector <string> v;
			temp = i;
			while (1)
			{
				stringstream ss;
				stringstream s;
				s << temp;
				v.push_back (s.str());
				int maxi = sqrt ((double)temp);
				ss << temp;
				if (temp > 1)
					ss << 1;
				for (int j = 2; j <= maxi; j++)
					if (temp % j == 0)
					{
						ss << j;
						int tm = temp / j;
						if (tm != j)
							ss << tm;
					}
				string str = ss.str();
				sum = 0;
				for (int j = 0; j < str.length(); j++)
					sum += str[j]-'0';
				if (sum == temp)
					break;
				temp = sum;
			}
			if ((int)v.size() > lst)
			{
				lst = v.size();
				res = "";
				for (int j = 0; j < lst; j++)
					res += (" " + v[j]);
			}
		}
		cout << "Output" << t << ":" << res << endl;
	}
	return 0;
}
*/