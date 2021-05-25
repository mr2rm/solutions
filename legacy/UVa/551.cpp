#include <iostream>
#include <stack>
#include <string>
#include <map>

using namespace std;

/*
string str;
int size, pos;
bool b;

int main ()
{
	while (getline (cin, str))
	{
		size = str.length();
		stack <string> st;
		pos = 0;
		b = true;
		for (int i = 0; b && i < size; i++)
		{
			string s;
			switch (str[i])
			{
				case '(':
					s = "(";
					if (i + 1 < size && str[i+1] == '*')
					{
						s += "*";
						i++;
					}
					st.push (s);
					break;
				case '{':
				case '[':
				case '<':
					s = string (1, str[i]);
					st.push (s);
					break;
				case ')':
					s = ")";
					if (i - 1 >= 0 && str[i-1] == '*' && (i == 1 || str[i-2] != '('))
					{
						s = "*" + s;
						pos--;
					}
					if (!st.empty() && 
						( (s == ")" && st.top () == "(") || (s == "*)" && st.top () == "(*") )
						)
						st.pop ();
					else
						b = false;
					break;
				case '}':
					if (!st.empty () && st.top () == "{")
						st.pop ();
					else
						b = false;
					break;
				case ']':
					if (!st.empty () && st.top () == "[")
						st.pop ();
					else
						b = false;
					break;
				case '>':
					if (!st.empty () && st.top () == "<")
						st.pop ();
					else
						b = false;
					break;
			}
			pos++;
		}
		if (b)
			if (st.empty())
				cout << "YES" << endl;
			else
				cout << "NO " << pos + 1 << endl;
		else
			cout << "NO " << pos << endl;
	}
	return 0;
}
*/

int main ()
{
	map <string, string> mp;
	mp[")"] = "(";
	mp["]"] = "[";
	mp[">"] = "<";
	mp["}"] = "{";
	mp["*)"] = "(*";
	string str;
	int res;
	bool b;
	while (getline(cin, str))
	{
		stack <string> st;
		res = 0;
		b = true;
		for (unsigned int I = 0; I < str.length(); I++)
		{
			res++;
			if (str[I] == '[' || str[I] == '<' || str[I] == '{' || str[I] == '(')
			{
				string s (1, str[I]);
				if (str[I] == '(' && I < str.length()-1 && str[I+1] == '*')
				{
					s += "*";
					I++;
				}
				st.push (s);
			}
			else
			{
				string s (1, str[I]);
				if (str[I] == '*' && I < str.length()-1 && str[I+1] == ')')
				{
					I++;
					s += ")";
				}
				if (mp[s] != "")
				{
					if (st.empty() || st.top() != mp[s])
					{
						b = false;
						break;
					}
					st.pop();
				}
			}
		}
		if (b && st.empty())
			cout << "YES" << endl;
		else
		{
			cout << "NO ";
			if (b) res++;
			cout << res << endl;
		}
	}
	return 0;
}
