#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

string s1 = "one two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen twenty thirty forty fifty sixty seventy eighty ninety";
string s2 = "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 30 40 50 60 70 80 90";
string str, st;
int sign, n, t;
map <string, int> mp;

int main ()
{
    stringstream ss1 (s1);
    stringstream ss2 (s2);
    while (ss1 >> st && ss2 >> t)
        mp[st] = t;
    while (getline(cin, str))
    {
        stringstream ss (str);
        sign = 1;
        n = t = 0;
        while (ss >> st)
        {
            if (st == "negative")
                sign = -1;
            else if (mp[st])
                t += mp[st];
            else if (st != "zero")
            {
                if (st == "million")
                {
                    n += t*1000000;
                    t = 0;
                }
                else if (st == "thousand")
                {
                    n += t*1000;
                    t = 0;
                }
                else
                    t *= 100;
            }
        }
        n += t;
        cout << sign*n << endl;
    }
    return 0;
}
