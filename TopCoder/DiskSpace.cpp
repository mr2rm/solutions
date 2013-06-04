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

class DiskSpace {
public:
   int minDrives( vector <int> used, vector <int> total )
   {   
	   int ANS = 0 , use = 0;
	   sort ( total.begin() , total.end() );
	   reverse ( total.begin() , total.end() );
	   for ( int i = 0 ; i < used.size() ; i++ )
		   use += used[i];
	   for ( int i = 0 ; i < total.size() && use > 0 ; i++ )
	   {
		   use -= total[i];
		   ANS++;
	   }
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
			int used[]                = {300,525,110};
			int total[]               = {350,600,115};
			int expected              = 2;

			clock_t moj_start_time    = clock();
			int received              = DiskSpace().minDrives( vector <int>( used, used + ( sizeof used / sizeof used[0] ) ), vector <int>( total, total + ( sizeof total / sizeof total[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int used[]                = {1,200,200,199,200,200};
			int total[]               = {1000,200,200,200,200,200};
			int expected              = 1;

			clock_t moj_start_time    = clock();
			int received              = DiskSpace().minDrives( vector <int>( used, used + ( sizeof used / sizeof used[0] ) ), vector <int>( total, total + ( sizeof total / sizeof total[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int used[]                = {750,800,850,900,950};
			int total[]               = {800,850,900,950,1000};
			int expected              = 5;

			clock_t moj_start_time    = clock();
			int received              = DiskSpace().minDrives( vector <int>( used, used + ( sizeof used / sizeof used[0] ) ), vector <int>( total, total + ( sizeof total / sizeof total[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			int used[]                = {49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,  49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49};
			int total[]               = {50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,  50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50};
			int expected              = 49;

			clock_t moj_start_time    = clock();
			int received              = DiskSpace().minDrives( vector <int>( used, used + ( sizeof used / sizeof used[0] ) ), vector <int>( total, total + ( sizeof total / sizeof total[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			int used[]                = {331,242,384,366,428,114,145,89,381,170,329,190,482,246,2,38,220,290,402,385};
			int total[]               = {992,509,997,946,976,873,771,565,693,714,755,878,897,789,969,727,765,521,961,906};
			int expected              = 6;

			clock_t moj_start_time    = clock();
			int received              = DiskSpace().minDrives( vector <int>( used, used + ( sizeof used / sizeof used[0] ) ), vector <int>( total, total + ( sizeof total / sizeof total[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			int used[]                = ;
			int total[]               = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = DiskSpace().minDrives( vector <int>( used, used + ( sizeof used / sizeof used[0] ) ), vector <int>( total, total + ( sizeof total / sizeof total[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int used[]                = ;
			int total[]               = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = DiskSpace().minDrives( vector <int>( used, used + ( sizeof used / sizeof used[0] ) ), vector <int>( total, total + ( sizeof total / sizeof total[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			int used[]                = ;
			int total[]               = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = DiskSpace().minDrives( vector <int>( used, used + ( sizeof used / sizeof used[0] ) ), vector <int>( total, total + ( sizeof total / sizeof total[0] ) ) );
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
