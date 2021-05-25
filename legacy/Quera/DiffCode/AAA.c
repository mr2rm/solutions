#include <stdio.h>
#include <string.h>
#include <limits.h>

int n, T, t, e;
int res, ct, ce, te;

int main()
{
    scanf("%d %d", &n, &T);

    res = -T;
    ct = ce = 0;
    while (n--)
    {
        scanf("%d %d", &t, &e);
        ct += t, ce += e;
        te = ce - (T - ct);
        if (ct <= T && te > res)
            res = te;
    }

    printf("%d\n", res);
    return 0;
}
