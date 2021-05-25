#include <iostream>

using namespace std;

int main ()
{
	//freopen ( "Ecological Premium.in" , "r" , stdin );
	int n , f;
	int arr[3];
	long long Result;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ )
	{
		cin >> f;
		Result = 0;
		for ( int j = 0 ; j < f ; j++ )
		{
			cin >> arr[0] >> arr[1] >> arr[2];
			Result += arr[0] * arr[2];
		}
		cout << Result << endl;
	}
	return 0;
}