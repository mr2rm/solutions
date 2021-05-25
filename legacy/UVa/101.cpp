#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main ()
{
	freopen ( "The Blocks Problem.in" , "r" , stdin );
	int n;
	string command , tmp;
	cin >> n;
	vector < vector <int> > blocks ( n );
	for ( int i = 0 ; i < n ; i++ )
		blocks[i].push_back ( i );
	int a , b , stacka , stackb , temp , lasta , lastb , indexa , indexb;
	while ( getline ( cin , command ) && command != "quit" )
	{
		stringstream ss ( command );	ss >> tmp >> a >> tmp >> b;
		if ( a < 0 || b < 0 || a >= n || b >= n )	continue;
		stacka = stackb = -1;
		for ( int i = 0 ; i < blocks.size() ; i++ )
			for ( int j = 0 ; j < blocks[i].size() ; j++ )
				if ( blocks[i][j] == a )
				{
					stacka = i;	indexa = j;
					if ( stacka != -1 && stackb != -1 )	break;
				}
				else if ( blocks[i][j] == b )
				{
					stackb = i;	indexb = j;
					if ( stacka != -1 && stackb != -1 )	break;
				}
		if ( a != b && stacka != stackb )
		{
			lasta = blocks[stacka].size() - 1;
			lastb = blocks[stackb].size() - 1;
			if ( tmp[1] == 'n' )
				for ( int i = lastb ; i > indexb ; i-- )
				{
					temp = blocks[stackb][i];
					blocks[temp].push_back ( temp );
					blocks[stackb].pop_back();
				}
			if ( command[0] == 'm' )
			{
				for ( int i = lasta ; i > indexa ; i-- )
				{
					temp = blocks[stacka][i];
					blocks[temp].push_back ( temp );
					blocks[stacka].pop_back();
				}
				blocks[stacka].pop_back();
				blocks[stackb].push_back ( a );
			}
			else
			{
				for ( int i = indexa ; i <= lasta ; i++ )	
					blocks[stackb].push_back ( blocks[stacka][i] );
				for ( int i = lasta ; i >= indexa ; i-- )	
					blocks[stacka].pop_back();
			}
		}
	}
	for ( int i = 0 ; i < blocks.size() ; i++ )
	{
		cout << i << ":";
		for ( int j = 0 ; j < blocks[i].size() ; j++ )
			cout << " " << blocks[i][j];
		cout << endl;
	}
	return 0;
}