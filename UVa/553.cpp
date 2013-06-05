#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int arr[256];
string alpha = "ABIMSY";
int width[6] = {18, 17, 10, 20, 16, 13};
int n, x, y, tm;
string str, s;
vector <string> v;

int main ()
{
	for (int i = 0; i < 6; i++)
		arr[alpha[i]] = width[i];
	while (cin >> n && cin.ignore () && getline (cin, str) && n)
	{
		v.clear ();
		y = x = 0;
		for (int i = 0; i < str.length(); i++)
			if (str[i] != ' ')
				n -= arr[str[i]];
			else
				y++;
		stringstream ss (str);
		while (ss >> s)
		{
			v.push_back (s);
			x += s.length() - 1;
		}
		tm = y*3 + x;
		tm = n / tm;	n -= x*tm;	x = tm;
		tm = n / y;		n -= y*tm;	y = tm;
		if (v.size () > 1)
		{
			tm = n / (v.size()-1);	
			n %= v.size()-1;	
			n = v.size() - 1 - n;
		}
		for (int i = 0; i < v.size(); i++)
			for (int j = 0; j < v[i].length(); j++)
			{
				cout << v[i][j];
				if (j < v[i].length()-1)
					cout << "/(" << x << ")";
				else 
				{
					if (i < v.size()-1)
					{
						int temp = y + tm;
						if (i >= n)
							temp++;
						cout << "/(" << temp << ")";
					}
					else if (str[str.length()-1] == ' ') 
						cout << "/(" << y << ")";
				}	
			}			
		cout << endl;
	}
	return 0;
}