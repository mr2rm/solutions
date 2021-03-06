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

class TheBoredomDivTwo {
public:
   int find( int n, int m, int j, int b ) 
   {
	   int ANS = 0;
	   /*
	   ANS += n;
	   if ( j > n )	ANS++;
	   if ( b > n ) ANS++;
	   */
	   /*
	   vector<int> mark ( n + m + 1 , 0 );
	   for ( int i = 0 ; i <= n ; i++ )
		   mark[i] = 1;
	   mark[j] = 1;
	   mark[b] = 1;
	   for ( int i = 0 ; i <= n + m ; i++ )
		   if ( mark[i] != 0 )
			   ANS++;
	   */
	   return ANS;
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
			int n                     = 1;
			int m                     = 1;
			int j                     = 1;
			int b                     = 2;
			int expected              = 2;

			clock_t moj_start_time    = clock();
			int received              = TheBoredomDivTwo().find( n, m, j, b );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int n                     = 2;
			int m                     = 1;
			int j                     = 1;
			int b                     = 2;
			int expected              = 2;

			clock_t moj_start_time    = clock();
			int received              = TheBoredomDivTwo().find( n, m, j, b );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int n                     = 1;
			int m                     = 2;
			int j                     = 3;
			int b                     = 2;
			int expected              = 3;

			clock_t moj_start_time    = clock();
			int received              = TheBoredomDivTwo().find( n, m, j, b );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			int n                     = 4;
			int m                     = 7;
			int j                     = 7;
			int b                     = 4;
			int expected              = 5;

			clock_t moj_start_time    = clock();
			int received              = TheBoredomDivTwo().find( n, m, j, b );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 4: {
			int n                     = ;
			int m                     = ;
			int j                     = ;
			int b                     = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = TheBoredomDivTwo().find( n, m, j, b );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 5: {
			int n                     = ;
			int m                     = ;
			int j                     = ;
			int b                     = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = TheBoredomDivTwo().find( n, m, j, b );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int n                     = ;
			int m                     = ;
			int j                     = ;
			int b                     = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = TheBoredomDivTwo().find( n, m, j, b );
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
