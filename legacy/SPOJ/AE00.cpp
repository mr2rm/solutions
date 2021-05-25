#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
	int n;
	cin >> n;
	int ANS = n;
	for ( int i = 1 ; i <= n ; i++ )
	{
		int counter = 0;
		for ( int j = 2 ; j <= sqrt ( (double) i ) ; j++ )
			if ( i % j == 0 )
				counter++;
		ANS += counter;
	}
	cout << ANS << endl;
	return 0;
}
