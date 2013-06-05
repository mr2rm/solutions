#include <iostream>
#include <cstring>

using namespace std;

int t, n;
int arr[101];
int res[10001];

//Greedy ---> WA
/*int main ()
{
	int arr[101];
	for (int i = 0; i < 101; i++)
		arr[i] = i*i;
	int t, n;
	cin >> t;
	for (int i = 0; i < t && cin >> n; i++)
	{
		int terms = 0;
		int temp = n;
		for (int j = 100; temp != 0 && j > 0; j--)
			if (temp >= arr[j])
			{
				terms += (int)temp/arr[j];
				temp = temp%arr[j];
			}
		cout << terms << endl;
	}	
	return 0;
}*/

//DP1 ---> TL
/*void squares (int x)
{
	if (res[x] == -1)
	{
		int mini= 10001;
		for (int i = 1; i < 101 && x >= arr[i]; i++)
		{
			int temp = x - arr[i];
			squares (temp);
			mini = min (res[temp] + 1, mini);
		}
		res[x] = mini;
	}
}*/

//DP2 ---> AC
void squares (int x)
{
	int mini= 10001;
	for (int i = 1; i < 101 && x >= arr[i]; i++)
	{
		int temp = x - arr[i];
		mini = min (res[temp] + 1, mini);
	}
	res[x] = mini;
}

int main ()
{
	for (int i = 0; i < 101; i++)
		arr[i] = i * i;

	//DP1
	//memset (res, -1, sizeof res);
	
	res[0] = 0;

	//DP2
	for (int i = 1; i < 10001; i++)
		squares (i);

	cin >> t;
	for (; t != 0 && cin >> n; t--)
	{
		//DP1
		//squares (n);
		
		cout << res[n] << endl;
	}
	return 0;
}