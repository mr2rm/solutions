#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int main ()
{
	string str, s1, s2;
	map <string, string> mp;
	while (getline (cin, str) && str != "")
	{
		stringstream ss (str);
		ss >> s1 >> s2;
		mp[s2] = s1;
	}
	while (cin >> str)
	{
		if (mp[str] == "")
			cout << "eh" << endl;
		else
			cout << mp[str] << endl;
	}
	return 0;
}