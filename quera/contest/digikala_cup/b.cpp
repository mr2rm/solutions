#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 1e3 + 13;
const int MOD = 1e9 + 7;
string s;
int l, r;
ll dp[MAX_N];

ll solve(int i)
{
    if (dp[i] != -1)
        return dp[i];
    if (i == s.size())
        return dp[i] = 1;
    if (s[i] == '0')
        return dp[i] = 0;
    ll res = 0;
    for (int j = i, x = 0; j < s.size(); ++j)
    {
        x = (x * 10) + (s[j] - '0');
        if (x >= r)
            break;
        if (x > l)
            res = (res + solve(j + 1)) % MOD;
    }
    return dp[i] = res;
}

int main()
{
    cin >> s >> l >> r;
    memset(dp, -1, sizeof(dp));
    cout << solve(0) << endl;
    return 0;
}