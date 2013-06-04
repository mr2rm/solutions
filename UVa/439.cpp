#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

string s1, s2;
int mat[8][8];
int dir[8][2] = { {-1, 2}, {1, 2}, {-1, -2}, {1, -2}, {-2, 1}, {-2, -1}, {2, 1}, {2, -1} };
pair <int, int> start;
pair <int, int> end;
void bfs ()
{
    mat[start.first][start.second] = 0;
    queue < pair <int, int> > q;
    q.push (start);
    while (mat[end.first][end.second] == -1)
    {
        pair <int, int> t;
        t = q.front();
        q.pop ();
        for (int i = 0; i < 8; i++)
        {
            int x = t.first + dir[i][0];
            int y = t.second + dir[i][1];
            if (x >= 0 && x < 8 && y >= 0 && y < 8 && mat[x][y] == -1)
            {
                mat[x][y] = mat[t.first][t.second] + 1;
                q.push (make_pair (x, y));
            }
        }
    }
}
int main()
{
    while (cin >> s1 >> s2)
    {
        for (int i = 0; i < 8; i++)
            memset (mat[i], -1, sizeof mat[i]);
        end.first = s2[0]-'a';  end.second = s2[1]-'1';
        start.first = s1[0]-'a';    start.second = s1[1]-'1';
        bfs ();
        cout << "To get from " << s1 << " to " << s2 << " takes " << mat[end.first][end.second] << " knight moves." << endl;
    }
    return 0;
}
