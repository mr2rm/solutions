/*
ID: mohamma58
PROG: friday
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
	ifstream fin ( "friday.in" );
	ofstream fout ( "friday.out" );
	int sum = 0 , index , n;
	fin >> n;
	int Days[7] = { 0 };
	//memset ( Days , 0 , sizeof ( Days ) );
	int Months[12] = { 31 , 0 , 31 , 30 , 31 , 30 , 31 ,  31  , 30  , 31 , 30 , 31 };
	for ( int i = 1900 ; i < 1900 + n ; i++ )
	{
		Months[1] = ( i % 400 == 0 || ( i % 100 != 0 && i % 4 == 0 ) ? 29 : 28 );
		for ( int j = 0 ; j < 12 ; j++ )
		{
			index = ( sum + 13 ) % 7;
			index = ( index + 1 == 7 ? 0 : index + 1 );
			Days[index]++;
			sum += Months[j];
		}
	}
	fout << Days[0];
	for ( int i = 1 ; i < 7 ; i++ )
		fout << " " << Days[i];
	fout << endl;
	return 0;
}