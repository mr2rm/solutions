#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <cstdio>

using namespace std;

void myfunc (int x)
{
	stringstream ss;
	ss << x;
	int size = x < 0 ? 5 : 4;
	if (x < 0 && ss.str().length() >= 4)
		size = ss.str().length() + 1;
	else if ( x >= 0 && ss.str().length() >= 3)
		size = ss.str().length() + 1;
	string space (10 - size, ' ');
	cout << space;
	float f = x / 100.;
	cout.flags(ios::fixed | ios::showpoint);
	cout.precision (2);
	cout << f << endl;
}

int main()
{
	freopen ("Transaction Processing.in", "r", stdin);
    vector <string> names (1000);
    vector < vector < pair <int, int> > > transactions (1000);
    vector <int> sums (1000, 0);
    pair <int, int> p;
    string str;
    int num, val, ind, trans;
    while (getline (cin, str))
    {
        string number (str.begin(), str.begin() + 3);
        if (number == "000")     break;
        string name (str.begin() + 3, str.end());
        stringstream ss (number);
        ss >> ind;
        names[ind] = name;
    }
    while (getline (cin, str))
    {
        string transaction (str.begin(), str.begin() + 3);
        if (transaction == "000")    break;
        string number (str.begin() + 3, str.begin() + 6);
        string value (str.begin() + 6, str.end());
        stringstream ss1 (transaction); ss1 >> trans;
        stringstream ss2 (number);      ss2 >> num;
        stringstream ss3 (value);       ss3 >> val;
        sums[trans] += val;
        p = make_pair (num, val);
        transactions[trans].push_back (p);
    }
    for (int i = 0; i < 1000; i++)
    {
        if (sums[i] != 0)
        {
			cout << "*** Transaction " << i << " is out of balance ***" << endl;
            for (int j = 0; j < transactions[i].size(); j++)
            {
				printf ("%3d", transactions[i][j].first);
                num = transactions[i][j].first;
                string space1 (30 - names[num].length(), ' ');
                cout << " " << names[num] + space1 << " ";
				myfunc (transactions[i][j].second);
            }
            cout << "999 Out of Balance                 ";
			myfunc (-1*sums[i]);
			cout << endl;
        }
    }
    return 0;
}