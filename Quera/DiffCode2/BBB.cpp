#include <iostream>
#include <string>

using namespace std;

int n;

void solve(string s, int x)
{
    if (x > n)
    {
        cout << s + " }" << endl;
        return;
    }
    solve(s + ' ' + to_string(x), x + 1);
    solve(s, x + 1);
}

int main()
{
    cin >> n;
    solve("{", 1);

    /* WA */
    // for (int x = 0; x < (1 << n); ++x)
    // {
    //     int t = x;
    //     string res = "{";
    //     for (int i = 0, t = x; t; t = t >> 1, ++i)
    //         if (t & 1)
    //             res += ' ' + to_string(i + 1);
    //     res += " }";
    //     cout << res << endl;
    // }

    return 0;
}