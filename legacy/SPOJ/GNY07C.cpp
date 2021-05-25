#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <string> v ( 27 , "00000" );
char arr[21][21];
int mark[21][21];

void precomputing ()
{
	int x;
	for ( int i = 0 ; i < 27 ; i++ )
	{
		x = i;
		for ( int j = 0 ; x != 0 ; j++ )
		{
			if ( x % 2 == 1 )
				v[i][4-j] = '1';
			x /= 2;
		}
	}
}

int main ()
{
	//freopen ( "Encoding.in" , "r" , stdin );

	precomputing ();

	int n , r , c;
	string str1;
	cin >> n;

	for ( int i = 1 ; i <= n ; i++ )
	{
		cin >> r >> c;
		getline ( cin , str1 );
		string str ( str1.begin() + 1 , str1.end() );

		string s;
		for ( int j = 0 ; j < str.length() ; j++ )
			s = s + ( str[j] == ' ' ? v[0] : v[str[j] - 'A' + 1] );

		for ( int j = 0 ; j < r ; j++ )
			for ( int k = 0 ; k < c ; arr[j][k] = '0' , mark[j][k] = 0 , k++ );

		int x , y , counter;
		counter = x = 0;	y = -1;

		for ( int j = 0 ; counter < s.length() ; j++ , j %= 4 )
			switch ( j )
			{
				case 0:
					for ( y++ ; y < c && mark[x][y] == 0 && counter < s.length() ; mark[x][y] = 1 , arr[x][y] = s[counter] , counter++ , y++ );
					y--;
					break;
				case 1:
					for ( x++ ; x < r && mark[x][y] == 0 && counter < s.length() ; mark[x][y] = 1 , arr[x][y] = s[counter] , counter++ , x++ );
					x--;
					break;
				case 2:
					for ( y-- ; y >= 0 && mark[x][y] == 0 && counter < s.length() ; mark[x][y] = 1 , arr[x][y] = s[counter] , counter++ , y-- );
					y++;
					break;
				default:
					for ( x-- ; x >= 0 && mark[x][y] == 0 && counter < s.length() ; mark[x][y] = 1 , arr[x][y] = s[counter] , counter++ , x-- );
					x++;
			}

		cout << i << " ";
		for ( int j = 0 ; j < r ; j++ )
			for ( int k = 0 ; k < c ; k++ )
				cout << arr[j][k];
		cout << endl;
	}

	return 0;
}