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

class Aquarium {
public:
   int peaceful( int minSize, int maxSize, vector <int> fishSizes ) 
   {
	   double t1 , t2;
	   bool b;
	   int Res = 0;
	   for ( int i = minSize ; i <= maxSize ; i++ )
	   {
		   b = true;
		   for ( int j = 0 ; j < fishSizes.size() ; j++ )
		   {
			   t1 = (double)i / fishSizes[j];
			   t2 = 1. / t1;
			   if ( ( ( t1 >= 2 && t1 <= 10 ) || ( t2 >= 2 && t2 <= 10 ) ) )
			   {
				   b = false;
				   break;
			   }
		   }
		   if ( b )
			   Res++;
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
			int minSize               = 1;
			int maxSize               = 12;
			int fishSizes[]           = {1};
			int expected              = 3;

			clock_t moj_start_time    = clock();
			int received              = Aquarium().peaceful( minSize, maxSize, vector <int>( fishSizes, fishSizes + ( sizeof fishSizes / sizeof fishSizes[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int minSize               = 1;
			int maxSize               = 36;
			int fishSizes[]           = {3};
			int expected              = 10;

			clock_t moj_start_time    = clock();
			int received              = Aquarium().peaceful( minSize, maxSize, vector <int>( fishSizes, fishSizes + ( sizeof fishSizes / sizeof fishSizes[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int minSize               = 1;
			int maxSize               = 1000;
			int fishSizes[]           = {10, 100, 500};
			int expected              = 4;

			clock_t moj_start_time    = clock();
			int received              = Aquarium().peaceful( minSize, maxSize, vector <int>( fishSizes, fishSizes + ( sizeof fishSizes / sizeof fishSizes[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			int minSize               = 5;
			int maxSize               = 880;
			int fishSizes[]           = {1, 3, 9, 27, 243, 729};
			int expected              = 121;

			clock_t moj_start_time    = clock();
			int received              = Aquarium().peaceful( minSize, maxSize, vector <int>( fishSizes, fishSizes + ( sizeof fishSizes / sizeof fishSizes[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			int minSize               = 3;
			int maxSize               = 997;
			int fishSizes[]           = {10, 11, 12, 13, 14, 16, 82, 83, 84, 85, 720, 730, 740, 750, 760, 770};
			int expected              = 147;

			clock_t moj_start_time    = clock();
			int received              = Aquarium().peaceful( minSize, maxSize, vector <int>( fishSizes, fishSizes + ( sizeof fishSizes / sizeof fishSizes[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 5: {
			int minSize               = 2;
			int maxSize               = 999;
			int fishSizes[]           = {941, 797, 120, 45, 7, 120};
			int expected              = 10;

			clock_t moj_start_time    = clock();
			int received              = Aquarium().peaceful( minSize, maxSize, vector <int>( fishSizes, fishSizes + ( sizeof fishSizes / sizeof fishSizes[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 6: {
			int minSize               = 1;
			int maxSize               = 791;
			int fishSizes[]           = {1, 4, 12, 25, 79, 556, 625, 800, 801, 950, 952, 954, 956, 958, 980, 1000};
			int expected              = 1;

			clock_t moj_start_time    = clock();
			int received              = Aquarium().peaceful( minSize, maxSize, vector <int>( fishSizes, fishSizes + ( sizeof fishSizes / sizeof fishSizes[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 7: {
			int minSize               = ;
			int maxSize               = ;
			int fishSizes[]           = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Aquarium().peaceful( minSize, maxSize, vector <int>( fishSizes, fishSizes + ( sizeof fishSizes / sizeof fishSizes[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 8: {
			int minSize               = ;
			int maxSize               = ;
			int fishSizes[]           = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Aquarium().peaceful( minSize, maxSize, vector <int>( fishSizes, fishSizes + ( sizeof fishSizes / sizeof fishSizes[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 9: {
			int minSize               = ;
			int maxSize               = ;
			int fishSizes[]           = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Aquarium().peaceful( minSize, maxSize, vector <int>( fishSizes, fishSizes + ( sizeof fishSizes / sizeof fishSizes[0] ) ) );
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
