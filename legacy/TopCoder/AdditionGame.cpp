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

class AdditionGame {
public:
   int getMaximumPoints( int A, int B, int C, int N ) 
   {
	   int arr[3] = { A , B , C };
	   int maxp = 0;
	   for ( int i = 0 ; i < N ; i++ )
	   {
		   int maxi = -1;
		   int index = -1;
		   int j;
		   for ( int j = 0 ; j < 3 ; j++ )
		   {
			   if ( arr[j] > maxi )
			   {
				   maxi = arr[j];
				   index = j;
			   }
		   }
		   if ( maxi == 0 )	break;
		   maxp += arr[index];
		   arr[index]--;
	   }
	   return maxp;
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
			int A                     = 3;
			int B                     = 4;
			int C                     = 5;
			int N                     = 3;
			int expected              = 13;

			clock_t moj_start_time    = clock();
			int received              = AdditionGame().getMaximumPoints( A, B, C, N );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int A                     = 1;
			int B                     = 1;
			int C                     = 1;
			int N                     = 8;
			int expected              = 3;

			clock_t moj_start_time    = clock();
			int received              = AdditionGame().getMaximumPoints( A, B, C, N );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int A                     = 3;
			int B                     = 5;
			int C                     = 48;
			int N                     = 40;
			int expected              = 1140;

			clock_t moj_start_time    = clock();
			int received              = AdditionGame().getMaximumPoints( A, B, C, N );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			int A                     = 36;
			int B                     = 36;
			int C                     = 36;
			int N                     = 13;
			int expected              = 446;

			clock_t moj_start_time    = clock();
			int received              = AdditionGame().getMaximumPoints( A, B, C, N );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			int A                     = 8;
			int B                     = 2;
			int C                     = 6;
			int N                     = 13;
			int expected              = 57;

			clock_t moj_start_time    = clock();
			int received              = AdditionGame().getMaximumPoints( A, B, C, N );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			int A                     = ;
			int B                     = ;
			int C                     = ;
			int N                     = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = AdditionGame().getMaximumPoints( A, B, C, N );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int A                     = ;
			int B                     = ;
			int C                     = ;
			int N                     = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = AdditionGame().getMaximumPoints( A, B, C, N );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			int A                     = ;
			int B                     = ;
			int C                     = ;
			int N                     = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = AdditionGame().getMaximumPoints( A, B, C, N );
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
