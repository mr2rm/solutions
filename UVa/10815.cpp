#include <iostream>
#include <string>
#include <set>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main ()
{
	string str, s;
	set <string> dic;
	set <string>::iterator it;
	unsigned int I, J, sz;
	while (cin >> str)
	{
		sz = str.length();
		for (J = 0, I = 0; J <= sz; J++)
		{
			if (J != sz && isalpha(str[J]))
				str[J] = tolower (str[J]);
			else
			{
				if (I != J)
				{
					s = str.substr (I, J-I);
					dic.insert (s);
				}
				I = J+1;
			}
		}
	}
	for (it = dic.begin(); it != dic.end(); it++)
		cout << *it << endl;
	return 0;
}
