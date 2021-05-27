#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5 + 13;
int n, m, k, arr[MAX_N];

bool check(int i)
{
    int cnt = m, rem = 0;
    for (int j = i; j < n; ++j)
    {
        rem -= arr[j];
        if (rem >= 0)
            continue;
        if (!cnt)
            return false;
        cnt--, rem = k - arr[j];
    }
    return true;
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int l = 0, r = n - 1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << n - l << endl;
    return 0;
}