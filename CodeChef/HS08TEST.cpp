#include <iostream>

using namespace std;

int main()
{
	int n;
	double balance , temp;
	cin >> n >> balance;
	temp = balance - n - 0.5;
	if ( n % 5 == 0 && temp >= 0 )
		balance = temp;
	printf ( "%.2f\n" , balance );
	return 0;
}