#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int res[14] = {0};

int main ()
{
	int n, temp;
	string str;
	while (cin >> n && n)
	{	
		if (res[n])
		{
			cout << res[n] << endl;
			continue;
		}
		bool b = false;
		for (int I = n + 1; 1; I++)
		{
			str = string (n, '1') + string (n, '0');
			temp = -1;
			while (1)
			{
				temp += I;
				temp %= str.length();
				if (str[temp] == '1')
				{
					if (str.size() == n)
						b = true;
					break;
				}
				else
				{
					str.erase (str.begin()+temp);
					temp--;
				}
			}
			if (b)
			{
				cout << I << endl;
				res[n] = I;
				break;
			}
		}
	}
	return 0;
}
