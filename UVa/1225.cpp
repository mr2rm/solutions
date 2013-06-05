#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

//2nd ---> AC
int arr[10000][10] = {0};

void digitcount (int x)
{
	stringstream ss;
	ss << x;
	string str = ss.str();
	for (int i = 0; i < str.length(); i++)
		arr[x][str[i]-'0']++;
	for (int i = 0; i < 10; i++)
		arr[x][i] += arr[x-1][i];
}

int main ()
{
	int t, n;
	cin >> t;
	for (int i = 1; i < 10000; i++)
		digitcount (i);
	for (; t != 0 && cin >> n; t--)
		for (int i = 0; i < 10; i++)
		{
			cout << arr[n][i];
			if (i == 9)
				cout << endl;
			else
				cout << " ";
		}
	return 0;
}

//1st ---> AC
/*int main ()
{
	int t, n;
	int arr[10];
	cin >> t;
	for (int i = 0; i < t && cin >> n; i++)
	{
		memset (arr, 0, sizeof arr);
		string str = "";
		for (int j = 1; j <= n; j++)
		{
			stringstream ss;
			ss << j;
			str += ss.str();
		}
		for (int j = 0; j < str.length(); j++)
			arr[str[j]-'0']++;
		for (int j = 0; j < 10; j++)
		{
			cout << arr[j];
			if (j == 9)
				cout << endl;
			else
				cout << " ";
		}
	}
	return 0;
}*/