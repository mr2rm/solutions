#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		int j = -1;
		bool b = true;
		for (int i = 0; i < s.length() && b; i++)
		{
			for (j++; j < t.length() && t[j] != s[i]; j++);
			if (j == t.length())
				b = false;
		}
		if (b)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}