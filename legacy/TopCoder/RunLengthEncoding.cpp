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

class RunLengthEncoding {
public:
   string decode( string text )
   {
       string Res;
       int Sum = 0;
       string number;
       int temp;
       for ( int i = 0 ; i < text.length() ; i++ )
       {
           if ( text[i] >= '0' && text[i] <= '9' )
           {
               number += string ( 1 , text[i] );
               if ( number.length() > 2 )   return "TOO LONG";
           }
           else
           {
               if ( number.length() == 0 )  temp = 1;
               else
               {
                   stringstream ss ( number );
                   ss >> temp;
               }
               Sum += temp;
               if ( Sum > 50 ) return "TOO LONG";
               Res += string ( temp , text[i] );
               number = "";
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
		case 4: {
			string text               = "4A3BC2DE";
			string expected           = "AAAABBBCDDE";

			clock_t moj_start_time    = clock();
			string received           = RunLengthEncoding().decode( text );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			string text               = "1A1B1C1D1E";
			string expected           = "ABCDE";

			clock_t moj_start_time    = clock();
			string received           = RunLengthEncoding().decode( text );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			string text               = "1A3A5A4BCCCC";
			string expected           = "AAAAAAAAABBBBCCCC";

			clock_t moj_start_time    = clock();
			string received           = RunLengthEncoding().decode( text );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			string text               = "50A";
			string expected           = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";

			clock_t moj_start_time    = clock();
			string received           = RunLengthEncoding().decode( text );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 0: {
			string text               = "21Z13S9A8M";
			string expected           = "TOO LONG";

			clock_t moj_start_time    = clock();
			string received           = RunLengthEncoding().decode( text );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 5: {
			string text               = "123456789012345678901234567890B";
			string expected           = "TOO LONG";

			clock_t moj_start_time    = clock();
			string received           = RunLengthEncoding().decode( text );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 6: {
			string text               = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = RunLengthEncoding().decode( text );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			string text               = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = RunLengthEncoding().decode( text );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 8: {
			string text               = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = RunLengthEncoding().decode( text );
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
