#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <string>
#include <complex>

using namespace std;

class Highscore {
   public: int getRank(vector <int> scores, int newscore, int places)
   {
       scores.push_back (newscore);
       sort (scores.begin(), scores.end());
       reverse (scores.begin(), scores.end());
       int sz = scores.size();
       int J;
       for (int I = 0; I < sz && I < places && scores[I] >= newscore; I++)
            if (scores[I] == newscore)
            {
                for (J = I+1; J < sz && scores[J] == scores[I]; J++);
                if (J <= places)
                    return I+1;
                else
                    break;
            }
       return -1;
   };
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
			int scores[]              = {100,90,80};
			int newscore              = 90;
			int places                = 10;
			int expected              = 2;

			clock_t moj_start_time    = clock();
			int received              = Highscore().getRank( vector <int>( scores, scores + ( sizeof scores / sizeof scores[0] ) ), newscore, places );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int scores[]              = {};
			int newscore              = 0;
			int places                = 50;
			int expected              = 1;

			clock_t moj_start_time    = clock();
			int received              = Highscore().getRank( vector <int>( scores, scores + ( sizeof scores / sizeof scores[0] ) ), newscore, places );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int scores[]              = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
			int newscore              = 1;
			int places                = 10;
			int expected              = -1;

			clock_t moj_start_time    = clock();
			int received              = Highscore().getRank( vector <int>( scores, scores + ( sizeof scores / sizeof scores[0] ) ), newscore, places );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			int scores[]              = {10, 9, 8, 7, 6, 5, 4, 3, 3, 0};
			int newscore              = 1;
			int places                = 10;
			int expected              = 10;

			clock_t moj_start_time    = clock();
			int received              = Highscore().getRank( vector <int>( scores, scores + ( sizeof scores / sizeof scores[0] ) ), newscore, places );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			int scores[]              = {2000000000, 19539, 19466, 19146, 17441, 17002, 16348, 16343, 15981, 15346, 14748, 14594, 13752, 13684, 13336, 13290, 12939, 12208, 12163, 12133, 11621, 11119, 10872, 10710, 10390, 9934, 9296, 8844, 8662, 8653, 8168, 7914, 7529, 7354, 6016, 5428, 5302, 5158, 4853, 4538, 4328, 3443, 3222, 2107, 2107, 1337, 951, 586, 424, 31};
			int newscore              = 1337;
			int places                = 50;
			int expected              = 46;

			clock_t moj_start_time    = clock();
			int received              = Highscore().getRank( vector <int>( scores, scores + ( sizeof scores / sizeof scores[0] ) ), newscore, places );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			int scores[]              = ;
			int newscore              = ;
			int places                = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Highscore().getRank( vector <int>( scores, scores + ( sizeof scores / sizeof scores[0] ) ), newscore, places );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int scores[]              = ;
			int newscore              = ;
			int places                = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Highscore().getRank( vector <int>( scores, scores + ( sizeof scores / sizeof scores[0] ) ), newscore, places );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			int scores[]              = ;
			int newscore              = ;
			int places                = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Highscore().getRank( vector <int>( scores, scores + ( sizeof scores / sizeof scores[0] ) ), newscore, places );
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
