#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

/*
int main ()
{
	string str, res, s;
	int sum;
	for (int t = 0; getline(cin, str); t++)
	{
		if (t)	cout << endl;
		res = "";
		do
		{
			for (unsigned int I = 0; I < str.length(); I++)
			{
				sum = 0;
				for (; isdigit(str[I]); I++)
					sum += str[I]-'0';
				if (!sum)
					sum = 1;
				switch (str[I])
				{
					case 'b':
						s = string (sum, ' ');
						break;
					case '!':
						s = string (sum, '\n');
						break;
					default:
						s = string (sum, str[I]);
				}
				res += s;
			}
			res += "\n";
		}
		while (getline(cin, str) && str != "");
		cout << res;
	}
	return 0;
}
*/

int main ()
{
	//freopen ( "Marevelous Mazes.in" , "r" , stdin );
	string str;
	int t;
	while ( getline ( cin , str ) )
	{
		t = 0;
		for ( int i = 0 ; i < str.length() ; i++ )
		{
			if ( str[i] == '!' )	cout << endl;
			if ( str[i] == 'b' )	
			{
				string s ( t , ' ' );
				cout << s;
				t = 0;
			}
			if ( str[i] >= '0' && str[i] <= '9' )
				t += str[i] - '0';
			if ( ( str[i] >= 'A' && str[i] <= 'Z' ) || str[i] == '*' )
			{
				string s ( t , str[i] );
				cout << s;
				t = 0;
			}
		}
		cout << endl;
	}
	return 0;
}