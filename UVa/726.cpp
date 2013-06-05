#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct ST
{
	char ch;
	int c;
	ST (int _c = 0, char _ch = 0)
	{
		ch = _ch;
		c = _c;
	}
	bool operator < (const ST & other) const
	{
		if (c == other.c)
			return ch > other.ch;
		return c < other.c;
	}
};

int main ()
{
	freopen ("C:\\Users\\Mohammad Reza\\Desktop\\A.txt", "r", stdin);
    freopen ("C:\\Users\\Mohammad Reza\\Desktop\\B.txt", "w", stdout);
    string known, decoded;
    map <char, int> mp;
    map <char, int>::iterator it;
    vector <ST> v1;
    vector <ST> v2;
    vector <string> vdcd;
    char F[256];
	int j;
    while (getline(cin, known) && known.length())
        for (int i = 0; i < known.length(); i++)
            if (isalpha(known[i]))
                mp[tolower(known[i])]++;
    for (it = mp.begin(); it != mp.end(); it++)
        v1.push_back(ST((*it).second, (*it).first));
    sort (v1.begin(), v1.end());
    mp.clear();
    while (getline(cin, decoded))
    {
        vdcd.push_back(decoded);
        for (int i = 0; i < decoded.length(); i++)
            if (isalpha(decoded[i]))
                mp[tolower(decoded[i])]++;
    }
    for (it = mp.begin(); it != mp.end(); it++)
        v2.push_back(ST((*it).second,(*it).first));
    sort (v2.begin(), v2.end());
	j = v1.size()-1;
    for (int i = v2.size()-1; i >= 0; i--, j--)
        F[v2[i].ch] = v1[j].ch;
    for (int i = 0; i < vdcd.size(); i++)
    {
        for (j = 0; j < vdcd[i].length(); j++)
        {
            if (isalpha(vdcd[i][j]))
                if (isupper(vdcd[i][j]))
                    cout << (char)(F[vdcd[i][j]+32]-32);
                else
                    cout << F[vdcd[i][j]];
            else
                cout << vdcd[i][j];
        }
        cout << endl;
    }
    return 0;
}
