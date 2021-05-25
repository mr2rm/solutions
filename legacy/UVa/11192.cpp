#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int g;
	string str;
	while (cin >> g && g != 0 && cin >> str)
	{
		int s = str.length() / g;
		for (int i = 0; i < str.length(); i += s)
			reverse (str.begin() + i, str.begin() + i + s);
		cout << str << endl;
	}
	return 0;
}