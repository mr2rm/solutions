#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;
int x, y;
int res, reg;
int tx, ty;
vector <string> v;
string str;
char land;
int arr[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void dfs (int a, int b)
{
    v[a][b] = ' ';
    reg++;
    for (int i = 0; i < 4; i++)
    {
        tx = a + arr[i][0];
        ty = (b + arr[i][1]) % n;
        if (ty == -1)
            ty = n - 1;
        if (tx >= 0 && tx < m && v[tx][ty] == land)
            dfs (tx, ty);
    }
}

int main ()
{
    while (cin >> m >> n)
    {
        v.clear();
        for (int i = 0; i < m && cin >> str; i++)
            v.push_back (str);
        cin >> x >> y;
        //cin.ignore ();
        land = v[x][y];
        dfs (x, y);
        res = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (v[i][j] == land)
                {
                    reg = 0;
                    dfs (i, j);
                    res = max (reg, res);
                }
        cout << res << endl;
    }
    return 0;
}

