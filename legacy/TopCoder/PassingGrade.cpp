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

class PassingGrade {
public:
   int pointsNeeded( vector <int> pointsEarned, vector <int> pointsPossible, int finalExam ) 
   {
	   /*
	   int sum = finalExam;
	   for ( int i = 0 ; i < pointsPossible.size() ; i++ )
		   sum += pointsPossible[i];
	   sum = ceil ( (double) sum * 0.65 );
	   for ( int i = 0 ; i < pointsEarned.size() ; i++ )
		   sum -= pointsEarned[i];
	   if ( sum < 0 )
		   return 0;
	   if ( sum > finalExam )
		   return -1;
	   return sum;
	   */
	   /*
	   int have , possible;
	   have = possible = 0;
	   for ( int i = 0 ; i < pointsEarned.size() ; i++ )
	   {
		   have += pointsEarned[i];
		   possible += pointsPossible[i];
	   }
	   possible += finalExam;
	   for ( int i = 0 ; i <= finalExam ; i++ )
		   if ( ( have + i ) * 100 / possible >= 65 )
			   return i;
	   return -1;
	   */
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
			int pointsEarned[]        = {55,77,82,60};
			int pointsPossible[]      = {100,100,100,100};
			int finalExam             = 300;
			int expected              = 181;

			clock_t moj_start_time    = clock();
			int received              = PassingGrade().pointsNeeded( vector <int>( pointsEarned, pointsEarned + ( sizeof pointsEarned / sizeof pointsEarned[0] ) ), vector <int>( pointsPossible, pointsPossible + ( sizeof pointsPossible / sizeof pointsPossible[0] ) ), finalExam );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int pointsEarned[]        = { 1, 2, 3, 4 };
			int pointsPossible[]      = { 2, 3, 4, 5 };
			int finalExam             = 7;
			int expected              = 4;

			clock_t moj_start_time    = clock();
			int received              = PassingGrade().pointsNeeded( vector <int>( pointsEarned, pointsEarned + ( sizeof pointsEarned / sizeof pointsEarned[0] ) ), vector <int>( pointsPossible, pointsPossible + ( sizeof pointsPossible / sizeof pointsPossible[0] ) ), finalExam );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int pointsEarned[]        = { 1, 2, 2, 1 };
			int pointsPossible[]      = { 9, 9, 9, 9 };
			int finalExam             = 9;
			int expected              = -1;

			clock_t moj_start_time    = clock();
			int received              = PassingGrade().pointsNeeded( vector <int>( pointsEarned, pointsEarned + ( sizeof pointsEarned / sizeof pointsEarned[0] ) ), vector <int>( pointsPossible, pointsPossible + ( sizeof pointsPossible / sizeof pointsPossible[0] ) ), finalExam );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			int pointsEarned[]        = { 7, 8, 7, 6 };
			int pointsPossible[]      = { 8, 8, 8, 8 };
			int finalExam             = 9;
			int expected              = 0;

			clock_t moj_start_time    = clock();
			int received              = PassingGrade().pointsNeeded( vector <int>( pointsEarned, pointsEarned + ( sizeof pointsEarned / sizeof pointsEarned[0] ) ), vector <int>( pointsPossible, pointsPossible + ( sizeof pointsPossible / sizeof pointsPossible[0] ) ), finalExam );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			int pointsEarned[]        = { 17, 23, 50, 200, 19, 56, 83, 91, 77, 9, 0 };
			int pointsPossible[]      = { 20, 30, 50, 250, 20, 70, 100, 100, 100, 10, 10 };
			int finalExam             = 400;
			int expected              = 129;

			clock_t moj_start_time    = clock();
			int received              = PassingGrade().pointsNeeded( vector <int>( pointsEarned, pointsEarned + ( sizeof pointsEarned / sizeof pointsEarned[0] ) ), vector <int>( pointsPossible, pointsPossible + ( sizeof pointsPossible / sizeof pointsPossible[0] ) ), finalExam );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 5: {
			int pointsEarned[]        = {600,600,600,600,600,600,600,600,600,600,  600,600,600,600,600,600,600,600,600,600};
			int pointsPossible[]      = {1000,1000,1000,1000,1000,1000,1000,1000,  1000,1000,1000,1000,1000,1000,1000,1000,  1000,1000,1000,901};
			int finalExam             = 3000;
			int expected              = 2886;

			clock_t moj_start_time    = clock();
			int received              = PassingGrade().pointsNeeded( vector <int>( pointsEarned, pointsEarned + ( sizeof pointsEarned / sizeof pointsEarned[0] ) ), vector <int>( pointsPossible, pointsPossible + ( sizeof pointsPossible / sizeof pointsPossible[0] ) ), finalExam );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 6: {
			int pointsEarned[]        = ;
			int pointsPossible[]      = ;
			int finalExam             = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = PassingGrade().pointsNeeded( vector <int>( pointsEarned, pointsEarned + ( sizeof pointsEarned / sizeof pointsEarned[0] ) ), vector <int>( pointsPossible, pointsPossible + ( sizeof pointsPossible / sizeof pointsPossible[0] ) ), finalExam );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			int pointsEarned[]        = ;
			int pointsPossible[]      = ;
			int finalExam             = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = PassingGrade().pointsNeeded( vector <int>( pointsEarned, pointsEarned + ( sizeof pointsEarned / sizeof pointsEarned[0] ) ), vector <int>( pointsPossible, pointsPossible + ( sizeof pointsPossible / sizeof pointsPossible[0] ) ), finalExam );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 8: {
			int pointsEarned[]        = ;
			int pointsPossible[]      = ;
			int finalExam             = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = PassingGrade().pointsNeeded( vector <int>( pointsEarned, pointsEarned + ( sizeof pointsEarned / sizeof pointsEarned[0] ) ), vector <int>( pointsPossible, pointsPossible + ( sizeof pointsPossible / sizeof pointsPossible[0] ) ), finalExam );
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
