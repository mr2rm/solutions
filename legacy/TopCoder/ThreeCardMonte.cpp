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

class ThreeCardMonte {
public:
   string position( string swaps ) 
   {
	   int p[3] = { 0 , 1 , 0 };
	   for ( int i = 0 ; i < swaps.length() ; i++ )
		   switch ( swaps[i] )
		   {
		   case 'L':
			   swap ( p[0] , p[1] );
			   break;
		   case 'R':
			   swap ( p[1] , p[2] );
			   break;
		   case 'E':
			   swap ( p[0] , p[2] );
			   break;
		   }
	   for ( int i = 0 ; i < 3 ; i++ )
		   if ( p[i] == 1 )
			   switch ( i )
			   {
			   case 0:	return "L";
			   case 1:	return "M";
			   default:	return "R";
			   }
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
			string swaps              = "L";
			string expected           = "L";

			clock_t moj_start_time    = clock();
			string received           = ThreeCardMonte().position( swaps );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			string swaps              = "REL";
			string expected           = "M";

			clock_t moj_start_time    = clock();
			string received           = ThreeCardMonte().position( swaps );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			string swaps              = "RFRFR";
			string expected           = "R";

			clock_t moj_start_time    = clock();
			string received           = ThreeCardMonte().position( swaps );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			string swaps              = "";
			string expected           = "M";

			clock_t moj_start_time    = clock();
			string received           = ThreeCardMonte().position( swaps );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			string swaps              = "FLRELFLRELLFRLFEELFLRFLELRFLRFREFRFLLRFERLFLREFRFL";
			string expected           = "L";

			clock_t moj_start_time    = clock();
			string received           = ThreeCardMonte().position( swaps );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			string swaps              = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = ThreeCardMonte().position( swaps );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			string swaps              = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = ThreeCardMonte().position( swaps );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			string swaps              = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = ThreeCardMonte().position( swaps );
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
