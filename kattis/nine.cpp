#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1e9 + 7;
int t;
ll d;

ll fast_power(int b, ll p)
{
    if (!p)
        return 1;
    if (p % 2)
        return (b * fast_power(b, p - 1)) % M;
    ll res = fast_power(b, p / 2);
    return (res * res) % M;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> d;
        cout << (8 * fast_power(9, d - 1)) % M << endl;
    }
    return 0;
}