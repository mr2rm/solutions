#include <bits/stdc++.h>

using namespace std;

const int MAX_T = 1e4 + 13;
int n, m, t, dp[MAX_T];

int main()
{
    while (cin >> n >> m >> t)
    {
        dp[0] = 0;
        for (int i = 1; i <= t; ++i)
        {
            dp[i] = -1;
            if (i >= n && dp[i - n] != -1)
                dp[i] = dp[i - n] + 1;
            if (i >= m && dp[i - m] != -1)
                dp[i] = max(dp[i], dp[i - m] + 1);
        }
        int res = t;
        while (dp[res] == -1)
            res--;
        cout << dp[res];
        int wasted = t - res;
        if (wasted)
            cout << ' ' << wasted;
        cout << endl;
    }
    return 0;
}