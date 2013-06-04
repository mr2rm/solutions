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

class DivToZero {
public:
   string lastTwo( int num, int factor ) 
   {
	   int n = num / 100;
	   n *= 100;
	   string Res;
	   for ( int i = 0 ; i < 100 ; i++ )
		   if ( ( n + i ) % factor == 0 )
		   {
			   if ( i / 10 == 0 )
			   {
				   string temp ( 1 , '0' + i );
				   Res = "0" + temp;
			   }
			   else
			   {
				   Res.push_back ( '0' + i / 10 );
				   Res.push_back ( '0' + i % 10 );
			   }
			   break;
		   }
	   return Res;
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
			int num                   = 2000000000;
			int factor                = 100;
			string expected           = "00";

			clock_t moj_start_time    = clock();
			string received           = DivToZero().lastTwo( num, factor );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int num                   = 1000;
			int factor                = 3;
			string expected           = "02";

			clock_t moj_start_time    = clock();
			string received           = DivToZero().lastTwo( num, factor );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int num                   = 23442;
			int factor                = 75;
			string expected           = "00";

			clock_t moj_start_time    = clock();
			string received           = DivToZero().lastTwo( num, factor );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			int num                   = 428392;
			int factor                = 17;
			string expected           = "15";

			clock_t moj_start_time    = clock();
			string received           = DivToZero().lastTwo( num, factor );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			int num                   = 32442;
			int factor                = 99;
			string expected           = "72";

			clock_t moj_start_time    = clock();
			string received           = DivToZero().lastTwo( num, factor );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			int num                   = ;
			int factor                = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = DivToZero().lastTwo( num, factor );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int num                   = ;
			int factor                = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = DivToZero().lastTwo( num, factor );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			int num                   = ;
			int factor                = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = DivToZero().lastTwo( num, factor );
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
