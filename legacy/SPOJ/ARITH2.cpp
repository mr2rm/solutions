#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main ()
{
	//freopen ( "Simple Arithmetics II.in" , "r" , stdin );
	int T;
	string s , str;
	cin >> T;
	getline ( cin , s );	
	for ( int i = 0 ; i < T ; i++ )
	{
		getline ( cin , s );
		getline ( cin , str );
		long long int ANS = 0 , temp;
		for ( int j = 0 ; str[j] != '=' ; j++ )
		{
			if ( j == 0 )
			{
				for ( ; str[j] == ' ' ; j++ );
				for ( ; str[j] >= '0' && str[j] <= '9'; j++ );
				string num1 ( str.begin() , str.begin() + j );
				stringstream ss ( num1 );
				ss >> ANS;
				for ( ; str[j] == ' ' ; j++ );
			}
			char op = str[j];
			int first;
			for ( j++ ; str[j] == ' ' ; j++ );
			for ( first = j ; str[j] >= '0' && str[j] <= '9' ; j++ );
			string num2 ( str.begin() + first , str.begin() + j );
			stringstream sss ( num2 );
			sss >> temp;
			switch ( op )
			{
				case '+':
					ANS += temp;
					break;
				case '-':
					ANS -= temp;
					break;
				case '*':
					ANS *= temp;
					break;
				default:
					ANS /= temp;
			}
			for ( ; str[j] == ' ' ; j++ );
			j--;
		}
		cout << ANS << endl;
	}
	return 0;
}