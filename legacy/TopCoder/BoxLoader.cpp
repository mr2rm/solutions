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

class BoxLoader {
public:
   int mostItems( int boxX, int boxY, int boxZ, int itemX, int itemY, int itemZ ) 
   {
	   int item[3] = { itemX , itemY , itemZ };
	   int Result = 0 , temp;
	   for ( int i = 0 ; i < 3 ; i++ )
		   for ( int j = 0 ; j < 3 ; j++ )
			   for ( int k = 0 ; k < 3 ; k++ )
				   if ( i != j && j != k && i != k )
					   {
						   temp = ( boxX / item[i] ) * ( boxY / item[j] ) * ( boxZ / item[k] ); 
						   Result = max ( temp , Result );
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
			int boxX                  = 100;
			int boxY                  = 98;
			int boxZ                  = 81;
			int itemX                 = 3;
			int itemY                 = 5;
			int itemZ                 = 7;
			int expected              = 7560;

			clock_t moj_start_time    = clock();
			int received              = BoxLoader().mostItems( boxX, boxY, boxZ, itemX, itemY, itemZ );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int boxX                  = 10;
			int boxY                  = 10;
			int boxZ                  = 10;
			int itemX                 = 9;
			int itemY                 = 9;
			int itemZ                 = 11;
			int expected              = 0;

			clock_t moj_start_time    = clock();
			int received              = BoxLoader().mostItems( boxX, boxY, boxZ, itemX, itemY, itemZ );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int boxX                  = 201;
			int boxY                  = 101;
			int boxZ                  = 301;
			int itemX                 = 100;
			int itemY                 = 30;
			int itemZ                 = 20;
			int expected              = 100;

			clock_t moj_start_time    = clock();
			int received              = BoxLoader().mostItems( boxX, boxY, boxZ, itemX, itemY, itemZ );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			int boxX                  = 913;
			int boxY                  = 687;
			int boxZ                  = 783;
			int itemX                 = 109;
			int itemY                 = 93;
			int itemZ                 = 53;
			int expected              = 833;

			clock_t moj_start_time    = clock();
			int received              = BoxLoader().mostItems( boxX, boxY, boxZ, itemX, itemY, itemZ );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			int boxX                  = 6;
			int boxY                  = 5;
			int boxZ                  = 4;
			int itemX                 = 3;
			int itemY                 = 2;
			int itemZ                 = 1;
			int expected              = 20;

			clock_t moj_start_time    = clock();
			int received              = BoxLoader().mostItems( boxX, boxY, boxZ, itemX, itemY, itemZ );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			int boxX                  = ;
			int boxY                  = ;
			int boxZ                  = ;
			int itemX                 = ;
			int itemY                 = ;
			int itemZ                 = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = BoxLoader().mostItems( boxX, boxY, boxZ, itemX, itemY, itemZ );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int boxX                  = ;
			int boxY                  = ;
			int boxZ                  = ;
			int itemX                 = ;
			int itemY                 = ;
			int itemZ                 = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = BoxLoader().mostItems( boxX, boxY, boxZ, itemX, itemY, itemZ );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			int boxX                  = ;
			int boxY                  = ;
			int boxZ                  = ;
			int itemX                 = ;
			int itemY                 = ;
			int itemZ                 = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = BoxLoader().mostItems( boxX, boxY, boxZ, itemX, itemY, itemZ );
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
