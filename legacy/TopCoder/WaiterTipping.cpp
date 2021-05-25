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

class WaiterTipping {
public:
   int maxPercent( int total, int taxPercent, int money ) 
   {
	   int all = total + floor ( total * taxPercent * 0.01 );
	   int tip = -1;
	   if ( money >= all )
	   {
		   int def = money - all;
		   tip = floor ( ( def * 100. ) / total );
		   for ( int i = tip + 1; floor ( ( i * total ) / 100. ) == def ; i++ )
			   tip = i;
	   }
	   return tip;
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
			int total                 = 500;
			int taxPercent            = 10;
			int money                 = 600;
			int expected              = 10;

			clock_t moj_start_time    = clock();
			int received              = WaiterTipping().maxPercent( total, taxPercent, money );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int total                 = 500;
			int taxPercent            = 10;
			int money                 = 604;
			int expected              = 10;

			clock_t moj_start_time    = clock();
			int received              = WaiterTipping().maxPercent( total, taxPercent, money );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int total                 = 850;
			int taxPercent            = 8;
			int money                 = 870;
			int expected              = -1;

			clock_t moj_start_time    = clock();
			int received              = WaiterTipping().maxPercent( total, taxPercent, money );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			int total                 = 226;
			int taxPercent            = 48;
			int money                 = 584;
			int expected              = 111;

			clock_t moj_start_time    = clock();
			int received              = WaiterTipping().maxPercent( total, taxPercent, money );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			int total                 = 123;
			int taxPercent            = 52;
			int money                 = 696;
			int expected              = 415;

			clock_t moj_start_time    = clock();
			int received              = WaiterTipping().maxPercent( total, taxPercent, money );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 5: {
			int total                 = 500;
			int taxPercent            = 10;
			int money                 = 550;
			int expected              = 0;

			clock_t moj_start_time    = clock();
			int received              = WaiterTipping().maxPercent( total, taxPercent, money );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 6: {
			int total                 = ;
			int taxPercent            = ;
			int money                 = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = WaiterTipping().maxPercent( total, taxPercent, money );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			int total                 = ;
			int taxPercent            = ;
			int money                 = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = WaiterTipping().maxPercent( total, taxPercent, money );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 8: {
			int total                 = ;
			int taxPercent            = ;
			int money                 = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = WaiterTipping().maxPercent( total, taxPercent, money );
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
