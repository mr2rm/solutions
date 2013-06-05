#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
	int n, tmp, num, s, car, sz;
	vector <string> fact (1001);
	fact[0] = fact[1] = "1";
	for (int I = 2; I <= 1000; I++)
	{
		tmp = I;
		sz = fact[I-1].length();
		string sum (sz, '0');
		for (int J = sz-1; tmp; J--)
		{
			num = tmp % 10;
			tmp /= 10;
			if (num)
			{
				car = 0;
				for (int K = sz-1, L = J; K >= 0; K--, L--)
				{
					s = (fact[I-1][K]-'0')*num + car;
					if (L >= 0)
					{
						s += (sum[L]-'0');
						sum[L] = '0'+(s % 10);
					}
					else
					{
						sum = string (1, '0'+(s % 10)) + sum;
						J++;
					}
					car = s / 10;
				}
				if (car)
				{
					sum = string (1, '0'+car) + sum;
					J++;
				}
			}
		}
		fact[I] = sum;
	}
	while (cin >> n)
		cout << n << "!" << endl << fact[n] << endl;
	return 0;
}