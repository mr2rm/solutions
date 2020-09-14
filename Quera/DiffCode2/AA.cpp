#include <iostream>
#include <string>

using namespace std;

int main()
{
    int k, n = 0;
    cin >> k;

    for (int i = 1; i <= 5000; ++i)
    {
        string s = to_string(i);
        int len = s.length();
        n += len;
        if (n >= k)
        {
            int idx = len - (n - k + 1);
            cout << s[idx] << endl;
            break;
        }
    }
    return 0;
}