#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int n, m;
int mat[1010][1010];

int check(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m && mat[x][y] != 0;
}

ll solve(int x, int y, int l)
{
    int score = 0, tmp;

    if (check(x, y - 1))
    {
        tmp = solve(x, y - 1, l);
        score = tmp != -1 ? tmp : 0;
    }

    int ty = l % 2 == 0 ? y - 1 : y + 1;
    if (check(x - 2, ty))
    {
        tmp = solve(x - 2, ty, l + 1);
        score = tmp != -1 ? max(score, tmp) : 0;
    }

    if (score == 0 && x != 0)
        return -1;

    return mat[x][y] + score;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> mat[i][j];

    ll res = 0;
    for (int j = 0; j < m; ++j)
        if (mat[n - 1][j] != 0)
            res = max(res, solve(n - 1, j, 0));

    cout << res << endl;
}
