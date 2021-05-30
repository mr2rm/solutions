#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, s;
ll dp[65 + 3][65 + 3][2 + 3];

ll solve(int i, int j, int l)
{
    if (dp[i][j][l] != -1)
        return dp[i][j][l];
    if (i == 0)
        return dp[i][j][l] = (j == 0);
    if (i < j)
        return dp[i][j][l] = 0;
    if (l)
    {
        dp[i][j][l] = solve(i - 1, j, 0);
        if (j > 0)
            dp[i][j][l] += solve(i - 1, j - 1, 1);
        return dp[i][j][l];
    }
    return dp[i][j][l] = solve(i - 1, j, 1) + solve(i - 1, j, 0);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    while (cin >> n >> s)
    {
        if (n + s < 0)
            break;
        cout << solve(n, s, 1) << endl;
    }
    return 0;
}