#include <iostream>
#include <string>
#include <stack>

using namespace std; 

int main ()
{
	freopen ( "Parentheses Balance.in" , "r" , stdin );
	int n;
	bool b;
	string str;
	cin >> n;
	getline ( cin , str );
	for ( int i = 0 ; i < n && getline ( cin , str ) ; i++ )
	{
		stack <char> st;
		b = true;
		for ( int j = 0 ; j < str.length() && b ; j++ )
			switch ( str[j] )
			{
				case '(':
				case '[':
					st.push ( str[j] );
					break;
				case ')':
					if ( st.size() != 0 && st.top() == '(' )	st.pop();
					else	b = false;
					break;
				case ']':
					if ( st.size() != 0 && st.top() == '[' )	st.pop();
					else	b = false;
					break;
			}
		if ( !b || st.size() != 0 )
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}