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

class BritishCoins {
public:
   vector <int> coins( int pence ) 
   {
   	   /*
   	   vector<int> ANS ( 3 );
	   ANS[2] = pence;
	   for ( int i = 2 , x = 12 ; i > 0 ; x += 8 , i-- )
	   {
		   ANS[i-1] = ANS[i] / x;
		   ANS[i] = ANS[i] % x;
	   }
	   return ANS;
	   */

   	   /*
	   vector <int> Res ( 3 );
	   Res[0] = pence / 240;
	   pence -= ( Res[0] * 240 );
	   Res[1] = pence / 12;
	   pence -= ( Res[1] * 12 );
	   Res[2] = pence;
	   return Res;
	   */
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
	
	template<typename T> ostream& operator<<( ostream &os, const vector<T> &v ) { os << "{"; for ( typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case( int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed ) { 
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
			int pence                 = 533;
			int expected[]            = { 2,   4,   5 };

			clock_t moj_start_time    = clock();
			vector <int> received     = BritishCoins().coins( pence );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 1: {
			int pence                 = 0;
			int expected[]            = { 0,   0,   0 };

			clock_t moj_start_time    = clock();
			vector <int> received     = BritishCoins().coins( pence );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 2: {
			int pence                 = 6;
			int expected[]            = { 0,   0,   6 };

			clock_t moj_start_time    = clock();
			vector <int> received     = BritishCoins().coins( pence );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 3: {
			int pence                 = 4091;
			int expected[]            = { 17,   0,   11 };

			clock_t moj_start_time    = clock();
			vector <int> received     = BritishCoins().coins( pence );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 4: {
			int pence                 = 10000;
			int expected[]            = { 41,   13,   4 };

			clock_t moj_start_time    = clock();
			vector <int> received     = BritishCoins().coins( pence );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			int pence                 = ;
			int expected[]            = ;

			clock_t moj_start_time    = clock();
			vector <int> received     = BritishCoins().coins( pence );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int pence                 = ;
			int expected[]            = ;

			clock_t moj_start_time    = clock();
			vector <int> received     = BritishCoins().coins( pence );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}*/
/*      case 7: {
			int pence                 = ;
			int expected[]            = ;

			clock_t moj_start_time    = clock();
			vector <int> received     = BritishCoins().coins( pence );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
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
