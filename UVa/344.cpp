#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main ()
{
	freopen ( "Roman Digititis.in" , "r" , stdin );
	int n;
	int arr[9] = { 1 , 4 , 5 , 9 , 10 , 40 , 50 , 90 , 100 };
	string s1 ( "ivxlc" );
	string s2 ( "ivixxlxc" );
	vector <string> v( 9 );
	int ind1 , ind2;
	ind1 = ind2 = 0;
	for ( int i = 0 ; i < 9 ; i++ )
		if ( i % 2 == 0 )
		{
			v[i] = s1[ind1];
			ind1++;
		}
		else
		{
			string st ( s2.begin() + ind2 , s2.begin() + ind2 + 2 );
			v[i] = st;
			ind2 += 2;
		}
	while ( cin >> n && n != 0 )
	{
		int Res[256] = { 0 };
		for ( int i = 1 ; i <= n ; i++ )
		{
			string str;
			int t = i;
			for ( int j = 8 ; t != 0 ; j-- )
				if ( t / arr[j] != 0 )
				{
					string stem;
					for ( int k = 0 ; k < t / arr[j] ; k++ )
						stem += v[j];
					t %= arr[j];
					str += stem;
				}
			for ( int j = 0 ; j < str.length() ; j++ )
				Res[str[j]]++;
		}
		cout << n << ":";
		for ( int i = 0 ; i < 5 ; i++ )
		{
			cout << " " << Res[s1[i]] << " " << s1[i];
			if ( i == 4 )
				cout << endl;
			else
				cout << ",";
		}
	}
	return 0;
}