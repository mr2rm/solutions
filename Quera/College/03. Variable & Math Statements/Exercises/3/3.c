#include <stdio.h>

int main() {
    int a, b, c, d;
    scanf("%d\n%d\n%d\n%d", &a, &b, &c, &d);
    printf("Sum : %.6lf\n", 1.0 * a + b + c + d);
    printf("Average : %.6lf\n", (a + b + c + d) / 4.);
    printf("Product : %.6lf\n", 1.0 * a * b * c * d);
    int x = (a + b + abs(a - b)) / 2;
    int y = (c + d + abs(c - d)) / 2;
    printf("MAX : %.6lf\n", (x + y + abs(x - y)) / 2.);
    x = (a + b - abs(a - b)) / 2;
    y = (c + d - abs(c - d)) / 2;
    printf("MIN : %.6lf\n", (x + y - abs(x - y)) / 2.);
    return 0;
}
