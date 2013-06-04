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

class RaceApproximator {
public:
   string timeToBeat( int d1, int t1, int d2, int t2, int raceDistance ) 
   {
	   int Result = t1 * exp ( ( log((double)d1/raceDistance) / log((double)d1/d2) ) * log ((double)t2/t1) );
	   string Answer;
	   int D , M;
	   for ( int i = 2 ; i >= 0 ; i-- )
	   {
		   M = pow ( 60. , i );
		   D = Result / M;
		   if ( i != 2 )
			   Answer += (char)( '0' + D / 10 );
		   Answer += (char)( '0' + D % 10 );
		   if ( i != 0 )	Answer += ':';
		   Result %= M;
	   }
	   return Answer;
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
	
	int verify_case( int casenum, const string &expected, const string &received, clock_t elapsed ) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			int d1                    = 800;
			int t1                    = 118;
			int d2                    = 5000;
			int t2                    = 906;
			int raceDistance          = 1500;
			string expected           = "0:03:57";

			clock_t moj_start_time    = clock();
			string received           = RaceApproximator().timeToBeat( d1, t1, d2, t2, raceDistance );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int d1                    = 400;
			int t1                    = 65;
			int d2                    = 1600;
			int t2                    = 350;
			int raceDistance          = 800;
			string expected           = "0:02:30";

			clock_t moj_start_time    = clock();
			string received           = RaceApproximator().timeToBeat( d1, t1, d2, t2, raceDistance );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int d1                    = 1600;
			int t1                    = 299;
			int d2                    = 10000;
			int t2                    = 2360;
			int raceDistance          = 5000;
			string expected           = "0:18:00";

			clock_t moj_start_time    = clock();
			string received           = RaceApproximator().timeToBeat( d1, t1, d2, t2, raceDistance );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			int d1                    = 100;
			int t1                    = 17;
			int d2                    = 10000;
			int t2                    = 4500;
			int raceDistance          = 9000;
			string expected           = "1:06:00";

			clock_t moj_start_time    = clock();
			string received           = RaceApproximator().timeToBeat( d1, t1, d2, t2, raceDistance );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			int d1                    = 156;
			int t1                    = 117;
			int d2                    = 3863;
			int t2                    = 2754;
			int raceDistance          = 1755;
			string expected           = "0:21:06";

			clock_t moj_start_time    = clock();
			string received           = RaceApproximator().timeToBeat( d1, t1, d2, t2, raceDistance );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			int d1                    = ;
			int t1                    = ;
			int d2                    = ;
			int t2                    = ;
			int raceDistance          = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = RaceApproximator().timeToBeat( d1, t1, d2, t2, raceDistance );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int d1                    = ;
			int t1                    = ;
			int d2                    = ;
			int t2                    = ;
			int raceDistance          = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = RaceApproximator().timeToBeat( d1, t1, d2, t2, raceDistance );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			int d1                    = ;
			int t1                    = ;
			int d2                    = ;
			int t2                    = ;
			int raceDistance          = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = RaceApproximator().timeToBeat( d1, t1, d2, t2, raceDistance );
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
