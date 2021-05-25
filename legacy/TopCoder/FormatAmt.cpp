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

class FormatAmt {
public:
   string amount( int dollars, int cents )
   {
	   dollars += ( cents / 100 );
	   cents %= 100;
	   string str1 , str2 , c , d , ANS;
	   stringstream ss1 ( str1 );
	   ss1 << dollars;
	   ss1 >> d;
	   for ( int i = d.length() - 3 ; i > 0 ; i -= 3 )
		   d.insert ( i , "," );
	   d = "$" + d;
	   stringstream ss2 ( str2 );
	   ss2 << cents;
	   ss2 >> c;
	   if ( c.length() == 1 )
		   c = "0" + c;
	   c = "." + c;
	   ANS = d + c;
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
			int dollars               = 123456;
			int cents                 = 0;
			string expected           = "$123,456.00";

			clock_t moj_start_time    = clock();
			string received           = FormatAmt().amount( dollars, cents );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int dollars               = 49734321;
			int cents                 = 9;
			string expected           = "$49,734,321.09";

			clock_t moj_start_time    = clock();
			string received           = FormatAmt().amount( dollars, cents );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int dollars               = 0;
			int cents                 = 99;
			string expected           = "$0.99";

			clock_t moj_start_time    = clock();
			string received           = FormatAmt().amount( dollars, cents );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			int dollars               = 249;
			int cents                 = 30;
			string expected           = "$249.30";

			clock_t moj_start_time    = clock();
			string received           = FormatAmt().amount( dollars, cents );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			int dollars               = 1000;
			int cents                 = 1;
			string expected           = "$1,000.01";

			clock_t moj_start_time    = clock();
			string received           = FormatAmt().amount( dollars, cents );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			int dollars               = ;
			int cents                 = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = FormatAmt().amount( dollars, cents );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int dollars               = ;
			int cents                 = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = FormatAmt().amount( dollars, cents );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			int dollars               = ;
			int cents                 = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = FormatAmt().amount( dollars, cents );
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
