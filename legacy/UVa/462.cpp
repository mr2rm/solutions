#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <cstring>

using namespace std;

int main ()
{
    string str, st;
    int p1, p2, res, maxi;
    bool K, Q, J, b;
    int stop[4];
    while (getline(cin, str))
    {
        vector < vector <string> > v (4);
        memset (stop, 0, sizeof stop);
        stringstream ss (str);
        p1 = p2 = 0;
        while (ss >> st)
        {
            switch (st[0])
            {
            case 'A':
                p1 += 4;
                break;
            case 'K':
                p1 += 3;
                break;
            case 'Q':
                p1 += 2;
                break;
            case 'J':
                p1 += 1;
                break;
            }

            switch (st[1])
            {
            case 'S':
                v[0].push_back(st);
                break;
            case 'H':
                v[1].push_back(st);
                break;
            case 'D':
                v[2].push_back(st);
                break;
            default:
                v[3].push_back(st);
            }
        }
        for (int i = 0; i < 4; i++)
        {
            K = Q = J = false;
            for (int j = 0; j < (int)v[i].size(); j++)
                switch (v[i][j][0])
                {
                case 'A':
                    stop[i] = 1;
                    break;
                case 'K':
                    if (v[i].size() >= 2)
                        stop[i] = 1;
                    K = true;
                    break;
                case 'Q':
                    if (v[i].size() >= 3)
                        stop[i] = 1;
                    Q = true;
                    break;
                case 'J':
                    J = true;
                    break;
                }
            if (K && v[i].size() < 2)
                p1--;
            if (Q && v[i].size() < 3)
                p1--;
            if (J && v[i].size() < 4)
                p1--;

            switch (v[i].size())
            {
            case 0:
            case 1:
                p2 += 2;
                break;
            case 2:
                p2++;
                break;
            }
        }
        p2 += p1;
        if (p2 < 14)
            cout << "PASS" << endl;
        else
        {
            if (p1 >= 16)
            {
                b = true;
                for (int i = 0; i < 4; i++)
                    if (!stop[i])
                    {
                        b = false;
                        break;
                    }
                if (b)
                {
                    cout << "BID NO-TRUMP" << endl;
                    continue;
                }
            }
            if (p2 >= 14)
            {
                cout << "BID ";
                res = maxi = -1;
                for (int i = 0; i < 4; i++)
                    if ((int)v[i].size() > maxi)
                    {
                        maxi = v[i].size();
                        res = i;
                    }
                switch (res)
                {
                case 0:
                    cout << "S" << endl;
                    break;
                case 1:
                    cout << "H" << endl;
                    break;
                case 2:
                    cout << "D" << endl;
                    break;
                default:
                    cout << "C" << endl;
                }
            }
        }
    }
    return 0;
}
