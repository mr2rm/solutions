#include <iostream>
#include <set>

using namespace std;

/* 1 - 0.028 *//*int main()
{
	freopen ( "What is the Median.in" , "r" , stdin );
	multiset<int> ms;
	int x , median;
	cin >> x;
	ms.insert ( x );
	cout << x << endl;
	multiset<int>::iterator it = ms.begin();
	multiset<int>::iterator nit = ms.begin();
	while ( cin >> x )
	{
		ms.insert ( x );
		if ( ms.size() % 2 == 0)
		{
			if ( x <= *it )
				it--;
			else
				nit++;
			median = ( ( *it ) + ( *nit ) ) / 2 ;
			cout << median;
		}
		else 
		{
			if ( x <= *it )
				nit--;
			else 
				if ( *it <= x && x <= *nit )
			{	
				it++;
				nit--;
			}
				else
					it++;
			cout << *it;
		}
		cout << endl;
	}
	return 0;
}*/

/* 2 - 0.264 */int main ()
{
	freopen ( "What is the Median.in" , "r" , stdin );
	multiset<int> ms;
	multiset<int>::iterator it;
	int x , median;
	while ( cin >> x )
	{
		ms.insert ( x );
		it = ms.begin();
		int size2 = ( ms.size() / 2 );
		for ( int c = 0 ; c < size2 ; it++ , c++ );
		if ( ms.size() % 2 == 0 )
		{
			median = *it;
			it--;
			median += *it;
			cout << median / 2 ;
		}
		else
			cout << *it;
		cout << endl;
	}
	return 0;
}