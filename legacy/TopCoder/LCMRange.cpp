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

class LCMRange {
public:
   int lcm( int first, int last ) 
   {
	   int LCM[12];
	   memset ( LCM , 0 , sizeof ( LCM ) );
	   int arr[12];
	   int primes[5] = { 2 , 3 , 5 , 7 , 11 };
	   for ( ; first <= last ; first++ )
	   {
		   memset ( arr , 0 , sizeof ( arr ) );
		   for ( int i = 0 , x = first ; x != 1 ; i++ )
		   {
			   while ( x % primes[i] == 0 )
			   {
				   x /= primes[i];
				   arr[ primes[i] ]++;
			   }
			   LCM[ primes[i] ] = max ( LCM[ primes[i] ] , arr[ primes[i] ] );
		   }
	   }
	   int ANS = 1;
	   for ( int i = 0 ; i < 12 ; i++ )
		   if ( LCM[i] != 0 )
			   ANS *= pow ( (double) i , LCM[i] );
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
			int first                 = 1;
			int last                  = 5;
			int expected              = 60;

			clock_t moj_start_time    = clock();
			int received              = LCMRange().lcm( first, last );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int first                 = 4;
			int last                  = 5;
			int expected              = 20;

			clock_t moj_start_time    = clock();
			int received              = LCMRange().lcm( first, last );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int first                 = 1;
			int last                  = 12;
			int expected              = 27720;

			clock_t moj_start_time    = clock();
			int received              = LCMRange().lcm( first, last );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 3: {
			int first                 = ;
			int last                  = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = LCMRange().lcm( first, last );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 4: {
			int first                 = ;
			int last                  = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = LCMRange().lcm( first, last );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 5: {
			int first                 = ;
			int last                  = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = LCMRange().lcm( first, last );
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
