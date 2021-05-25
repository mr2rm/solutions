#include <iostream>
#include <string>
#include <stack>
#include <cstdio>

using namespace std;

string in, pre, post;
char c;

int op (char ch)
{
    switch (ch)
    {
    case '$':
        return 5;
    case '*':
    case '/':
        return 4;
    case '+':
    case '-':
        return 3;
    case '&':
    case '|':
        return 2;
    case '!':
        return 1;
    }
}

void postfix()
{
    stack <char> st;
    for (int i = 0; i < in.length(); i++)
        if (isalpha(in[i]))
        {
			if (post.length())
				post.push_back (' ');
            post.push_back (in[i]);
        }
        else if (in[i] != ' ')
        {
            while (!st.empty() && op(in[i]) < op(st.top()))
            {
                c = st.top();
                st.pop();
                post.push_back (' ');
                post.push_back (c);
            }
            st.push(in[i]);
        }
    while (!st.empty())
    {
        c = st.top();
        st.pop();
        post.push_back (' ');
        post.push_back (c);
    }
}

int main ()
{
    getline (cin, in);
    getline (cin, pre);
	postfix ();
    cout << "INFIX   => " << in << endl;
    cout << "PREFIX  => " << pre << endl;
    cout << "POSTFIX => " << post << endl;
    return 0;
}
