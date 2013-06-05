#include <iostream>
#include <map>
#include <climits>

using namespace std;

map <long long, long long> mp;
int l, h, res;
long long sum, maxi, temp;
int s, e;

/*//perfect memoize
void ackermann (long long x)
{
	long long tmp;
	if (x % 2)
		tmp = (3 * x) + 1;
	else
		tmp = x / 2;
	if (tmp == 1)
		mp[x] = 1;
	else
	{
		if (!mp[tmp])
			ackermann (tmp);
		mp[x] = mp[tmp] + 1;
	}
}
//*/

int main ()
{
	/*//Pre-Computing
	for (int I = 1; I <= INT_MAX; I++)
		ackermann (I);
	*/
	while (cin >> l >> h && l + h)
	{
		s = min (l, h);
		e = max (l, h);
		maxi = res = 0;
		for (int I = s; I <= e; I++)
		{
			/*//bruteforce
			sum = 0;
			temp = I;
			do
			{
				if (temp % 2)
					temp = (3*temp) + 1;
				else
					temp /= 2;
				sum++;
			}
			while (temp != 1);
			if (sum > maxi)
			{
				maxi = sum;
				res = I;
			}
			*/
			/*//simple memoize
			if (!mp[I])
			{
				temp = I;
				sum = 0;
				do
				{
					if (temp % 2)
						temp = (temp * 3) + 1;
					else
						temp /= 2;
					sum++;
				}
				while(temp != 1);
				mp[I] = sum;
			}
			if (mp[I] > maxi)
			{
				maxi = mp[I];
				res = I;
			}
			*/
			/*//perfect memoize
			if (!mp[I])
				ackermann (I);
			if (mp[I] > maxi)
			{
				res = I;
				maxi = mp[I];
			}
			*/
		}
		cout << "Between " << s << " and " << e << ", " << res << " generates the longest sequence of " << maxi << " values." << endl;
	}
	return 0;
}

