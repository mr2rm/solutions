#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

int mark[12], n, co, wstate, sum1, sum2;
string w[3][3];
bool b;
map <char, int> mp;

bool check ()
{
	sum1 = sum2 = 0;
	for (int J = 0; J < 3; J++)
		if (w[J][2] != "even")
		{
			sum1 = sum2 = 0;
			for (int K = 0; K < (int)w[J][0].size(); K++)
			{
				sum1 += mp[w[J][0][K]];
				sum2 += mp[w[J][1][K]];
			}
			if (sum1 == sum2 || (sum1 > sum2 && w[J][2] == "down") || (sum1 < sum2 && w[J][2] == "up"))
				return false;
		}
	return true;
}

int main()
{
	for (cin >> n; n; n--)
	{
		memset (mark, 0, sizeof mark);
		mp.clear();
		for (int I = 0; I < 3; I++)
			for (int J = 0; J < 3; J++)
				cin >> w[I][J];
		for (int I = 0; I < 3; I++)
			if (w[I][2] == "even")
			{
				string str = w[I][0] + w[I][1];
				for (int I = 0; I < (int)str.length(); I++)
					mark[str[I]-'A'] = 1;
			}
		wstate = 0;
		co = -1;
		for (int I = 0; I < 12; I++)
			if (!mark[I])
			{
				mp['A'+I] = 1;
				if (check())
				{
					co = I;
					wstate = 1;
					break;
				}
				else
				{
					mp['A'+I] = -1;
					if (check())
					{
						co = I;
						wstate = -1;
						break;
					}
					mp['A'+I] = 0;
				}
			}
		cout << (char)('A'+co) << " is the counterfeit coin and it is ";
		if (wstate == -1)
			cout << "light";
		else
			cout << "heavy";
		cout << "." << endl;
	}
	return 0;
}