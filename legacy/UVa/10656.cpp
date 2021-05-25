#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	int n, x;
	bool b;
	int arr[1000];
	while (cin >> n && n)
	{
		b = false;
		for (int i = 0; i < n && cin >> arr[i]; i++)
			if (!b && arr[i])
				b = true;
		if (!b)
			cout << "0" << endl;
		else
		{
			b = false;
			for (int i = 0; i < n; i++)
				if (arr[i])
				{
					if (b)
						cout << " ";
					else
						b = true;
					cout << arr[i];
				}
			cout << endl;
		}
	}
	return 0;
}