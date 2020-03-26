#include <iostream>

using namespace std;

int t, a, b;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> a >> b;

        if (a <= b)
        {
            cout << b - a << endl;
            continue;
        }

        int d = a / b;
        if (a % b != 0)
            d++;
        cout << d * b - a << endl;
    }
    return 0;
}