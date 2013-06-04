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

class IndicatorMotion {
public:
   string getMotion( string program, char startState ) 
   {
	   char c[4] = { '|' , '/' , '-' , '\\' };
	   string Res ( 1 , startState );
	   int start;
	   for ( int i = 0 ; i < 4 ; i++ )
	   {
		   if ( startState == c[i] )
		   {
			   start = i;
			   break;
		   }
	   }
	   for ( int i = 0 ; i < program.length() ; i += 3 )
	   {
		   int step = 0;
		   switch ( program[i] )
		   {
		   case 'L':
			   step = -1;
			   break;
		   case 'R':
			   step = +1;
			   break;
		   case 'F':
			   step = +2;
			   break;
		   }
		   int sec = ( program[i+1] - '0' ) * 10 + ( program[i+2] - '0' );
		   for ( int j = 1 ; j <= sec ; j++ )
		   {
			   start += step;
			   start = start < 0 ? 3 : start % 4;
			   Res += c[start];
		   }
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
			string program            = "F03L02R03S02F04";
			char startState           = '-';
			string expected           = "-|-|\\-\\|///\\/\\/";

			clock_t moj_start_time    = clock();
			string received           = IndicatorMotion().getMotion( program, startState );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			string program            = "F10R01F10";
			char startState           = '/';
			string expected           = "/\\/\\/\\/\\/\\/-|-|-|-|-|-";

			clock_t moj_start_time    = clock();
			string received           = IndicatorMotion().getMotion( program, startState );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			string program            = "";
			char startState           = '/';
			string expected           = "/";

			clock_t moj_start_time    = clock();
			string received           = IndicatorMotion().getMotion( program, startState );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			string program            = "F00R00L00S00";
			char startState           = '\\';
			string expected           = "\\";

			clock_t moj_start_time    = clock();
			string received           = IndicatorMotion().getMotion( program, startState );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 4: {
			string program            = ;
			char startState           = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = IndicatorMotion().getMotion( program, startState );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 5: {
			string program            = ;
			char startState           = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = IndicatorMotion().getMotion( program, startState );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			string program            = ;
			char startState           = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = IndicatorMotion().getMotion( program, startState );
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
