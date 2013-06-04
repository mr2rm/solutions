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

class Reppity {
public:
   int longestRep( string input ) 
   {
	   int Size = input.size();
	   for ( int i = Size / 2 ; i > 0 ; i-- )
	   {
		   int A = Size - i;
		   for ( int j = 0 ; j <= A ; j++ )
		   {
			   string str ( input.begin() + j , input.begin() + j + i );
			   int Sum = 0;
		   for ( int k = 0 ; k <= A ; k++ )
				   if ( !( k >= j && k < j + i ) )
				   {
					   string s ( input.begin() + k , input.begin() + k + i );
					   if ( str == s )	Sum++;
				   }
			   if ( Sum > 1 )	return Sum;
		   }
		   return 0;
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
			string input              = "ABCDEXXXYYYZZZABCDEZZZYYYXXX";
			int expected              = 5;

			clock_t moj_start_time    = clock();
			int received              = Reppity().longestRep( input );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			string input              = "abcdabcdabcdabCD";
			int expected              = 6;

			clock_t moj_start_time    = clock();
			int received              = Reppity().longestRep( input );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			string input              = "abcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxy";
			int expected              = 25;

			clock_t moj_start_time    = clock();
			int received              = Reppity().longestRep( input );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			string input              = "againANDagainANDagainANDagainANDagainANDagain";
			int expected              = 21;

			clock_t moj_start_time    = clock();
			int received              = Reppity().longestRep( input );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			string input              = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWX";
			int expected              = 0;

			clock_t moj_start_time    = clock();
			int received              = Reppity().longestRep( input );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			string input              = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Reppity().longestRep( input );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			string input              = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Reppity().longestRep( input );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			string input              = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Reppity().longestRep( input );
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
