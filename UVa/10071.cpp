#include <iostream>

using namespace std;

int main ()
{
	freopen ( "Back to High School Physics.in" , "r" , stdin );
	int v , t;
	while ( cin >> v >> t )
		cout << 2 * v * t << endl;
	return 0;
}