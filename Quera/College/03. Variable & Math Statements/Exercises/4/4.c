#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%02d:%02d\n", (12 - a) % 12, (60 - b) % 60);
    return 0;
}
