#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

int n, sz;
string str, s;
set <string> SET;
set <string>::iterator it;
int mark[10];

void permute (int in)
{
    if (in == sz)
        SET.insert(s);
    else
    {
        for (int i = 0; i < sz; i++)
            if (mark[i] == 0)
            {
                mark[i] = 1;
                s[in] = str[i];
                permute (in+1);
                mark[i] = 0;
            }
    }
}

int main ()
{
    cin >> n;
    for (; n > 0 && cin >> str; n--)
    {
        sz = str.length();
        SET.clear();
        memset (mark, 0, sizeof mark);
        s = string (sz, ' ');
        permute (0);
        for (it = SET.begin(); it != SET.end(); it++)
            cout << *it << endl;
        cout << endl;
    }
    return 0;
}
