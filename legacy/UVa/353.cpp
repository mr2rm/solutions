#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main ()
{
	string str, s2, s1;
	set <string> s;
	while (cin >> str)
	{
		s.clear();
		for (int I = 0; I < str.length(); I++)
		{
			s1 = s2 = "";
			for (int J = I; J < str.length(); J++)
			{
				s1.insert (s1.end(), str[J]);
				s2.insert (s2.begin(), str[J]);
				if (s1 == s2)
					s.insert(s1);
			}
		}
		cout << "The string '" << str << "' contains " << s.size() << " palindromes." << endl;
	}
	return 0;
}