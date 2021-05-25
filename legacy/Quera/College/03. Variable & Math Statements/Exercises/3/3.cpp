#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << setprecision(6) << fixed << "Sum : " << 1.0 * (a + b + c + d) << endl;
    cout << setprecision(6) << fixed << "Average : " << (a + b + c + d) / 4. << endl;
    cout << setprecision(6) << fixed << "Product : " << 1.0 * a * b * c * d << endl;
    int x = (a + b + abs(a - b)) / 2;
    int y = (c + d + abs(c - d)) / 2;
    cout << setprecision(6) << fixed << "MAX : " << (x + y + abs(x - y)) / 2. << endl;
    x = (a + b - abs(a - b)) / 2;
    y = (c + d - abs(c - d)) / 2;
    cout << setprecision(6) << fixed << "MIN : " << (x + y - abs(x - y)) / 2. << endl;
    return 0;
}
