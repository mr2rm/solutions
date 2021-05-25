#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int oprands[100];
int temp, tm;

int main ()
{
	int t, n, target;
	cin >> t;
	for (; t != 0 && cin >> n; t--)
	{
		string res;
		vector < vector <char> > dp (n, vector <char> (64001, ' '));
		for (int i = 0; i < n && cin >> oprands[i]; i++);
		cin >> target;
		dp[0][32000+oprands[0]] = 's';
		for (int i = 0; i < n - 1; i++)
			for (int j = 0; j < 64001; j++)
				if (dp[i][j] != ' ')
				{
					tm = j - 32000;
					temp = tm + oprands[i+1];
					if (temp >= -32000 && temp <= 32000)
						dp[i+1][temp+32000] = '+';
					temp = tm - oprands[i+1];
					if (temp >= -32000 && temp <= 32000)
						dp[i+1][temp+32000] = '-';
					temp = tm * oprands[i+1];
					if (temp >= -32000 && temp <= 32000)
						dp[i+1][temp+32000] = '*';
					temp = tm / oprands[i+1];
					if (temp == (double)tm / oprands[i+1])
						dp[i+1][temp+32000] = '/';
				}
		temp = target + 32000;
		if (dp[n-1][temp] == ' ')
			res = "NO EXPRESSION";
		else
		{
			for (int i = n - 1; i >= 0; i--)
			{	
				stringstream ss;
				ss << oprands[i];
				res = ss.str() + res;
				if (i != 0)
				{
					tm = temp;
					string s (1, dp[i][tm]);
					res = s + res;
					temp -= 32000;
					switch (dp[i][tm])
					{
						case '+':
							temp -= oprands[i];
							break;
						case '-':
							temp += oprands[i];
							break;
						case '*':
							temp /= oprands[i];
							break;
						case '/':
							temp *= oprands[i];
							break;
					}
					temp += 32000;
				}	
			}
			stringstream ss;
			ss << target;
			res += ("=" + ss.str());
		}
		cout << res << endl;
	}
	return 0;
}