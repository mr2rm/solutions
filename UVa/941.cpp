#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main ()
{
	long long t, n, ind;
	string str;
	long long fact[21];
	fact[0] = 1;
	for (int I = 1; I < 21; I++)
		fact[I] = I * fact[I-1];
	for (cin >> t; t && cin >> str >> n; t--)
	{
		sort (str.begin(), str.end());
		for (int I = str.length()-1; I; I--)
		{
			ind = n / fact[I];
			n %= fact[I];
			cout << str[ind];
			str.erase (str.begin()+ ind);
		}
		cout << str << endl;
	}
	return 0;
}