#include <iostream>
#include <string>
#include <vector>

using namespace std;

string rule, word, str;

void passwords (int x)
{
	if (x == rule.length())
	{
		cout << str << endl;
		return;
	}
	if (rule[x] == '#')
	{
		str += word;
		passwords (x+1);
		str = string (str.begin(), str.end()-word.length());
	}
	else
	{
		str += " ";
		for (int i = 0; i <= 9; i++)
		{
			str[str.length()-1] = '0'+i;
			passwords (x+1);
		}
		str = string (str.begin(), str.end()-1);
	}
}

int main ()
{
	freopen ("test.in", "r", stdin);
	int n, m;
	while (cin >> n)
	{
		cout << "--" << endl;
		vector <string> words (n);
		for (int i = 0; i < n; i++)
			cin >> words[i];
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> rule;
			for (int j = 0; j < n; j++)
			{
				word = words[j];
				str = "";
				passwords(0);
			}
		}
	}
	return 0;
}