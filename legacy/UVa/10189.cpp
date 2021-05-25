#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

/* ( TLE )

vector< vector<char> > T( 101 , vector<char> (101) );
vector< vector<char> > A( 100 , vector<char> (100) );

char counter ( int x , int y )		//int counter ( int x , int y )
{	
	char c = '0';					//int c = 0;
	for ( int i = x - 1 ; i <= x + 1 ; i++ )
		for ( int j = y - 1 ; j <= y + 1 ; j++ )
			if ( T[i][j] == '*')
				c++;
	return c;						//return '0' + c;
}

int main ()
{
	//freopen ( "Minesweeper.in" , "r" , stdin );
	int n , m;
	int f = 1;
	while ( cin >> n >> m && ( n != 0 && m != 0 ) )
	{
		for ( int i = 0 ; i <= n + 1 ; i++ )
			for ( int j = 0 ; j <= m + 1 ; j++ )
				if ( i == 0 || i == n + 1 || j == 0 || j == m + 1 )
					T[i][j]=' ';
				else 
					cin >> T[i][j];
		for ( int i = 1 ; i <= n ; i++ )
			for ( int j = 1 ; j <= m ; j++ )
				if ( T[i][j] == '.' )
					A[i-1][j-1] = counter ( i , j );
				else
					A[i-1][j-1] = '*';
		cout << "Field #" << f << ":" << endl;
		for ( int i = 0 ; i < n ; i++ )
		{
			for ( int j = 0 ; j < m ; j++ )
				cout << A[i][j];
			cout << endl;
		}
		cout << endl;
		f++;
	}
	return 0;
}
*/

vector <string> Q ( 100 );
vector < vector <int> > A ( 100 , vector <int> ( 100 ) );
int dir[8][2] = { { -1 , -1 } , { -1 , 0 } , { -1 , 1 } , { 0 , 1 } , { 1 , 1 } , { 1 , 0 } , { 1 , -1 } , { 0 , -1 } };

int main ()
{
    //freopen ( "Minesweeper.in" , "r" , stdin );

    int n , m;
    int counter = 1;

    for ( ; cin >> n >> m && ( n != 0 && m != 0 ) ; counter++ )
    {
        for ( int i = 0 ; i < n ; i++ )
            cin >> Q[i];

        for ( int i = 0 ; i < n ; i++ )
            for ( int j = 0 ; j < m ; j++ )
                A[i][j] = ( Q[i][j] == '*' ? -1 : 0 );

        for ( int i = 0 ; i < n ; i++ )
            for ( int j = 0 ; j < m ; j++ )
                if ( Q[i][j] == '*' )
                    for ( int k = 0 ; k < 8 ; k++ )
                    {
                        int x = i + dir[k][0];
                        int y = j + dir[k][1];
                        if ( !( x < 0 || y < 0 || x > n - 1 || y > m - 1 || A[x][y] == -1 ) )
                            A[x][y]++;
                    }

		if ( counter != 1 )	cout << endl;
        cout <<"Field #" << counter << ":" << endl;
        for ( int i = 0 ; i < n ; i++ , cout << endl )
            for ( int j = 0 ; j < m ; j++ )
                if ( A[i][j] == -1 )
                    cout << "*";
                else
                    cout << A[i][j];
    }

    return 0;
}

