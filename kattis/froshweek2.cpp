#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 13;
int n, m, t[MAX_N], l[MAX_N];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> t[i];
    for (int i = 0; i < m; ++i)
        cin >> l[i];
    sort(t, t + n), sort(l, l + m);
    int r;
    for (int i = 0; r < n && i < m; ++i)
        if (t[r] <= l[i])
            r++;
    cout << r << endl;
    return 0;
}