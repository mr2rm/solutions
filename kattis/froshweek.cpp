#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 1e6 + 13;
int n, arr[MAX_N], tmp[MAX_N];

ll inversion_index(int l, int r)
{
    if (l + 1 == r)
        return 0;
    int mid = (l + r) / 2;
    ll res = inversion_index(l, mid) + inversion_index(mid, r);
    for (int i = l, j = l, k = mid; i < r; ++i)
        if (j == mid)
            tmp[i] = arr[k++];
        else if (k == r)
            tmp[i] = arr[j++];
        else if (arr[j] <= arr[k])
            tmp[i] = arr[j++];
        else
            res += mid - j, tmp[i] = arr[k++];
    for (int i = l; i < r; ++i)
        arr[i] = tmp[i];
    return res;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << inversion_index(0, n) << endl;
    return 0;
}