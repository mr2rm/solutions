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

class bloggoShortcuts {
public:
   string expand( string text ) 
   {
	   vector <string> s ( 4 );
	   string Result;
	   s[0] = "<i>";	s[1] = "</i>";
	   s[2] = "<b>";	s[3] = "</b>";
	   bool b1 , b2;
	   b1 = b2 = true;
	   for ( int i = 0 ; i < text.length() ; i++ )
	   {
		   if ( text[i] == '_' )
		   {
			   ( b1 ? Result += s[0] : Result += s[1] );
			   b1 = !b1;
			   continue;
		   }
		   if ( text[i] == '*' )
		   {
			   ( b2 ? Result += s[2] : Result += s[3] );
			   b2 = !b2;
			   continue;
		   }
		   Result.push_back ( text[i] );
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
			string text               = "You _should_ see the new walrus at the zoo!";
			string expected           = "You <i>should</i> see the new walrus at the zoo!";

			clock_t moj_start_time    = clock();
			string received           = bloggoShortcuts().expand( text );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			string text               = "Move it from *Accounts Payable* to *Receiving*.";
			string expected           = "Move it from <b>Accounts Payable</b> to <b>Receiving</b>.";

			clock_t moj_start_time    = clock();
			string received           = bloggoShortcuts().expand( text );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			string text               = "I saw _Chelydra serpentina_ in *Centennial Park*.";
			string expected           = "I saw <i>Chelydra serpentina</i> in <b>Centennial Park</b>.";

			clock_t moj_start_time    = clock();
			string received           = bloggoShortcuts().expand( text );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			string text               = " _ _ __  _ yabba dabba _   *  dooooo  * ****";
			string expected           = " <i> </i> <i></i>  <i> yabba dabba </i>   <b>  dooooo  </b> <b></b><b></b>";

			clock_t moj_start_time    = clock();
			string received           = bloggoShortcuts().expand( text );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			string text               = "_now_I_know_*my*_ABC_next_time_*sing*it_with_me";
			string expected           = "<i>now</i>I<i>know</i><b>my</b><i>ABC</i>next<i>time</i><b>sing</b>it<i>with</i>me";

			clock_t moj_start_time    = clock();
			string received           = bloggoShortcuts().expand( text );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			string text               = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = bloggoShortcuts().expand( text );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			string text               = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = bloggoShortcuts().expand( text );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			string text               = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = bloggoShortcuts().expand( text );
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
