#include <iostream>
#include <string>
#include <set>

using namespace std;

set <string> s1;
set <string> s2;
string str;
int len, now, size;
bool b;

void myfunc1 (int ind)
{
	if (ind == len)
	{
		s2.insert (str);
		return;
	}
	if (str[ind] == '*')
	{
		str[ind] = '0';	myfunc1 (ind+1);
		str[ind] = '1';	myfunc1 (ind+1);
		str[ind] = '*';
	}
	else
		myfunc1 (ind+1);
}

int main ()
{
	while (cin >> len >> now && (len || now))
	{
		s1.clear();
		s2.clear();
		b = true;
		for (int i = 0; i < now && cin >> str; i++)
		{
			if (!b)
				continue;
			string st = str;
			for (int j = 0; j < st.length(); j++)
				if (st[j] != '*')
					st[j] = '$';
			size = s1.size();
			s1.insert (st);
			if (s1.size() == size)
				b = false;
			myfunc1 (0);
		}
		if (!b)
			cout << "NO" << endl;
		else
			cout << "YES " << s2.size() << endl;
	}
	cout << "YES 0" << endl;
	return 0;
}