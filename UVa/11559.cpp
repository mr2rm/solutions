#include <iostream>

using namespace std;

int main ()
{
	int n, b, h, w;
	int p, e;
	int temp, res;
	bool b1, b2;
	while (cin >> n >> b >> h >> w)
	{
		res = -1;
		for (int i = 0; i < h && cin >> p; i++)
		{
			temp = p*n;
			b1 = b2 = false;
			if (temp <= b)
				b1 = true;
			for (int j = 0;j < w && cin >> e; j++)
				if (b1 && !b2 && n <= e)
					b2 = true;
			if (b2)
				res = (res != -1 ? min(res, temp) : temp);
		}
		if (res != -1)
			cout << res << endl;
		else
			cout << "stay home" << endl;
	}
	return 0;
}