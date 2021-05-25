#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

vector<int> primes;
set<int> aprimes;
set<int>::iterator it;

void PreComputing1 ()
{
	primes.push_back ( 2 );
	bool b;
	for ( int i = 3 ; i < 1e+6 ; i++ )
	{
		b = true;
		for ( int j = 0 ; j < primes.size() && primes[j] < i ; j++ )
			if ( i % primes[j] == 0 )
			{
				b = false;
				break;
			}
		if ( b == true )
			primes.push_back ( i );
	}
}

void PreComputing2 ()
{
	aprimes.insert ( 4 );
	it = aprimes.end();
	it--;
	for ( int i = 0 ; i < primes.size() ; i++ )
		for ( int j = 2 ; *it < 1e+12 ; j++ , it-- )
		{
			aprimes.insert ( pow ( (double) primes[i] , j ) );
			it = aprimes.end();
		}	
}

int main ()
{
	PreComputing1 ();
	PreComputing2 ();
	int inl , inh ;
	int counter = 0 ;
	int n , low , high;
	cin >> n;
	for ( int i = 0 ; i < n && cin >> low >> high ; i++ )
	{
		for ( it = aprimes.begin() ; it != aprimes.end() ; i++ )
			if ( *it >= low )
				break;
		for (  ; *it <= high ; it++ )
			counter++;
		cout << counter;
	}
	return 0;
}