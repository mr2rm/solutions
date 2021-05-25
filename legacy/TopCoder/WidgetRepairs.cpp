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

class WidgetRepairs {
public:
   int days( vector <int> arrivals, int numPerDay ) 
   {
	   int sum = 0;
	   int day = 0;
	   for ( int i = 0 ; i < arrivals.size() ; i++ )
	   {
		   sum += arrivals[i];
		   if ( sum != 0 )
		   {
			   if ( sum >= numPerDay )
				   sum -= numPerDay;
			   else
				   sum = 0;
			   day++;
		   }
	   }
	   day += ( sum / numPerDay );
	   if ( sum % numPerDay != 0 )
		   day++;
	   return day;
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
			int arrivals[]            = { 10, 0, 0, 4, 20 };
			int numPerDay             = 8;
			int expected              = 6;

			clock_t moj_start_time    = clock();
			int received              = WidgetRepairs().days( vector <int>( arrivals, arrivals + ( sizeof arrivals / sizeof arrivals[0] ) ), numPerDay );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int arrivals[]            = { 0, 0, 0 };
			int numPerDay             = 10;
			int expected              = 0;

			clock_t moj_start_time    = clock();
			int received              = WidgetRepairs().days( vector <int>( arrivals, arrivals + ( sizeof arrivals / sizeof arrivals[0] ) ), numPerDay );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int arrivals[]            = { 100, 100 };
			int numPerDay             = 10;
			int expected              = 20;

			clock_t moj_start_time    = clock();
			int received              = WidgetRepairs().days( vector <int>( arrivals, arrivals + ( sizeof arrivals / sizeof arrivals[0] ) ), numPerDay );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			int arrivals[]            = { 27, 0, 0, 0, 0, 9 };
			int numPerDay             = 9;
			int expected              = 4;

			clock_t moj_start_time    = clock();
			int received              = WidgetRepairs().days( vector <int>( arrivals, arrivals + ( sizeof arrivals / sizeof arrivals[0] ) ), numPerDay );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			int arrivals[]            = { 6, 5, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 5, 6 };
			int numPerDay             = 3;
			int expected              = 15;

			clock_t moj_start_time    = clock();
			int received              = WidgetRepairs().days( vector <int>( arrivals, arrivals + ( sizeof arrivals / sizeof arrivals[0] ) ), numPerDay );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			int arrivals[]            = ;
			int numPerDay             = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = WidgetRepairs().days( vector <int>( arrivals, arrivals + ( sizeof arrivals / sizeof arrivals[0] ) ), numPerDay );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int arrivals[]            = ;
			int numPerDay             = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = WidgetRepairs().days( vector <int>( arrivals, arrivals + ( sizeof arrivals / sizeof arrivals[0] ) ), numPerDay );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			int arrivals[]            = ;
			int numPerDay             = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = WidgetRepairs().days( vector <int>( arrivals, arrivals + ( sizeof arrivals / sizeof arrivals[0] ) ), numPerDay );
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
