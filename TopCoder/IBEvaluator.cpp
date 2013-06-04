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

class IBEvaluator {
public:
   vector <int> getSummary( vector <int> predictedGrades, vector <int> actualGrades ) 
   {
	   vector <int> ANS ( 7 , 0 );
	   int Numbers = actualGrades.size();
	   for ( int i = 0 ; i < Numbers ; i++ )
		   ANS[ fabs ( (double) predictedGrades[i] - actualGrades[i] ) ]++;
	   for ( int i = 0 ; i < 7 ; i++ )
		   if ( ANS[i] != 0 )
			   ANS[i] = (double) ( ANS[i] * 100 ) / Numbers;
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
	
	template<typename T> ostream& operator<<( ostream &os, const vector<T> &v ) { os << "{"; for ( typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case( int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed ) { 
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
			int predictedGrades[]     = {1,5,7,3};
			int actualGrades[]        = {3,5,4,5};
			int expected[]            = { 25,  0,  50,  25,  0,  0,  0 };

			clock_t moj_start_time    = clock();
			vector <int> received     = IBEvaluator().getSummary( vector <int>( predictedGrades, predictedGrades + ( sizeof predictedGrades / sizeof predictedGrades[0] ) ), vector <int>( actualGrades, actualGrades + ( sizeof actualGrades / sizeof actualGrades[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 1: {
			int predictedGrades[]     = {1,1,1};
			int actualGrades[]        = {5,6,7};
			int expected[]            = { 0,  0,  0,  0,  33,  33,  33 };

			clock_t moj_start_time    = clock();
			vector <int> received     = IBEvaluator().getSummary( vector <int>( predictedGrades, predictedGrades + ( sizeof predictedGrades / sizeof predictedGrades[0] ) ), vector <int>( actualGrades, actualGrades + ( sizeof actualGrades / sizeof actualGrades[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 2: {
			int predictedGrades[]     = {3};
			int actualGrades[]        = {3};
			int expected[]            = { 100,  0,  0,  0,  0,  0,  0 };

			clock_t moj_start_time    = clock();
			vector <int> received     = IBEvaluator().getSummary( vector <int>( predictedGrades, predictedGrades + ( sizeof predictedGrades / sizeof predictedGrades[0] ) ), vector <int>( actualGrades, actualGrades + ( sizeof actualGrades / sizeof actualGrades[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 3: {
			int predictedGrades[]     = {1,5,3,5,6,4,2,5,7,6,5,2,3,4,1,4,6,5,4,7,6,6,1};
			int actualGrades[]        = {5,1,3,2,6,4,1,7,5,2,7,4,2,6,5,7,3,1,4,6,3,1,7};
			int expected[]            = { 17,  13,  21,  17,  21,  4,  4 };

			clock_t moj_start_time    = clock();
			vector <int> received     = IBEvaluator().getSummary( vector <int>( predictedGrades, predictedGrades + ( sizeof predictedGrades / sizeof predictedGrades[0] ) ), vector <int>( actualGrades, actualGrades + ( sizeof actualGrades / sizeof actualGrades[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}

		// custom cases

/*      case 4: {
			int predictedGrades[]     = ;
			int actualGrades[]        = ;
			int expected[]            = ;

			clock_t moj_start_time    = clock();
			vector <int> received     = IBEvaluator().getSummary( vector <int>( predictedGrades, predictedGrades + ( sizeof predictedGrades / sizeof predictedGrades[0] ) ), vector <int>( actualGrades, actualGrades + ( sizeof actualGrades / sizeof actualGrades[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}*/
/*      case 5: {
			int predictedGrades[]     = ;
			int actualGrades[]        = ;
			int expected[]            = ;

			clock_t moj_start_time    = clock();
			vector <int> received     = IBEvaluator().getSummary( vector <int>( predictedGrades, predictedGrades + ( sizeof predictedGrades / sizeof predictedGrades[0] ) ), vector <int>( actualGrades, actualGrades + ( sizeof actualGrades / sizeof actualGrades[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int predictedGrades[]     = ;
			int actualGrades[]        = ;
			int expected[]            = ;

			clock_t moj_start_time    = clock();
			vector <int> received     = IBEvaluator().getSummary( vector <int>( predictedGrades, predictedGrades + ( sizeof predictedGrades / sizeof predictedGrades[0] ) ), vector <int>( actualGrades, actualGrades + ( sizeof actualGrades / sizeof actualGrades[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
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
