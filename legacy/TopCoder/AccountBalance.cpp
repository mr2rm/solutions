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

class AccountBalance {
public:
   int processTransactions( int startingBalance, vector <string> transactions )
   {
       string str;
       int temp;
       for ( int i = 0 ; i < transactions.size() ; i++ )
       {
           stringstream ss ( transactions[i] );
           ss >> str;
           ss >> temp;
           if ( str == "C" )    startingBalance += temp;
           else startingBalance -= temp;
       }
       return startingBalance;
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
			int startingBalance       = 100;
			string transactions[]     = {"C 1000", "D 500", "D 350"};
			int expected              = 250;

			clock_t moj_start_time    = clock();
			int received              = AccountBalance().processTransactions( startingBalance, vector <string>( transactions, transactions + ( sizeof transactions / sizeof transactions[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int startingBalance       = 100;
			string transactions[]     = {};
			int expected              = 100;

			clock_t moj_start_time    = clock();
			int received              = AccountBalance().processTransactions( startingBalance, vector <string>( transactions, transactions + ( sizeof transactions / sizeof transactions[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int startingBalance       = 100;
			string transactions[]     = {"D 50", "D 20", "D 40"};
			int expected              = -10;

			clock_t moj_start_time    = clock();
			int received              = AccountBalance().processTransactions( startingBalance, vector <string>( transactions, transactions + ( sizeof transactions / sizeof transactions[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			int startingBalance       = 53874;
			string transactions[]     = {"D 1234", "C 987", "D 2345", "C 654", "D 6789", "D 34567"};
			int expected              = 10580;

			clock_t moj_start_time    = clock();
			int received              = AccountBalance().processTransactions( startingBalance, vector <string>( transactions, transactions + ( sizeof transactions / sizeof transactions[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 4: {
			int startingBalance       = ;
			string transactions[]     = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = AccountBalance().processTransactions( startingBalance, vector <string>( transactions, transactions + ( sizeof transactions / sizeof transactions[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 5: {
			int startingBalance       = ;
			string transactions[]     = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = AccountBalance().processTransactions( startingBalance, vector <string>( transactions, transactions + ( sizeof transactions / sizeof transactions[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int startingBalance       = ;
			string transactions[]     = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = AccountBalance().processTransactions( startingBalance, vector <string>( transactions, transactions + ( sizeof transactions / sizeof transactions[0] ) ) );
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
