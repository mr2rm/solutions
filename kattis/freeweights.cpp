#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 1e6 + 13;
int n, r1[MAX_N], r2[MAX_N];
vector<int> v1, v2;

bool check(int w)
{
    v1.clear(), v2.clear();
    for (int i = 0; i < n; ++i)
        if (r1[i] > w)
            v1.push_back(r1[i]);
    for (int i = 0; i < n; ++i)
        if (r2[i] > w)
            v2.push_back(r2[i]);
    if (v1.size() % 2 || v2.size() % 2)
        return false;
    for (int i = 0; i < v1.size(); i += 2)
        if (v1[i] != v1[i + 1])
            return false;
    for (int i = 0; i < v2.size(); i += 2)
        if (v2[i] != v2[i + 1])
            return false;
    return true;
}

int main()
{
    cin >> n;
    int l = 0, h = 0;
    for (int i = 0; i < n; ++i)
        cin >> r1[i], h = max(h, r1[i]);
    for (int i = 0; i < n; ++i)
        cin >> r2[i], h = max(h, r2[i]);

    while (l < h)
    {
        int mid = (l + h) / 2;
        if (check(mid))
            h = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
    return 0;
}