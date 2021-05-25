#include <bits/stdc++.h>

using namespace std;

int n, res;
string s, t;

int main()
{
    cin >> s >> n;

    res = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;

        int k = 0;
        for (int j = 0; j < t.length() && k < s.length(); ++j)
            if (t[j] == s[k])
                k++;

        if (k == s.length())
            res++;
    }

    cout << res << endl;
    return 0;
}
