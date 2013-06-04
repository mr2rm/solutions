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

class PrefixCode {
public:
   string isOne( vector <string> words ) 
   {
	   int index;
	   string ANS , str , s;
	   for ( index = 0 ; index < words.size() ; index++ )
		   for ( int i = 0 ; i < words.size() ; i++ )
			   if ( index != i && words[index].length() <= words[i].length() )
			   {
				   bool b = true;
				   for ( int j = 0 ; j < words[index].length() ; j++ )
					   if ( words[index][j] != words[i][j] )
					   {
						   b = false;
						   break;
					   }
				   if ( b == true )
				   {
					   ANS = "No, ";
					   stringstream ss ( str );
					   ss << index;
					   ss >> s;
					   ANS = ANS + s;
					   return ANS;
				   }
			   }
	   ANS = "Yes";
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
			string words[]            = {"trivial"};
			string expected           = "Yes";

			clock_t moj_start_time    = clock();
			string received           = PrefixCode().isOne( vector <string>( words, words + ( sizeof words / sizeof words[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			string words[]            = {"10001", "011", "100", "001", "10"};
			string expected           = "No, 2";

			clock_t moj_start_time    = clock();
			string received           = PrefixCode().isOne( vector <string>( words, words + ( sizeof words / sizeof words[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			string words[]            = {"no", "nosy", "neighbors", "needed"};
			string expected           = "No, 0";

			clock_t moj_start_time    = clock();
			string received           = PrefixCode().isOne( vector <string>( words, words + ( sizeof words / sizeof words[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			string words[]            = {"1010", "11", "100", "0", "1011"};
			string expected           = "Yes";

			clock_t moj_start_time    = clock();
			string received           = PrefixCode().isOne( vector <string>( words, words + ( sizeof words / sizeof words[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			string words[]            = {"No", "not"};
			string expected           = "Yes";

			clock_t moj_start_time    = clock();
			string received           = PrefixCode().isOne( vector <string>( words, words + ( sizeof words / sizeof words[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			string words[]            = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = PrefixCode().isOne( vector <string>( words, words + ( sizeof words / sizeof words[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			string words[]            = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = PrefixCode().isOne( vector <string>( words, words + ( sizeof words / sizeof words[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			string words[]            = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = PrefixCode().isOne( vector <string>( words, words + ( sizeof words / sizeof words[0] ) ) );
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
