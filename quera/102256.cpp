#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 1e5 + 13;
const ll MOD = 1e9 + 7;
ll n, k, arr[MAX_N];

ll sum(ll x)
{
    return x * (x + 1) / 2;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cin >> k;

    ll res = 0;
    sort(arr, arr + n);
    for (int i = n - 1; i >= 0; --i)
    {
        i = lower_bound(arr, arr + i, arr[i]) - arr;
        ll prev = i > 0 ? arr[i - 1] : 0, m = n - i;
        ll buys = m * (arr[i] - prev);
        if (buys > k)
        {
            ll x = arr[i] - k / m;
            res += (m * (sum(arr[i]) - sum(x))) % MOD;
            res += (x * (k % m)) % MOD;
            res %= MOD;
            break;
        }
        res += (m * (sum(arr[i]) - sum(prev))) % MOD;
        res %= MOD;
        k -= buys;
    }
    cout << res << endl;
    return 0;
}