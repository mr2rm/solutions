#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

string str, s, s1, s2;
vector <string> v;
bool b;

string to_lower (string st)
{
	for (int I = 0; I < st.length(); I++)
		st[I] = tolower(st[I]);
	sort (st.begin(), st.end());
	return st;
}

int main ()
{
	while (getline(cin, str) && str != "#")
	{
		stringstream ss (str);
		while (ss >> s)
			v.push_back(s);
	}
	sort (v.begin(), v.end());
	for (int I = 0; I < v.size(); I++)
	{
		if (v[I].length() == 1)
		{
			cout << v[I] << endl;
			continue;
		}
		b = false;
		s1 = to_lower(v[I]);
		for (int J = I + 1; J < v.size();)
		{
			s2 = to_lower(v[J]);
			if (s1 == s2)
			{
				b = true;
				v.erase(v.begin()+J);
			}
			else
				J++;
		}
		if (!b)
			cout << v[I] << endl;
	}
	return 0;
}
