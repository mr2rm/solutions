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

class MassiveNumbers {
public:
   string getLargest( string numberA, string numberB )
   {
       int a , b , j;
       vector <double> results ( 2 );
       vector <string> numbers ( 2 );
       string str1 , str2;
       numbers[0] = numberA;    numbers[1] = numberB;
       for ( int i = 0 ; i < 2 ; i++ )
       {
           for ( j = 0 ; numbers[i][j] != '^' ; j++ );
           str1 = string ( numbers[i].begin() , numbers[i].begin() + j );
           stringstream ss1 ( str1 );
           ss1 >> a;
           j++;
           str2 = string ( numbers[i].begin() + j , numbers[i].end() );
           stringstream ss2 ( str2 );
           ss2 >> b;
           results[i] = b * log ( a );
       }
       return
       results[0] > results[1] ? numbers[0] : numbers[1];
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
			string numberA            = "3^100";
			string numberB            = "2^150";
			string expected           = "3^100";

			clock_t moj_start_time    = clock();
			string received           = MassiveNumbers().getLargest( numberA, numberB );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			string numberA            = "1^1000";
			string numberB            = "2^1";
			string expected           = "2^1";

			clock_t moj_start_time    = clock();
			string received           = MassiveNumbers().getLargest( numberA, numberB );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			string numberA            = "893^605";
			string numberB            = "396^906";
			string expected           = "396^906";

			clock_t moj_start_time    = clock();
			string received           = MassiveNumbers().getLargest( numberA, numberB );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			string numberA            = "999^1000";
			string numberB            = "1000^999";
			string expected           = "999^1000";

			clock_t moj_start_time    = clock();
			string received           = MassiveNumbers().getLargest( numberA, numberB );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 4: {
			string numberA            = ;
			string numberB            = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = MassiveNumbers().getLargest( numberA, numberB );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 5: {
			string numberA            = ;
			string numberB            = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = MassiveNumbers().getLargest( numberA, numberB );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			string numberA            = ;
			string numberB            = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = MassiveNumbers().getLargest( numberA, numberB );
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
