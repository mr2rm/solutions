#include <iostream>

using namespace std;

int main()
{
	int t;
	int r, w;
	for (cin >> t; t && cin >> r >> w; t--)
	{
		r /= 3;	w /= 3;
		cout << r*w << endl;
	}
	return 0;
}