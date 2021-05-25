#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
	unsigned int n;
	while (cin >> n && n != 0)
	{
		double d = sqrt (n);
		if (d == (int)d)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}

//TLE
/*
int main ()
{
	unsigned int  n;
	bool stat;
	while (cin >> n && n != 0)
	{
		stat = false;
		for (unsigned int i = 1; i <= n; i++)
			if (n % i == 0)
			{
				if (stat)	
					stat = false;
				else
					stat = true;
			}
		if (stat)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}
*/
