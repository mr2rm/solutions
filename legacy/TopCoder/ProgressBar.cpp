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

class ProgressBar {
public:
   string showProgress( vector <int> taskTimes, int tasksCompleted ) 
   {
	   int whole , sum = 0 , index;
	   for ( index = 0 ; index < tasksCompleted ; index++ )
		   sum += taskTimes[index];
	   whole = sum;
	   for ( ; index < taskTimes.size() ; index++ )
		   whole += taskTimes[index];
	   double ANS;
	   ANS = (double) sum * 20 / whole;
	   string MANS ( 20 , '#');
	   for ( int i = ANS ; i < 20 ; i++ )
		   MANS[i] = '.';
	   return MANS;
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
		case 0: {
			int taskTimes[]           = {19,6,23,17};
			int tasksCompleted        = 3;
			string expected           = "##############......";

			clock_t moj_start_time    = clock();
			string received           = ProgressBar().showProgress( vector <int>( taskTimes, taskTimes + ( sizeof taskTimes / sizeof taskTimes[0] ) ), tasksCompleted );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int taskTimes[]           = {2,3,7,1,4,3};
			int tasksCompleted        = 4;
			string expected           = "#############.......";

			clock_t moj_start_time    = clock();
			string received           = ProgressBar().showProgress( vector <int>( taskTimes, taskTimes + ( sizeof taskTimes / sizeof taskTimes[0] ) ), tasksCompleted );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int taskTimes[]           = {553,846,816,203,101,120,161,818,315,772};
			int tasksCompleted        = 4;
			string expected           = "##########..........";

			clock_t moj_start_time    = clock();
			string received           = ProgressBar().showProgress( vector <int>( taskTimes, taskTimes + ( sizeof taskTimes / sizeof taskTimes[0] ) ), tasksCompleted );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			int taskTimes[]           = {7,60,468,489,707,499,350,998,1000,716,457,104,597,583,396,862};
			int tasksCompleted        = 2;
			string expected           = "....................";

			clock_t moj_start_time    = clock();
			string received           = ProgressBar().showProgress( vector <int>( taskTimes, taskTimes + ( sizeof taskTimes / sizeof taskTimes[0] ) ), tasksCompleted );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			int taskTimes[]           = {419,337,853,513,632,861,336,594,94,367,336,297,966,627,399,433,846,859,80,2};
			int tasksCompleted        = 19;
			string expected           = "###################.";

			clock_t moj_start_time    = clock();
			string received           = ProgressBar().showProgress( vector <int>( taskTimes, taskTimes + ( sizeof taskTimes / sizeof taskTimes[0] ) ), tasksCompleted );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			int taskTimes[]           = ;
			int tasksCompleted        = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = ProgressBar().showProgress( vector <int>( taskTimes, taskTimes + ( sizeof taskTimes / sizeof taskTimes[0] ) ), tasksCompleted );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int taskTimes[]           = ;
			int tasksCompleted        = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = ProgressBar().showProgress( vector <int>( taskTimes, taskTimes + ( sizeof taskTimes / sizeof taskTimes[0] ) ), tasksCompleted );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			int taskTimes[]           = ;
			int tasksCompleted        = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = ProgressBar().showProgress( vector <int>( taskTimes, taskTimes + ( sizeof taskTimes / sizeof taskTimes[0] ) ), tasksCompleted );
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
