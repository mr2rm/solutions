#include <iostream>
#include <vector>

using namespace std;

struct triple
{
	int Left;
	int Height;
	int Right;
};

int main ()
{
	freopen ("105.in", "r", stdin);
	int L, H, R;
	vector <triple> v;
	int maxi = -1;
	while (cin >> L >> H >> R)
	{
		if (R > maxi)
			maxi = R;
		triple p;
		p.Left = L;
		p.Height = H;
		p.Right = R;
		v.push_back (p);
	}
	int h = -1;
	vector <int> Res;
	for (int i = v[0].Left; i <= maxi; i++)
	{
		int temp = -1;
		for (int j = 0; j < v.size(); j++)
			if (i >= v[j].Left && i < v[j].Right && v[j].Height > temp)
				temp = v[j].Height;
		if (temp != h)
		{
			h = temp;
			cout << i << " ";
			if (temp == -1)	cout << "0";
			else			cout << temp;
			if (i == maxi)	cout << endl;
			else			cout << " ";
		}	
	}
	return 0;
}