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

class ObjectFall {
public:
   int howLong( int x, int y, vector <string> obstacles )
   {
       int sum = y;
       int yo , x1o , x2o;
       sort ( obstacles.begin() , obstacles.end() );
       for ( int i = obstacles.size() - 1 ; i >= 0 ; i-- )
       {
           stringstream ss ( obstacles[i] );
           ss >> yo;    ss >> x1o;  ss >> x2o;
           if ( y >= yo && x >= x1o && x <= x2o )
           {
               sum += 5;
               y = yo;
               x = x2o;
           }
       }
       return sum;
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
			int x                     = 15;
			int y                     = 10;
			string obstacles[]        = {"005 010 020"};
			int expected              = 15;

			clock_t moj_start_time    = clock();
			int received              = ObjectFall().howLong( x, y, vector <string>( obstacles, obstacles + ( sizeof obstacles / sizeof obstacles[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int x                     = 15;
			int y                     = 12;
			string obstacles[]        = {"010 010 020","015 010 020","005 020 050"};
			int expected              = 22;

			clock_t moj_start_time    = clock();
			int received              = ObjectFall().howLong( x, y, vector <string>( obstacles, obstacles + ( sizeof obstacles / sizeof obstacles[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int x                     = 50;
			int y                     = 85;
			string obstacles[]        = {"020 001 100","010 100 100","005 100 200"};
			int expected              = 100;

			clock_t moj_start_time    = clock();
			int received              = ObjectFall().howLong( x, y, vector <string>( obstacles, obstacles + ( sizeof obstacles / sizeof obstacles[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			int x                     = 10;
			int y                     = 1000;
			string obstacles[]        = {};
			int expected              = 1000;

			clock_t moj_start_time    = clock();
			int received              = ObjectFall().howLong( x, y, vector <string>( obstacles, obstacles + ( sizeof obstacles / sizeof obstacles[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			int x                     = 500;
			int y                     = 800;
			string obstacles[]        = {"800 001 500","400 001 499","401 501 999"};
			int expected              = 805;

			clock_t moj_start_time    = clock();
			int received              = ObjectFall().howLong( x, y, vector <string>( obstacles, obstacles + ( sizeof obstacles / sizeof obstacles[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 5: {
			int x                     = 645;
			int y                     = 802;
			string obstacles[]        = {"739 038 799","916 169 791","822 372 911","162 125 992","261 307 545",  "510 031 765","592 723 742","477 315 676","566 143 617","337 114 664",  "986 648 883","116 230 680","254 746 943","742 948 988","060 117 401",  "634 035 433","288 741 864","819 626 730","906 071 222","554 100 121",  "573 051 551","949 528 915","562 151 223","857 135 243","621 115 474",  "588 405 615","895 812 919","052 378 836","858 116 505","285 428 469",  "792 244 250","109 265 637","714 804 885","625 150 410","518 593 921",  "282 235 339","081 212 659","663 047 982","556 194 345","798 150 938",  "391 026 813","886 348 796","975 007 743","053 854 895","243 561 875"};
			int expected              = 817;

			clock_t moj_start_time    = clock();
			int received              = ObjectFall().howLong( x, y, vector <string>( obstacles, obstacles + ( sizeof obstacles / sizeof obstacles[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 6: {
			int x                     = ;
			int y                     = ;
			string obstacles[]        = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = ObjectFall().howLong( x, y, vector <string>( obstacles, obstacles + ( sizeof obstacles / sizeof obstacles[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			int x                     = ;
			int y                     = ;
			string obstacles[]        = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = ObjectFall().howLong( x, y, vector <string>( obstacles, obstacles + ( sizeof obstacles / sizeof obstacles[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 8: {
			int x                     = ;
			int y                     = ;
			string obstacles[]        = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = ObjectFall().howLong( x, y, vector <string>( obstacles, obstacles + ( sizeof obstacles / sizeof obstacles[0] ) ) );
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
