#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a = n / 2;
    int b = n - a;
    printf("%d\n", (a + 1) * (b + 1));
    return 0;
}
