#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 13;
int n, p;
int arr[MAX_N];

int solve(int l, int r)
{
    if (l + 1 == r)
        return arr[l];
    int mid = (l + r) / 2;
    int res = max(solve(l, mid), solve(mid, r));
    int lmax = INT_MIN, rmax = INT_MIN;
    for (int i = mid - 1, psum = 0; i >= l; --i)
        psum += arr[i], lmax = max(psum, lmax);
    for (int i = mid, psum = 0; i < r; ++i)
        psum += arr[i], rmax = max(psum, rmax);
    return max(res, lmax + rmax);
}

int main()
{
    cin >> n >> p;
    for (int i = 0; i < n; ++i)
        cin >> arr[i], arr[i] -= p;
    cout << solve(0, n) << endl;
    return 0;
}