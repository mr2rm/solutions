#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <cstring>
#include <cstdio>

using namespace std;

vector <string> mat;
int mark[100][100];
vector <int> noc;
int arr[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
int cn, sumofcomp;
pair <int, int> p;
int n, m;

bool inboard (int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
        return true;
    return false;
}

void dfs (pair <int, int> x)
{
	mark[x.first][x.second] = cn;
	sumofcomp++;
	for (int i = 0; i < 8; i++)
	{
		int a = x.first + arr[i][0];
		int b = x.second + arr[i][1];
		if (inboard (a, b) && mat[a][b] == 'W' && mark[a][b] == 0)
			dfs (make_pair (a, b));
	}
}

int main ()
{
	//freopen ("/home/blackwizard/Desktop/Wetlands of Florica.in", "r", stdin);
	int t;
	cin >> t;
	string str;
	getline (cin, str);
	getline (cin, str);
	for (int i = 0; i < t; i++)
	{
		mat.clear ();
		noc.clear ();
		cn = 0;
		n = 0;
		while (getline(cin, str) && str != "")
		{
			if (str[0] == 'W' || str[0] == 'L')
			{
				mat.push_back (str);
				memset (mark[n], 0, sizeof mark[n]);
				n++;
				m = str.length ();
			}
			else
			{
				stringstream ss (str);
				ss >> p.first;	p.first--;
				ss >> p.second;	p.second--;
				if (inboard (p.first, p.second))
				{
				    if (mark[p.first][p.second] == 0)
                    {
                        cn++;
                        sumofcomp = 0;
                        dfs (p);
                        noc.push_back (sumofcomp);
                    }
                    int tt = mark[p.first][p.second];
                    cout << noc[tt-1] << endl;
				}
				else    cout << "0" << endl;
			}
		}
		if (i != t-1)
			cout << endl;
	}
	return 0;
}
