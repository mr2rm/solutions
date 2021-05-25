#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

string str, s;
bool b;

int constant (int in)
{
    for (in++; in < str.length(); in++)
        if (str[in] == '\'')
        {
            if (in < str.length()-1 && str[in+1] == '\'')
                in++;
            else
                return in;
        }
}

void space (int in)
{
    int i;
    for (i = in + 1; i < str.length() && str[i] == ' '; i++);
    str.erase (str.begin()+in+1, str.begin()+i);
}

bool show ()
{
    if (str.length())
    {
        s = string (str.length(), ' ');
        if (s != str)
            return true;
    }
    return false;
}

int comment1 (int in)
{
    b = false;
	int i = in + 1;
    do
    {
        for (; !b && i < str.length(); i++)
            if (str[i] == '}')
                b = true;
        if (!b)
        {
			getline (cin, s);
			str += s;
        }
    }while (!b);
	str.erase (str.begin()+in, str.begin()+i);
    return in-1;
}

int comment2 (int in)
{
    b = false;
    int i = in + 2;
    do
    {
        for (i++; !b && i < str.length(); i++)
            if (str[i] == ')' && str[i-1] == '*')
                b = true;
        if (!b)
        {
			getline (cin, s);
			str += s;
        }
    }while (!b);
	str.erase (str.begin()+in, str.begin()+i);
    return in-1;
}

int main ()
{
    while (getline(cin, str))
    {
        for (int i = 0; i < str.length(); i++)
        {
            switch (str[i])
            {
            case '\'':
                i = constant(i);
                break;
            case ' ':
                space (i);
                break;
            case '{':
                i = comment1 (i);
                break;
            case '(':
                if (i < str.length()-1 && str[i+1] == '*')
                    i = comment2 (i);
                break;
            }
        }
        if (show())
            cout << str << endl;
    }
    return 0;
}

