#include <iostream> 
                                                       
using namespace std;

int main()
{
	int counter = 0 , n;
	unsigned int *testcase;
	unsigned int reverse , tc;
	cin >> n;
	testcase = new unsigned int [n];
	for ( int i = 0 ; i < n ; i++ )
		cin >> testcase[i];
	for ( int i = 0 ; i < n ; i++ )
	{
		unsigned int m = testcase[i];
		counter = 0;
		while ( testcase[i] >= m )
		{
			tc = testcase[i];
			reverse = 0;
			while ( tc != 0 )
			{
				reverse = reverse * 10;
				reverse = reverse + (tc % 10);
				tc = tc / 10;
			}
			if ( reverse != testcase[i] )
			{
				m = testcase[i];
				testcase[i] = reverse + testcase[i];
				counter++;
			}
			else
			{
				cout << counter << " " << reverse << endl;
				break;
			}
		}
	}
	return 0;
}