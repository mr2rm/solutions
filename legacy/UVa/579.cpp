#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdio>

using namespace std;

int main ()
{
	freopen ( "ClockHands.in" , "r" , stdin );
	string str;
	double Minute , Hour;
	char ch;
	while ( cin >> str )
	{
		double Result;
		stringstream ss ( str );
		ss >> Hour >> ch >> Minute;
		if ( Hour == 0 && Minute == 0 )	break;
		Hour *= 5;
		Hour += ( Minute / 12 );
		Result = fabs ( Hour - Minute ) * 6;
		Result = min ( Result , 360 - Result );
		printf ( "%.3lf\n" , Result );
	}
	return 0;
}
