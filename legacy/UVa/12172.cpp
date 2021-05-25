#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <string> dp1 (101);
vector <string>	dp2 (101);
int mathsticks[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

string mini (string s1, string s2)
{
	if (s1.length() == 0)
		return s2;
	if (s1.length() != s2.length())
		return s1.length() < s2.length() ? s1 : s2;
	return s1 < s2 ? s1 : s2;
}

string maxi (string s1, string s2)
{
	if (s1.length() == 0)
		return s2;
	if (s1.length() != s2.length())
		return s1.length() > s2.length() ? s1 : s2;
	return s1 > s2 ? s1 : s2;
}

int main ()
{
	for (int i = 2; i < 101; i++)
	{
		string m, M;
		int temp;
		for (int j = 0; j < 10; j++)
		{
			temp = i - mathsticks[j];
			string s (1, '0' + j);
			if (temp == 0 && j != 0)
			{
				m = mini (m, s);
				M = maxi (M, s);
			}	
			if (temp >= 2)
			{
				m = mini (m, dp1[temp] + s);
				M = maxi (M, dp2[temp] + s);
			}
		}
		dp1[i] = m;
		dp2[i] = M;
	}
	int t, n;
	cin >> t;
	for (; t != 0 && cin >> n; t--)
		cout << dp1[n] << " " << dp2[n] << endl;
	return 0;
}