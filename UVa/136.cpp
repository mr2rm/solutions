#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main ()
{
	int arr[3] = { 2 , 3 , 5 };
	set<long long> UglyNumbers;	set<long long>::iterator it;	UglyNumbers.insert ( 1 );
	int Counter;
	for ( it = UglyNumbers.begin() , Counter = 0 ; Counter != 1500 ; Counter++ , it++ )
		for ( int i = 0 ; i < 3 ; i++ )
			UglyNumbers.insert ( (*it) * arr[i] );
	vector<long long> Result ( UglyNumbers.begin() , UglyNumbers.end() );
	cout << "The 1500'th ugly number is " << Result[1499] << "." << endl;
	return 0;
}