#include <stdio.h>
#include <string.h>

int n, x, c;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &x);
        c = x <= 3 ? x : 1;
        char s[3] = {};
        memset(s, '*', c);
        printf("%s\n", s);
    }
}
