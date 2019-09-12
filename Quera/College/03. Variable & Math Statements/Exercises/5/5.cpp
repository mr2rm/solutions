#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    int m = n / 2;
    long long x = 1ll * m * (m + 1);
    int y = (1 - n % 2) * m;
    cout << fixed << 1.0 * (x - y) / (n + 1) << endl;
    return 0;
}
