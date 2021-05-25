#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	//freopen ( "Error Correction.in" , "r" , stdin );
	int n;
	while ( cin >> n && n != 0 )
	{
		 vector < vector<int> > v ( n , vector<int> ( n ) );
		 vector <int> sumx ( n , 0 );
		 vector <int> sumy ( n , 0 );
		 for ( int i = 0 ; i < n ; i++ )
			 for ( int j = 0 ; j < n ; j++ )
			 {
				 cin >> v[i][j];
				 sumx[i] += v[i][j];
				 sumy[j] += v[i][j];
			 }
		 int counterx , countery , indexi , indexj;
		 counterx = countery = 0;
		 for ( int i = 0 ; i < n && counterx < 2 && countery < 2 ; i++ )
		 {
			 if ( sumx[i] % 2 != 0 )
			 {
				 counterx++;
				 indexi = i + 1;
			 }
			 if ( sumy[i] % 2 != 0 )
			 {
				 countery++;
				 indexj = i + 1;
			 }
		 }
		 if ( counterx == 0 && countery == 0 )
		 {
			 cout << "OK" << endl;
			 continue;
		 }
		 if ( counterx * countery == 1 )
		 {
			 cout << "Change bit (" << indexi << "," << indexj << ")" << endl;
			 continue;
		 }
		 cout << "Corrupt" << endl;
	}
	return 0;
}
