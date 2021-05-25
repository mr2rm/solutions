#include <iostream>
#include <string>

using namespace std;

int t;
string str;
//string alpha = "abcdefghijklmnopqrstuvwxyz";
string press = "12312312312312312341231234";

int main ()
{
	cin >> t;
	getline (cin, str);
	for (int test = 1; test <= t && getline (cin, str); test++)
	{
		int sum = 0;
		for (int i = 0; i < str.length(); i++)
			if (str[i] == ' ')
				sum++;
			else
				sum += press[str[i]-'a'] - '0';
		cout << "Case #" << test << ": " << sum << endl;
	}
	return 0;
}