#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int m = n / 2;
    long long x = 1ll * m * (m + 1);
    int y = (1 - n % 2) * m;
    printf("%lf\n", 1.0 * (x - y) / (n + 1));
    return 0;
}
