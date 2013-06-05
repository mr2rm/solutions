#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

string str;
int mark[256];
int n, w;
bool b;

bool ptoz (int in)
{
    return (str[in] >= 'p' && str[in] <= 'z');
}

int main ()
{
    while (cin >> str)
    {
        memset (mark, -1, sizeof mark);
        n = str.length();
        reverse (str.begin(), str.end());
        b = true;
        for (int i = 0; b && i < n; i++)
        {
            if (ptoz(i))
                mark[i] = i;
            else
            {
                if (str[i] == 'N' && i > 0)
                    mark[i] = mark[i-1];
                else if (i > 1 && mark[i-1] > 0)
                    mark[i] = mark[mark[i-1]-1];
            }
            if (mark[i] == -1)
                b = false;
        }
        if (b)
        {
            w = 0;
            for (int i = n-1; i >= 0; i--)
            {
                w++;
                i = mark[i];
            }
            if (w > 1)
                b = false;
        }
        if (b)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
