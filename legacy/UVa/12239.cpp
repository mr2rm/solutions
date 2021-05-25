#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main ()
{
    int n, b;
    int mark[91];
    bool bo;
    while (cin >> n >> b && b != 0)
    {
        memset (mark, 0, sizeof mark);
        vector <int> balls(b);
        for (int i = 0; i < b; i++)
                cin >> balls[i];
        sort (balls.begin(), balls.end());
        for (int i = 0; i < b; i++)
            for (int j = i + 1; j < b; j++)
                mark[balls[j]-balls[i]] = 1;
        bo = true;
        for (int i = 1; bo && i <= n ; i++)
            if (!mark[i])
                bo = false;
        if (bo)
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
    return 0;
}
