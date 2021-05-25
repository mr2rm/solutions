#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    string dsc, usc, str;
    getline (cin, dsc);
    getline (cin, usc);
    vector <string> v (2);
    v[0] = dsc; 
	v[1] = usc;
	int shift;
    while (cin >> str)
    {
		shift = 0;
        for (int i = 0; i < str.length(); i += 5)
        {
            string s (str.begin() + i, str.begin() + i + 5);
            int t = 0;
            for (int i = 0; i < 5; i++)
                t += (s[i]-'0') * pow (2., 5-i-1);
            if (t == 27)
            {
                shift = 0;
                continue;
            }
            if (t == 31)
            {
                shift = 1;
                continue;
            }
            cout << v[shift][t];
        }
        cout << endl;
    }
    return 0;
}
