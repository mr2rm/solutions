#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n, m;
int x,y;
int mat[101][101];
int mark[101];
vector <int> Res;

void dfs (int a)
{
    mark[a] = 1;
    for (int i = 1; i <= n; i++)
        if (mark[i] == 0 && mat[a][i] == 1)
            dfs (i);
    Res.push_back (a);
}

int main()
{
    while (cin >> n >> m && n != 0)
    {
        Res.clear();
        for (int i = 1; i <= n; i++)
            memset (mat[i], 0, sizeof mat[i]);
        memset (mark, 0, sizeof mark);
        for (int i = 0; i < m && cin >> x >> y; i++)
            mat[x][y] = 1;
        for (int i = 1; i <= n; i++)
            if (mark[i] == 0)
                dfs (i);
        for (int i = Res.size() - 1; i >= 0; i--)
        {
            cout << Res[i];
            if (i == 0) cout << endl;
            else    cout << " ";
        }
    }
    return 0;
}