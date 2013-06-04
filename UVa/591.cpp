#include <iostream>
#include <vector>

using namespace std;

int main () 
{
	freopen ( "Box of Bricks.in" , "r" , stdin );
	int DataSets = 0 , Stacks , Bricks , Average , Result;
	while ( cin >> Stacks && Stacks != 0 )
	{
		DataSets++;
		Bricks = 0;	Result = 0;
		vector <int> TheNumbers ( Stacks );
		for ( int i = 0 ; i < Stacks ; i++ )
		{
			cin >> TheNumbers[i];
			Bricks += TheNumbers[i];
		}
		Average = Bricks / Stacks;
		for ( int i = 0 ; i < Stacks ; i++ )
			if ( TheNumbers[i] > Average )
				Result += ( TheNumbers[i] - Average );
		cout << "Set #" << DataSets << endl;
		cout << "The minimum number of moves is " << Result << "." << endl << endl;
	}
	return 0;
}