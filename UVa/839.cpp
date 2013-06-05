#include <iostream>

using namespace std;

int rec ()
{
	int w_1, d_1, w_2, d_2;
	cin >> w_1 >> d_1 >> w_2 >> d_2;
	if (!w_1)	
		w_1 = rec ();
	if (!w_2)	
		w_2 = rec ();
	if (w_1 < 0 || w_2 < 0 || w_1*d_1 != w_2*d_2)
		return -1;
	else
		return w_1 + w_2;
}

int main ()
{
	int t;
	for (cin >> t; t != 0; t--)
	{
		if (rec() < 0)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
		if (t > 1)
			cout << endl;
	}
	return 0;
}