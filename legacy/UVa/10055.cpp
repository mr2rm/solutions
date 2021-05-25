#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
	//freopen ( "Hashmat The Brave Warrior.in" , "r" , stdin );
	
	long long a , b , c;

	while ( cin >> a >> b )
	{
		c = b - a;
		c = fabs ( (double) c );
		cout << c << endl;
	}

	return 0;
}