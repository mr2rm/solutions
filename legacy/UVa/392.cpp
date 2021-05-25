#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int main ()
{
	string str;
	int n;
	bool b;
	while (getline(cin, str))
	{
		stringstream ss (str);
		b = false;
		for (int I = 8; I >= 0 && ss >> n; I--)
		{
			if (!I)
			{
				if (!b)
					cout << n << endl;
				else if (n < 0)
					cout << " - " << -1*n << endl;
				else if (n > 0)
					cout << " + " << n << endl;
				else
					cout << endl;
			}
			else if (n)
			{
				if (!b)
				{
					if (n == -1)
						cout << "-";
					else if (n != 1)
						cout << n;
					b = true;
				}
				else
				{
					if (n < 0)
						cout << " - ";
					else
						cout << " + ";
					n = abs(n);
					if (n != 1)
						cout << n;
				}
				cout << "x";
				if (I != 1)
					cout << "^" << I;
			}
		}
	}
	return 0;
}