#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main ()
{
	freopen ( "Zeros and Ones.in" , "r" , stdin );
	string str , s;
	int n , i1 , i2;
	bool bl;
	int a , b;
	int c = 0;
	while ( getline ( cin , str ) && str != "" )
	{
		c++;
		cin >> n ;
		cout << "Case " << c << ":" << endl;
		for ( int i = 0 ; i < n ; i++ )
		{
			cin >> i1 >> i2;
			a = min ( i1 , i2 );
			b = max ( i1 , i2 );
			bl = true;
			for ( int j = a + 1 ; j <= b ; j++ )
				if ( str[j] != str[a] )
				{
					bl = false;
					break;
				}
			if ( bl == true )
				cout << "Yes" << endl;
			else 
				cout << "No" << endl;
		}
		getline ( cin , s );
	}
	return 0;
}

/*int main ()
{
	string str , s;
	int 
	int i1 , i2 , n;
	int c = 0;
	while ( getline ( cin , str ) && str != "" )
	{
		cin >> n;
		for ( int i = 0 ; i < str.length() ; i++ )
			
		getline ( cin , str );
	}
	return 0;
}*/