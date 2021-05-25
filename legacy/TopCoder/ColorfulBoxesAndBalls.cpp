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

class ColorfulBoxesAndBalls {
public:
   int getMaximum( int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors ) 
   {
	   int Result = (numRed * onlyRed ) + ( numBlue * onlyBlue );
	   int Temp;
	   if ( numRed > numBlue )
		   Temp = ( 2 * numBlue * bothColors ) + onlyRed * ( numRed - numBlue );
	   else
		   Temp = ( 2 * numRed * bothColors ) + onlyBlue * ( numBlue - numRed );
	   Result = max ( Temp , Result );
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
			int numRed                = 2;
			int numBlue               = 3;
			int onlyRed               = 100;
			int onlyBlue              = 400;
			int bothColors            = 200;
			int expected              = 1400;

			clock_t moj_start_time    = clock();
			int received              = ColorfulBoxesAndBalls().getMaximum( numRed, numBlue, onlyRed, onlyBlue, bothColors );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int numRed                = 2;
			int numBlue               = 3;
			int onlyRed               = 100;
			int onlyBlue              = 400;
			int bothColors            = 300;
			int expected              = 1600;

			clock_t moj_start_time    = clock();
			int received              = ColorfulBoxesAndBalls().getMaximum( numRed, numBlue, onlyRed, onlyBlue, bothColors );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int numRed                = 5;
			int numBlue               = 5;
			int onlyRed               = 464;
			int onlyBlue              = 464;
			int bothColors            = 464;
			int expected              = 4640;

			clock_t moj_start_time    = clock();
			int received              = ColorfulBoxesAndBalls().getMaximum( numRed, numBlue, onlyRed, onlyBlue, bothColors );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			int numRed                = 1;
			int numBlue               = 4;
			int onlyRed               = 20;
			int onlyBlue              = -30;
			int bothColors            = -10;
			int expected              = -100;

			clock_t moj_start_time    = clock();
			int received              = ColorfulBoxesAndBalls().getMaximum( numRed, numBlue, onlyRed, onlyBlue, bothColors );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			int numRed                = 9;
			int numBlue               = 1;
			int onlyRed               = -1;
			int onlyBlue              = -10;
			int bothColors            = 4;
			int expected              = 0;

			clock_t moj_start_time    = clock();
			int received              = ColorfulBoxesAndBalls().getMaximum( numRed, numBlue, onlyRed, onlyBlue, bothColors );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			int numRed                = ;
			int numBlue               = ;
			int onlyRed               = ;
			int onlyBlue              = ;
			int bothColors            = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = ColorfulBoxesAndBalls().getMaximum( numRed, numBlue, onlyRed, onlyBlue, bothColors );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int numRed                = ;
			int numBlue               = ;
			int onlyRed               = ;
			int onlyBlue              = ;
			int bothColors            = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = ColorfulBoxesAndBalls().getMaximum( numRed, numBlue, onlyRed, onlyBlue, bothColors );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			int numRed                = ;
			int numBlue               = ;
			int onlyRed               = ;
			int onlyBlue              = ;
			int bothColors            = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = ColorfulBoxesAndBalls().getMaximum( numRed, numBlue, onlyRed, onlyBlue, bothColors );
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
