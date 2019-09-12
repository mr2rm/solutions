#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << setw(2) << setfill('0') << (12 - a) % 12 << ':';
    cout << setw(2) << setfill('0') << (60 - b) % 60 << endl;
    return 0;
}
