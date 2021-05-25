#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>

using namespace std;


int n, sz;
int a, b;
string input, st, str;
vector <int> mark;
//set <string> s;

void anagram (int ind)
{
	if (ind == sz)
		//s.insert (st);
		cout << st << endl;
	else
	{
		for (int I = 0; I < sz;)
			if (!mark[I])
			{
				mark[I] = 1;
				st[ind] = str[I];
				anagram (ind+1);
				mark[I] = 0;
				char ch = str[I];
				for (I++; I < sz && str[I] == ch; I++);
			}
			else
                I++;
	}
}

int main ()
{
	for (cin >> n; n && cin >> input; n--)
	{
		sz = input.length();
		st = string (sz, ' ');
		mark = vector <int> (sz, 0);
		//s.clear();
		//sort (str.begin(), str.end());
		str = "";
		for (int I = 'A'; I <= 'Z'; I++)
		{
			a = b = 0;
			for (int J = 0; J < sz; J++)
			{
				if ((int)input[J] == I)
					a++;
				else if ((int)input[J] == I + 32)
					b++;
			}
			string s1 (a, (char)I);
			string s2 (b, (char)I+32);
			str += s1 + s2;
		}
		anagram (0);
		/*
		for (set <string>::iterator it = s.begin(); it != s.end(); it++)
			cout << *it << endl;
		*/
	}
	return 0;
}
