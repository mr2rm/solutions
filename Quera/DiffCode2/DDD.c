#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int T, n;
int mat[101][101];
int src[2], dst[2];
const char *dir_sign = "DURL";
const int dir[][2] = {
    {1, 0},  // D
    {-1, 0}, // U
    {0, 1},  // R
    {0, -1}  // L
};

bool is_prime(int x)
{
    if (x == 2)
        return true;
    if (x <= 1 || x % 2 == 0)
        return false;
    for (int y = 3; y * y <= x; y += 2)
        if (x % y == 0)
            return false;
    return true;
}

bool find_path(int x, int y, char *path)
{
    if (x == dst[0] && y == dst[1])
    {
        printf("%s\n", path);
        return true;
    }

    mat[x][y] = 0;
    for (int i = 0; i < 4; ++i)
    {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (tx >= 0 && tx < n && ty >= 0 && ty < n && is_prime(mat[tx][ty]))
        {
            char tpath[10101];
            sprintf(tpath, "%s%c", path, dir_sign[i]);
            if (find_path(tx, ty, tpath))
                return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d", &T);

    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &mat[i][j]);

        scanf("%d %d", &src[0], &src[1]);
        scanf("%d %d", &dst[0], &dst[1]);

        if (!find_path(src[0], src[1], ""))
            printf("No Monaseb Masir!\n");
    }
    return 0;
}