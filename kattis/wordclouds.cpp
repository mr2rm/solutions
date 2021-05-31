#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 5e3 + 13;
int n, c;
int w[MAX_N], h[MAX_N], dp[MAX_N];

int solve(int i)
{
    if (dp[i] != -1)
        return dp[i];
    if (i == n)
        return dp[i] = 0;

    int sum_w = 0, max_h = 0, res = INT_MAX;
    for (int j = i; j < n; ++j)
    {
        sum_w += w[j];
        if (sum_w > c)
            break;
        max_h = max(max_h, h[j]);
        res = min(res, max_h + solve(j + 1));
    }
    return dp[i] = res;
}

int main()
{
    cin >> n >> c;
    for (int i = 0; i < n; ++i)
        cin >> w[i] >> h[i];

    // memset(dp, -1, sizeof(dp));
    // cout << solve(0) << endl;

    dp[n] = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        dp[i] = INT_MAX;
        int sum_w = 0, max_h = 0;
        for (int j = i; j < n; ++j)
        {
            sum_w += w[j];
            if (sum_w > c)
                break;
            max_h = max(max_h, h[j]);
            dp[i] = min(dp[i], max_h + dp[j + 1]);
        }
    }
    cout << dp[0] << endl;

    return 0;
}