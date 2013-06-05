#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main ()
{
	char ch;
	int n, cnt;
	double d1, d2;
	double rec[10][4];
	for (n = 0; cin >> ch && ch != '*'; n++)
		cin >> rec[n][0] >> rec[n][1] >> rec[n][2] >> rec[n][3];
	for (int I = 1; cin >> d1 >> d2 && !(d1 == 9999.9 && d2 == 9999.9); I++)
	{
		cnt = 0;
		for (int J = 0; J <= n; J++)
			if (d1 > rec[J][0] && d1 < rec[J][2] && d2 > rec[J][3] && d2 < rec[J][1])
			{
				cnt++;
				cout << "Point " << I << " is contained in figure " << J+1 << endl;
			}
		if (!cnt)
			cout << "Point " << I << " is not contained in any figure" << endl;
	}
	return 0;
}