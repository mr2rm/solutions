#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string str;
int n, i, m;
bool b;

bool IsDig (int in)
{
    return (str[in] >= '0' && str[in] <= '9');
}

int main ()
{
    while (getline(cin, str) && str != "*")
    {
        for (i = str.length()-1; i >= 0 && str[i] == ' '; i--);
        str = string (str.begin(), str.begin()+i+1);
        for (i = 0; i < (int)str.length() && str[i] == ' '; i++);
        str = string (str.begin()+i, str.end());

        n = str.length();
        b = false;
        i = 0;

        if (i < n && (str[i] == '+' || str[i] == '-'))
            i++;
        for (m = 0; i < n && IsDig(i); i++ , m++);

        if (i < n && str[i] == '.' && m)
        {
            for (m = 0, i++; i < n && IsDig(i); i++, m++);
            if (m)
                b = true;
        }

        if (i < n && (str[i] == 'e' || str[i] == 'E') && m)
        {
            i++;
            if (i < n && (str[i] == '+' || str[i] == '-'))
                i++;
            for (m = 0; i < n && IsDig(i); i++, m++);
            if (m)
                b = true;
            else
                b = false;
        }

        cout << str << " is ";
        if (b && i == (int)str.length())
            cout << "legal." << endl;
        else
            cout << "illegal." << endl;
    }
    return 0;
}
