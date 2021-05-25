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

class EllipseCoverage {
public:
   int calculateCoverage( int x1, int y1, int x2, int y2, int d ) 
   { 
	   int const Lower = -300;
	   int const Upper = 300;
	   double D1 , D2 , D;
	   int Pow1 , Pow2;
	   int Result = 0;
	   for ( int x = Lower ; x <= Upper ; x++ )
		   for ( int y = Lower ; y <= Upper ; y++ )
		   {
			   Pow1 = pow ( fabs((double)(x-x1)) , 2 );
			   Pow2 = pow ( fabs((double)(y-y1)) , 2 );
			   D1 = sqrt ( (double)Pow1 + Pow2 );
			   Pow1 = pow ( fabs((double)(x-x2)) , 2 );
			   Pow2 = pow ( fabs((double)(y-y2)) , 2 );
			   D2 = sqrt ( (double)Pow1 + Pow2 );
			   D = D1 + D2;
			   if ( D < d )
				   Result++;
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
			int x1                    = 0;
			int y1                    = 0;
			int x2                    = 0;
			int y2                    = 0;
			int d                     = 4;
			int expected              = 9;

			clock_t moj_start_time    = clock();
			int received              = EllipseCoverage().calculateCoverage( x1, y1, x2, y2, d );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int x1                    = -3;
			int y1                    = 0;
			int x2                    = 3;
			int y2                    = 0;
			int d                     = 10;
			int expected              = 59;

			clock_t moj_start_time    = clock();
			int received              = EllipseCoverage().calculateCoverage( x1, y1, x2, y2, d );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int x1                    = 10;
			int y1                    = 12;
			int x2                    = 8;
			int y2                    = 14;
			int d                     = 50;
			int expected              = 1941;

			clock_t moj_start_time    = clock();
			int received              = EllipseCoverage().calculateCoverage( x1, y1, x2, y2, d );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			int x1                    = 0;
			int y1                    = 0;
			int x2                    = 0;
			int y2                    = 0;
			int d                     = 200;
			int expected              = 31397;

			clock_t moj_start_time    = clock();
			int received              = EllipseCoverage().calculateCoverage( x1, y1, x2, y2, d );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			int x1                    = 13;
			int y1                    = -23;
			int x2                    = 49;
			int y2                    = 91;
			int d                     = 200;
			int expected              = 25187;

			clock_t moj_start_time    = clock();
			int received              = EllipseCoverage().calculateCoverage( x1, y1, x2, y2, d );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			int x1                    = ;
			int y1                    = ;
			int x2                    = ;
			int y2                    = ;
			int d                     = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = EllipseCoverage().calculateCoverage( x1, y1, x2, y2, d );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int x1                    = ;
			int y1                    = ;
			int x2                    = ;
			int y2                    = ;
			int d                     = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = EllipseCoverage().calculateCoverage( x1, y1, x2, y2, d );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			int x1                    = ;
			int y1                    = ;
			int x2                    = ;
			int y2                    = ;
			int d                     = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = EllipseCoverage().calculateCoverage( x1, y1, x2, y2, d );
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
