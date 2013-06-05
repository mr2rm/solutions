#include <iostream>
#include <string>
#include <utility>
#include <queue>
#include <cstring>

using namespace std;

pair <int, int> start, end;
int dir[8][2] = {{-1, 2}, {-1, -2}, {1, 2}, {1, -2}, {-2, 1}, {-2, -1}, {2, 1}, {2, -1}};
int mark[8][8];

void bfs ()
{
    queue < pair <int, int> > q;
    q.push (start);
    mark[start.first][start.second] = 0;
    while (!q.empty())
    {
        pair <int, int> p = q.front();
        q.pop();
        if (p == end)
            return;
        for (int I = 0; I < 8; I++)
        {
            int tx = dir[I][0] + p.first;
            int ty = dir[I][1] + p.second;
            if (tx >= 0 && tx < 8 && ty >= 0 && ty < 8 && mark[tx][ty] < 0)
            {
                mark[tx][ty] = mark[p.first][p.second]+1;
                q.push(make_pair(tx, ty));
            }
        }
    }
}
int main ()
{
    string s, e;
    while (cin >> s >> e)
    {
        memset (mark, -1, sizeof mark);
        start.first = (s[1]-'0'-1); 
        start.second = (s[0]-'a');
        end.first = (e[1]-'0'-1);
        end.second = (e[0]-'a');
        bfs ();
        cout << "To get from " << s << " to " << e << " takes " << mark[end.first][end.second] << " knight moves." << endl;
    }
    return 0;
}