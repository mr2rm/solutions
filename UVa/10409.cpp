#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main ()
{
	int n;
	int dir[3];
	string str;
	while (cin >> n && n)
	{
		for (int I = 0; I < 3; I++)
			dir[I] = I+1;
		for (int I = 0; I < n; I++)
		{
			cin >> str;
			switch (str[0])
			{
				case 'n':
					swap (dir[0], dir[1]);
					dir[0] = 7 - dir[0];
					break;
				case 's':
					swap (dir[0], dir[1]);
					dir[1] = 7 - dir[1];
					break;
				case 'w':
					swap (dir[0], dir[2]);
					dir[0] = 7 - dir[0];
					break;
				default:
					swap (dir[0], dir[2]);
					dir[2] = 7 - dir[2];
			}
		}
		cout << dir[0] << endl;
	}
	return 0;
}
