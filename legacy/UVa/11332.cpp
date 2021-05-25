#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		while (n/10 != 0)
		{
			stringstream ss;
			ss << n;
			n = 0;
			string str = ss.str();
			for (int i = 0; i < str.length(); i++)
				n += str[i]-'0';
		}
		cout << n << endl;
	}
	return 0;
}