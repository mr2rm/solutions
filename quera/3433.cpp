#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = (1 << 17) + 13;
int n;
int arr[MAX_N];

ll solve(int l, int r)
{
    if (l + 1 == r)
        return arr[l];
    int mid = (l + r) / 2;
    ll lwin = solve(l, mid) + *max_element(arr + mid, arr + r);
    ll rwin = solve(mid, r) + *max_element(arr + l, arr + mid);
    return max(lwin, rwin);
}

int main()
{
    cin >> n;
    n = 1 << n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << solve(0, n) << endl;
    return 0;
}
