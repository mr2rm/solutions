#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    string str, s;
    int w, n, c, temp, tm;
    bool b;
    vector <int> v;
    while (getline(cin, str))
    {
        v.clear();
        stringstream ss(str);
        while (ss >> s)
        {
            reverse(s.begin(), s.end());
            w = 0;
            for (int i = 0; i < s.length(); i++)
                w += (s[i]-'a'+1)*pow(32., i);
            v.push_back(w);
        }
        sort(v.begin(), v.end());
		n = v.size();
		c = v[0];
		do
		{
			b = true;
			for (int i = 0; b && i < n; i++)
			{
				temp = floor((double)c/v[i]);
				temp %= n;
				for (int j = i + 1; j < n; j++)
				{
					tm = floor((double)c/v[j]);
					tm %= n;
					if (tm == temp)
					{
						c = min ( (floor((double)c/v[i])+1)*v[i], (floor((double)c/v[j])+1)*v[j]);
						b = false;
					}
				}
			}
		}while (!b);
        cout << str << endl << c << endl << endl;
    }
    return 0;
}