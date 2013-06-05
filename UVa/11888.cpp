#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*//TLE
bool palin (string str)
{
	string s = str;
	reverse (s.begin(), s.end());
	if (s == str)
		return true;
	return false;
}
int main ()
{
	string str;
	int t;
	cin >> t;
	bool b;
	while (t-- && cin >> str)
	{
		b = false;
		for (unsigned int I = 1; I < str.length(); I++)
			if (palin(string(str.begin(), str.begin()+I)) && palin(string(str.begin()+I, str.end())))
			{
				b = true;
				break;
			}
		if (b)
			cout << "alindrome" << endl;
		else if (palin(str))
			cout << "palindrome" << endl;
		else
			cout << "simple" << endl;
	}
	return 0;
}
*/

/*//TLE
int main ()
{
	int t, sz;
	string str, rev;
	cin >> t;
	bool b;
	while (t-- && cin >> str)
	{
		rev = str;
		reverse (rev.begin(), rev.end());
		sz = str.length();
		b = false;
		for (int I = 1; I < sz; I++)
			if(string (str.begin(), str.begin()+I) == string (rev.end()-I, rev.end()))
				if (string (str.begin()+I, str.end()) == string (rev.begin(), rev.end()-I))
				{
					b = true;
					break;
				}
		if (b)
			cout << "alindrome" << endl;
		else if (rev == str)
			cout << "palindrome" << endl;
		else
			cout << "simple" << endl;
	}
	return 0;
}
*/

string str;
bool palin (int x, int y)
{
	y--;
	for (; x < y; x++, y--)
		if (str[x] != str[y])
			return false;
	return true;
}
int main ()
{
	int t, sz;
	bool b;
	cin >> t;
	while (t-- && cin >> str)
	{
		sz = str.length();
		b = false;
		for (int I = 1; I < sz; I++)
			if (palin(0, I) && palin(I, sz))
			{
				b = true;
				break;
			}
		if (b)
			cout << "alindrome" << endl;
		else if (palin(0, sz))
			cout << "palindrome" << endl;
		else
			cout << "simple" << endl;
	}
	return 0;
}
