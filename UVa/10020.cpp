#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main ()
{
    int n, m, l, r, t, mx, in;
    vector < pair <int, int> > v;
    vector < pair <int, int> > res;
    for (cin >> n; n != 0 && cin >> m; n--)
    {
        v.clear();
        res.clear();
        while (cin >> l >> r && (l || r))
        {
            if (r < 0 || l >= m)
                continue;
            v.push_back (make_pair (l, r));
        }
        sort (v.begin(), v.end());
        t = 0;
        while (t < m)
        {
            mx = in = -1;
            for (int i = 0; i < v.size(); i++)
                if (t >= v[i].first && t < v[i].second && v[i].second - t > mx)
                {
                    mx = v[i].second - t;
                    in = i;
                }
            if (in == -1)
                break;
            res.push_back (v[in]);
            t = v[in].second;
        }
        if (in >= 0)
        {
            cout << res.size() << endl;
            for (int i = 0; i < res.size(); i++)
                cout << res[i].first << " " << res[i].second << endl;
        }
        else
            cout << "0" << endl;
        if (n != 1)
            cout << endl;
    }
    return 0;
}