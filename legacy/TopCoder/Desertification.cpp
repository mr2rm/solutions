// Paste me into the FileEdit configuration dialog

#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <bitset>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstdio>

using namespace std;

class Desertification {
public:
   int desertArea( vector <string> island, int T ) 
   {
	   int Result = 0;
	   int X = island.size();
	   int Y = island[0].length();
	   int x , y;
	   vector < vector<int> > Years ( X , vector<int> ( Y ) );
	   int Arr[4][2] = { { 1 , 0 } , { 0 , 1 } , { -1 , 0 } , { 0 , -1 } };

	   for ( int i = 0 ; i < X ; i++ )
		   for ( int j = 0 ; j < Y ; j++ )
			   if ( island[i][j] == 'D' )
			   {
				   Result++;
				   Years[i][j] = 0;
			   }
			   else
				   Years[i][j] = -1;
	   
	   for ( int year = 0 ; year < T && Result != 0 && Result != X*Y ; year++ )
		   for ( int i = 0 ; i < X ; i++ )
			   for ( int j = 0 ; j < Y ; j++ )
				   if ( Years[i][j] != -1 && year == Years[i][j] )
				   {
					   for ( int k = 0 ; k < 4 ; k++ )
					   {
						   x = Arr[k][0] + i;
						   y = Arr[k][1] + j;
						   if ( x >= 0 && x < X && y >= 0 && y < Y && Years[x][y] == -1 )
						   {
							   Years[x][y] = Years[i][j] + 1;
							   Result++;
						   }
					   }
				   }
	   return Result;
   }
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test( int casenum = -1 ) {
		if ( casenum != -1 ) {
			if ( run_test_case( casenum ) == -1 )
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			return;
		}
		
		int correct = 0, total = 0;
		for ( int i=0;; ++i ) {
			int x = run_test_case(i);
			if ( x == -1 ) {
				if ( i >= 100 ) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if ( total == 0 ) {
			cerr << "No test cases run." << endl;
		} else if ( correct < total ) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case( int casenum, const int &expected, const int &received, clock_t elapsed ) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if ( expected == received ) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			string island[]           = {"FFF",  "FDF",  "FFF"};
			int T                     = 1;
			int expected              = 5;

			clock_t moj_start_time    = clock();
			int received              = Desertification().desertArea( vector <string>( island, island + ( sizeof island / sizeof island[0] ) ), T );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			string island[]           = {"FFF",  "FDF",  "FFF"};
			int T                     = 2;
			int expected              = 9;

			clock_t moj_start_time    = clock();
			int received              = Desertification().desertArea( vector <string>( island, island + ( sizeof island / sizeof island[0] ) ), T );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			string island[]           = {"FFFFF",  "FFDFF",  "FFFFD",  "FFFFF",  "FFFFF"};
			int T                     = 2;
			int expected              = 17;

			clock_t moj_start_time    = clock();
			int received              = Desertification().desertArea( vector <string>( island, island + ( sizeof island / sizeof island[0] ) ), T );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			string island[]           = {"FFFFFF",  "FFFFFF",  "FFFFFF",  "FFFFFF"};
			int T                     = 1000000000;
			int expected              = 0;

			clock_t moj_start_time    = clock();
			int received              = Desertification().desertArea( vector <string>( island, island + ( sizeof island / sizeof island[0] ) ), T );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			string island[]           = {"FFFFFDFFFF",  "FDFDFFFFFF",  "FFFFFFFFFD",  "FFFFFFFFFF",  "DDFFFFFFFF",   "FFFFFFFFFD",  "FFFFFFFFFF",  "FFFFFFFDFF",  "FFFFFFFDFF",  "FFFFDDFFFF"};
			int T                     = 3;
			int expected              = 90;

			clock_t moj_start_time    = clock();
			int received              = Desertification().desertArea( vector <string>( island, island + ( sizeof island / sizeof island[0] ) ), T );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 5: {
			string island[]           = {"FFFFFDFFFF",  "FDFDFFFFFF",  "FFFFFFFFFD",  "FFFFFFFFFF",  "DDFFFFFFFF",   "FFFFFFFFFD",  "FFFFFFFFFF",  "FFFFFFFDFF",  "FFFFFFFDFF",  "FFFFDDFFFF"};
			int T                     = 98765432;
			int expected              = 100;

			clock_t moj_start_time    = clock();
			int received              = Desertification().desertArea( vector <string>( island, island + ( sizeof island / sizeof island[0] ) ), T );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 6: {
			string island[]           = ;
			int T                     = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Desertification().desertArea( vector <string>( island, island + ( sizeof island / sizeof island[0] ) ), T );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			string island[]           = ;
			int T                     = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Desertification().desertArea( vector <string>( island, island + ( sizeof island / sizeof island[0] ) ), T );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 8: {
			string island[]           = ;
			int T                     = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Desertification().desertArea( vector <string>( island, island + ( sizeof island / sizeof island[0] ) ), T );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
		default:
			return -1;
		}
	}
}
 

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
