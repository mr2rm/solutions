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

class AmoebaDivTwo {
public:
   int count( vector <string> table, int K ) 
   {
	   int statenums = 0;
	   int sum;
	   int x , y;
	   x = table.size();	y = table[0].length();

	   for ( int i = 0 ; i < x ; i++ )
	   {
		   sum = 0;
		   for ( int j = 0 ; j <= y ; j++ )
		   {
			   if ( j == y || table[i][j] == 'M' )
			   {
				   int M = sum - K + 1;
				   if ( M > 0 )
					   statenums += M;
				   sum = 0;
			   }
			   else
				   sum++;
		   }
	   }

	   for ( int j = 0 ; K != 1 && j < y ; j++ )
	   {
		   sum = 0;
		   for ( int i = 0 ; i <= x ; i++ )
		   {
			   if ( i == x || table[i][j] == 'M' )
			   {
				   int M = sum - K + 1;
				   if ( M > 0 )
					   statenums += M;
				   sum = 0;
			   }
			   else
				   sum++;
		   }
	   }

	   return statenums;
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
			string table[]            = {"MA"};
			int K                     = 2;
			int expected              = 0;

			clock_t moj_start_time    = clock();
			int received              = AmoebaDivTwo().count( vector <string>( table, table + ( sizeof table / sizeof table[0] ) ), K );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			string table[]            = {"AAA",  "AMA",  "AAA"};
			int K                     = 3;
			int expected              = 4;

			clock_t moj_start_time    = clock();
			int received              = AmoebaDivTwo().count( vector <string>( table, table + ( sizeof table / sizeof table[0] ) ), K );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			string table[]            = {"AA",  "AA",  "AA"};
			int K                     = 2;
			int expected              = 7;

			clock_t moj_start_time    = clock();
			int received              = AmoebaDivTwo().count( vector <string>( table, table + ( sizeof table / sizeof table[0] ) ), K );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			string table[]            = {"MMM",  "MMM",  "MMM"};
			int K                     = 1;
			int expected              = 0;

			clock_t moj_start_time    = clock();
			int received              = AmoebaDivTwo().count( vector <string>( table, table + ( sizeof table / sizeof table[0] ) ), K );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			string table[]            = {"AAM",  "MAM",  "AAA"};
			int K                     = 1;
			int expected              = 6;

			clock_t moj_start_time    = clock();
			int received              = AmoebaDivTwo().count( vector <string>( table, table + ( sizeof table / sizeof table[0] ) ), K );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 5: {
			string table[]            = {"AAA",  "AAM",  "AAA"};
			int K                     = 2;
			int expected              = 9;

			clock_t moj_start_time    = clock();
			int received              = AmoebaDivTwo().count( vector <string>( table, table + ( sizeof table / sizeof table[0] ) ), K );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 6: {
			string table[]            = ;
			int K                     = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = AmoebaDivTwo().count( vector <string>( table, table + ( sizeof table / sizeof table[0] ) ), K );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			string table[]            = ;
			int K                     = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = AmoebaDivTwo().count( vector <string>( table, table + ( sizeof table / sizeof table[0] ) ), K );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 8: {
			string table[]            = ;
			int K                     = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = AmoebaDivTwo().count( vector <string>( table, table + ( sizeof table / sizeof table[0] ) ), K );
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
