#include <iostream>
#include <cstring>

using namespace std;
int n, l;
int x, y;
bool b;
int mat[200][200];

void dfs (int node , int color)
{
    mat[node][node] = color;
    for (int i = 0; b && i < n; i++)
        if (i != node && mat[node][i] == 1)
            if (mat[i][i] == 0)
                dfs (i, color%2 + 1);
            else if (mat[i][i] == color)
                b = false;
}

int main()
{
    while (cin >> n && n != 0)
    {
        b = true;
        for (int i = 0; i < n; i++)
            memset (mat[i], 0, sizeof mat[i]);
        cin >> l;
        for (int i = 0; i < l && cin >> x >> y; i++)
            mat[x][y] = 1;
        dfs (0, 1);
        if (b)
            cout << "BICOLORABLE." << endl;
        else
            cout << "NOT BICOLORABLE." << endl;
    }
    return 0;
}