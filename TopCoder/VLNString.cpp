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

class VLNString {
public:
   string makeAcronym( string longName ) 
   {
	   stringstream ss ( longName );
	   string str;
	   string Res ( "" );
	   while ( ss >> str )
		   if ( str != "of" && str != "and" && str != "the" )
			   Res += ( str[0] - 32 );
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
			string longName           = "dance dance revolution";
			string expected           = "DDR";

			clock_t moj_start_time    = clock();
			string received           = VLNString().makeAcronym( longName );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			string longName           = "  return  of  the king   ";
			string expected           = "RK";

			clock_t moj_start_time    = clock();
			string received           = VLNString().makeAcronym( longName );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			string longName           = "the united states of america";
			string expected           = "USA";

			clock_t moj_start_time    = clock();
			string received           = VLNString().makeAcronym( longName );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			string longName           = " of  the   and    ";
			string expected           = "";

			clock_t moj_start_time    = clock();
			string received           = VLNString().makeAcronym( longName );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			string longName           = " ";
			string expected           = "";

			clock_t moj_start_time    = clock();
			string received           = VLNString().makeAcronym( longName );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			string longName           = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = VLNString().makeAcronym( longName );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			string longName           = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = VLNString().makeAcronym( longName );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			string longName           = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = VLNString().makeAcronym( longName );
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
