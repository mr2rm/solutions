#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

//1//
/*
int main()
{
	int n;
	cin >> n;
	string str;
	getline (cin, str);
	vector < set <string> > v (2000);
	vector <string> vv;
	for (int i = 0; i < n && getline (cin, str); i++)
	{
		stringstream ss (str);
		string s1, s2;
		ss >> s1;
		getline (ss, s2);
		bool b = true;
		for (int i = 0; i < vv.size(); i++)
			if (vv[i] == s1)
			{
				b = false;
				v[i].insert (s2);
				break;
			}
		if (b)
		{
			vv.push_back (s1);
			v[vv.size()-1].insert (s2);
		}
	}
	vector <string> nvv (vv.begin(), vv.end());
	sort (nvv.begin(), nvv.end());
	for (int i = 0; i < nvv.size(); i++)
	{
		cout << nvv[i] << " ";
		for (int j = 0; j < vv.size(); j++)
			if (nvv[i] == vv[j])
			{
				cout << v[j].size() << endl;
				break;
			}
	}
	return 0;
}
*/

//2//
/*
int main()
{
    bool b1, b2;
    int n;
    cin >> n;
    string str;
    getline (cin, str);
    vector < vector <string> > v(2000);
    vector <string> vv;
    for (int i = 0; i < n && getline (cin, str); i++)
    {
        stringstream ss (str);
        string s1, s2;
        ss >> s1;
        getline (ss, s2);
        b1 = true;
        for (int i = 0; i < vv.size(); i++)
            if (s1 == vv[i])
            {
                b1 = false;
                b2 = true;
                for (int j = 0; j < v[i].size(); j++)
                    if (v[i][j] == s2)
                    {
                        b2 = false;
                        break;
                    }
                if (b2)
                    v[i].push_back (s2);
            }
        if (b1)
        {
            vv.push_back (s1);
            v[vv.size()-1].push_back (s2);
        }

    }
    vector <string> nvv (vv.begin(), vv.end());
    sort (nvv.begin(), nvv.end());
    for (int i = 0; i < nvv.size(); i++)
    {
        cout << nvv[i] << " ";
        for (int j = 0; j < vv.size(); j++)
            if (vv[j] == nvv[i])
            {
                cout << v[j].size() << endl;
                break;
            }
    }
    return 0;
}
*/