#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;
string s;
bool printed = false;

void solve(int i, int d)
{
    s[i] = '0' + d;
    if (i == n - 1)
    {
        if (printed)
            cout << ',';
        else
            printed = true;
        cout << s;
        return;
    }
    if (d - k >= 0)
        solve(i + 1, d - k);
    if (d + k <= 9)
        solve(i + 1, d + k);
}

int main()
{
    cin >> n >> k;
    s.resize(n);
    for (int d = 1; d <= 9; ++d)
        solve(0, d);
    if (printed)
        cout << endl;
    return 0;
}