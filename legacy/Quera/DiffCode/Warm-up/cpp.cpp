#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
    cin >> s;
    for (int i = 0; i < s.length(); ++i)
        cout << string(i, s[i]) + string(s.begin() + i, s.end()) << endl;
    return 0;
}
