#include <iostream>
#include <queue>
#include <cstring>
#include <stdio.h>

using namespace std;

int mat[21][21];
int mark[21];
int tc = 0;
int n, m, t;
int a, b;

void bfs ()
{
   queue <int> q;
   q.push (a);
   mark[a] = 0;
   while (!q.empty())
   {
      int temp = q.front();
      q.pop();
      if (temp == b)
         return;
      for (int i = 1; i <= 20; i++)
         if (mat[temp][i] == 1 && mark[i] == -1)
         {
            q.push (i);
            mark[i] = mark[temp] + 1;
         }
   }
}

int main ()
{
   //freopen ("input.in", "r", stdin);
   while (cin >> n)
   {
      tc++;
      for (int i = 0; i < 21; i++)
         memset (mat[i], 0, sizeof mat[i]);
      for (int i = 1; i <= 19; i++)
      {
         if (i != 1)    cin >> n;
         for (int j = 0; j < n && cin >> m; j++)
         {
            mat[i][m] = 1;
            mat[m][i] = 1;
         }
      }
      cin >> t;
      cout << "Test Set #" << tc << endl;
      for (int i = 0; i < t && cin >> a >> b; i++)
      {
         memset (mark, -1, sizeof mark);
         bfs ();
         printf ("%2d", a);
         cout << " to ";
         printf ("%2d", b);
         cout << ": " << mark[b] << endl;
      }
      cout << endl;
   }
   return 0;
}

