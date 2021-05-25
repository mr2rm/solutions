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

class Cryptography {
public:
   long long encrypt( vector <int> numbers ) 
   {
	   long long Maxi = 1;

	   /*long long Sum;
	   for ( int i = 0 ; i < numbers.size() ; i++ )
	   {
		   Sum = 1;
		   for ( int j = 0 ; j < numbers.size() ; j++ )
			   if ( j == i )
				   Sum *= ( numbers[j] + 1 );
			   else
				   Sum *= numbers[j];
		   Maxi = max ( Maxi , Sum );
	   }*/
	   
	   /*int MinIndex = 0;
	   for ( int i = 0 ; i < numbers.size() ; i++ )
		   if ( numbers[i] < numbers[MinIndex] )
			   MinIndex = i;
	   numbers[MinIndex]++;
	   for ( int i = 0 ; i < numbers.size() ; i++ )
		   Maxi *= numbers[i];*/

	   return Maxi;
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
	
	int verify_case( int casenum, const long long &expected, const long long &received, clock_t elapsed ) { 
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
			int numbers[]             = {1,2,3};
			long long expected        = 12LL;

			clock_t moj_start_time    = clock();
			long long received        = Cryptography().encrypt( vector <int>( numbers, numbers + ( sizeof numbers / sizeof numbers[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int numbers[]             = {1,3,2,1,1,3};
			long long expected        = 36LL;

			clock_t moj_start_time    = clock();
			long long received        = Cryptography().encrypt( vector <int>( numbers, numbers + ( sizeof numbers / sizeof numbers[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int numbers[]             = {1000,999,998,997,996,995};
			long long expected        = 986074810223904000LL;

			clock_t moj_start_time    = clock();
			long long received        = Cryptography().encrypt( vector <int>( numbers, numbers + ( sizeof numbers / sizeof numbers[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			int numbers[]             = {1,1,1,1};
			long long expected        = 2LL;

			clock_t moj_start_time    = clock();
			long long received        = Cryptography().encrypt( vector <int>( numbers, numbers + ( sizeof numbers / sizeof numbers[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 4: {
			int numbers[]             = ;
			long long expected        = LL;

			clock_t moj_start_time    = clock();
			long long received        = Cryptography().encrypt( vector <int>( numbers, numbers + ( sizeof numbers / sizeof numbers[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 5: {
			int numbers[]             = ;
			long long expected        = LL;

			clock_t moj_start_time    = clock();
			long long received        = Cryptography().encrypt( vector <int>( numbers, numbers + ( sizeof numbers / sizeof numbers[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int numbers[]             = ;
			long long expected        = LL;

			clock_t moj_start_time    = clock();
			long long received        = Cryptography().encrypt( vector <int>( numbers, numbers + ( sizeof numbers / sizeof numbers[0] ) ) );
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
