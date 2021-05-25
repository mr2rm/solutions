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

class BunnyPuzzle {
public:
   int theCount( vector <int> bunnies ) 
   {
	   vector < vector<bool> > Flag ( 2 , vector<bool> (3000001,false) );
	   for ( int i = 0 ; i < bunnies.size() ; i++ )
		   if ( bunnies[i] >= 0 )
			   Flag[0][bunnies[i]] = true;
		   else
			   Flag[1][fabs((double)bunnies[i])] = true;
	   int Result = 0;
	   int TempRes , Neg , Counter;
	   for ( int i = 0 ; i < bunnies.size() ; i++ )
		   for ( int j = 0 ; j < bunnies.size() ; j++ )
			   if ( i != j )
			   {
				   TempRes = 2*bunnies[j]-bunnies[i];
				   Neg = 0;
				   if ( TempRes < 0 )
					   Neg = 1;
				   Counter = 0;
				   if ( Flag[Neg][fabs((double)TempRes)] == false )
				   {
					   if ( bunnies[i] < TempRes)
						   for ( int k = i + 1 ; k < bunnies.size() && bunnies[k] < TempRes ; k++ , Counter++ );
					   else
						   for ( int k = i - 1 ; k >= 0 && bunnies[k] > TempRes ; k-- , Counter++ );
					   if ( Counter == 1 )
						   Result++;
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
			int bunnies[]             = {5, 8};
			int expected              = 2;

			clock_t moj_start_time    = clock();
			int received              = BunnyPuzzle().theCount( vector <int>( bunnies, bunnies + ( sizeof bunnies / sizeof bunnies[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int bunnies[]             = {-1, 0, 1};
			int expected              = 2;

			clock_t moj_start_time    = clock();
			int received              = BunnyPuzzle().theCount( vector <int>( bunnies, bunnies + ( sizeof bunnies / sizeof bunnies[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int bunnies[]             = {0, 1, 3};
			int expected              = 3;

			clock_t moj_start_time    = clock();
			int received              = BunnyPuzzle().theCount( vector <int>( bunnies, bunnies + ( sizeof bunnies / sizeof bunnies[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			int bunnies[]             = {-677, -45, -2, 3, 8, 29, 384, 867};
			int expected              = 7;

			clock_t moj_start_time    = clock();
			int received              = BunnyPuzzle().theCount( vector <int>( bunnies, bunnies + ( sizeof bunnies / sizeof bunnies[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			int bunnies[]             = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
			int expected              = 2;

			clock_t moj_start_time    = clock();
			int received              = BunnyPuzzle().theCount( vector <int>( bunnies, bunnies + ( sizeof bunnies / sizeof bunnies[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			int bunnies[]             = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = BunnyPuzzle().theCount( vector <int>( bunnies, bunnies + ( sizeof bunnies / sizeof bunnies[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int bunnies[]             = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = BunnyPuzzle().theCount( vector <int>( bunnies, bunnies + ( sizeof bunnies / sizeof bunnies[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			int bunnies[]             = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = BunnyPuzzle().theCount( vector <int>( bunnies, bunnies + ( sizeof bunnies / sizeof bunnies[0] ) ) );
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
