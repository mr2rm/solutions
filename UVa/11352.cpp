#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <vector>
#include <utility>

using namespace std;

int n, m;
vector <string> v;
int arr[8][2] = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
int a[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
int mat[100][100];

void fill (int a, int b)
{
    int tx, ty;
    for (int i = 0; i < 8; i++)
    {
        tx = a + arr[i][0];
        ty = b + arr[i][1];
        if (tx >= 0 && tx < n && ty >= 0 && ty < m && v[tx][ty] == '.')
            v[tx][ty] = 'N';
    }
}

int bfs (pair <int, int> p)
{
    queue < pair <int, int> > q;
    q.push (p);
    mat[p.first][p.second] = 0;
    int tx, ty;
    while (!q.empty())
    {
        pair <int, int> tp = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            tx = tp.first + a[i][0];
            ty = tp.second + a[i][1];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m)
            {
				if (v[tx][ty] == 'B')
					return mat[tp.first][tp.second] + 1;
				if (v[tx][ty] == '.' && mat[tx][ty] == -1)
				{
					q.push (make_pair (tx, ty));
					mat[tx][ty] = mat[tp.first][tp.second] + 1;
				}
            }
        }
    }
    return -1;
}

int main ()
{
    int t;
    cin >> t;
    string str;
    for (int i = 0; i < t && cin >> n >> m; i++)
    {
        v.clear();
        pair <int, int> s;
        for (int i = 0; i < n; i++)
            memset (mat[i], -1, sizeof mat[i]);
        for (int i = 0; i < n && cin >> str; i++)
            v.push_back (str);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] == 'Z')
                    fill (i, j);
                if (v[i][j] == 'A')
                {
                    s.first = i;
                    s.second = j;
                }
            }
        int Res = bfs (s);
        if (Res == -1)
            cout << "King Peter, you can't go now!" << endl;
        else
            cout << "Minimal possible length of a trip is " << Res << endl;
    }
    return 0;
}
