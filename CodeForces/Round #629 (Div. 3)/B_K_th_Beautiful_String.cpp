#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int t, n, k, i;
long long s, d;
string res, tail;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (i = 0; i < n - 1; ++i)
        {
            long long x = n - i - 1;
            s = x * (x + 1) / 2;
            if (s <= k)
            {
                d = k - s;
                break;
            }
        }

        if (d == 0)
            tail = 'b' + string(n - i - 2, 'a');
        else
        {
            i--, d--;
            tail = string(n - i - 2 - d, 'a') + 'b' + string(d, 'a');
        }

        res = string(i, 'a') + 'b' + tail;
        cout << res << endl;
    }
    return 0;
}