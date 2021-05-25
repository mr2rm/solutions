#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int n, m;
string res;

void rec ()
{
	if (!m || n % m || n == n / m)
		res = "Boring!";
	else
	{
		stringstream ss;
		ss << n;
		res += ss.str();
		res += " ";
		n /= m;
		if (n == 1)
			res += "1";
		else
			rec ();
	}
}

int main ()
{
	while (cin >> n >> m)
	{
		res = "";
		rec ();
		cout << res << endl;
	}
	return 0;
}