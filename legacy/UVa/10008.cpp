#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
	freopen ( "What's Cryptanalysis.in" , "r" , stdin );
	int n;
	cin >> n;
	string str;
	int arr[256] = { 0 };
	for ( int i = -1 ; i < n && getline ( cin , str ) ; i++ )
		for ( int j = 0 ; j < str.length() ; j++ )
			if ( ( str[j] >= 'a' && str[j] <= 'z' ) || ( str[j] >= 'A' && str[j] <= 'Z' ) )
			{
				if ( str[j] >= 'a' && str[j] <= 'z' )	arr[str[j]-32]++;
				else	arr[str[j]]++;
			}
	vector <int> Res;
	for ( int i = 'A' ; i <= 'Z' ; i++ )
		Res.push_back ( arr[i] );
	sort ( Res.begin() , Res.end() );
	reverse ( Res.begin() , Res.end() );
	for ( int i = 0 ; i < Res.size() && Res[i] > 0 ; i++ )
		for ( int j = 'A' ; j <= 'Z' ; j++ )
			if ( arr[j] == Res[i] )
			{
				arr[j] = -1;
				cout << (char)j << " " << Res[i] << endl;;
				break;
			}
	return 0;
}
