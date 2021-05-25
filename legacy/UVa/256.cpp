#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <stdio.h>
#include <cstdio>

using namespace std;

int main ()
{
	freopen ( "Quirksome Squares.in" , "r" , stdin );
	int n , temp;
	//int f , e , o;
	int a , b , o;
	//int t1 , t2;
	while ( cin >> n )
	{
		string st1 ( n / 2 , '9' );	stringstream ss ( st1 );	ss >> temp;
		for ( a = b = o = 0 ; 1 ; o++ )
		{
			if ( pow ( a + b , 2. ) == o )
			{
				//2//0.39s
				/*
				t1 = ( a == 0 ? 1 : (int)log10 ( (double)a ) + 1 );	
				t2 = ( b == 0 ? 1 : (int)log10 ( (double)b ) + 1 );
				string s1 ( n / 2 - t1 , '0' );	string s2 ( n / 2 - t2 , '0' );
				cout << s1 << a << s2 << b << endl;
				*/
				//3//0.33s
				switch ( n )
				{
				case 2:
					printf ( "%01d%01d\n" , a , b );
					break;
				case 4:
					printf ( "%02d%02d\n" , a , b );
					break;
				case 6:
					printf ( "%03d%03d\n" , a , b );
					break;
				default:
					printf ( "%04d%04d\n" , a , b );
				}
			}
			if ( a == temp && b == temp )	break;
			if ( b == temp )
			{
				b = 0;
				a++;
			}
			else
				b++;
		}
		//1//
		//time limit
		/*
		string str1 ( n , '0' );
		string str2 ( n , '9' );
		while ( true )
		{
			temp = n / 2;
			string s1 ( str1.begin() , str1.begin() + temp );
			string s2 ( str1.begin() + temp , str1.end() );
			string s = s1 + " " + s2 + " " + str1;
			stringstream ss ( s );	ss >> f >> e >> o;
			if ( pow ( f + e , 2. ) == o )
				cout << str1 << endl;
			if ( str1 == str2 )	break;
			o++;
			stringstream ss1;	ss1 << o;	str1 = ss1.str();
			string t ( n - str1.length() , '0' );
			str1 = t + str1;
		}
		*/
	}
	return 0;
}