#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int res[150];

int main ()
{
	int n, ind, sum;
	memset (res, 0, sizeof res);
	bool b;
	while (cin >> n && n)
	{
		if (!res[n])
		{
			b = false;
			for (int I = 2; !b; I++)
			{
				vector <int> v(n);
				for (int J = 0; J < n; J++)
					v[J] = J+1;
				ind = 0;
				sum = n;
				while (1)
				{
					if (v[ind] == 2)
					{
						if (v.size() == 1)
							b = true;
						break;
					}
					else
					{
						v.erase (v.begin()+ind);
						sum--;
						ind += I-1;
						ind %= sum;
					}
				}
				if (b)
					res[n] = I;
			}
		}
		cout << res[n] << endl;
	}
	return 0;
}