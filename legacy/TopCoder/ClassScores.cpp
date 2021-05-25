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

class ClassScores {
public:
   vector <int> findMode( vector <int> scores ) 
   {
	   vector <int> Res;
	   vector <int> v ( 101 , 0 );
	   for ( int i = 0 ; i < scores.size() ; i++ )
		   v[scores[i]]++;
	   vector <int> vv ( v );
	   sort ( vv.begin() , vv.end() );
	   for ( int i = 0 ; i < 101 ; i++ )
		   if ( v[i] == vv[100] )
			   Res.push_back ( i );
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
			int scores[]              = {65, 70, 88, 70};
			int expected[]            = {70 };

			clock_t moj_start_time    = clock();
			vector <int> received     = ClassScores().findMode( vector <int>( scores, scores + ( sizeof scores / sizeof scores[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 1: {
			int scores[]              = {88, 70, 65, 70, 88};
			int expected[]            = {70, 88 };

			clock_t moj_start_time    = clock();
			vector <int> received     = ClassScores().findMode( vector <int>( scores, scores + ( sizeof scores / sizeof scores[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 2: {
			int scores[]              = {92, 56, 14, 73, 22, 38, 93, 45, 55};
			int expected[]            = {14, 22, 38, 45, 55, 56, 73, 92, 93 };

			clock_t moj_start_time    = clock();
			vector <int> received     = ClassScores().findMode( vector <int>( scores, scores + ( sizeof scores / sizeof scores[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}

		// custom cases

/*      case 3: {
			int scores[]              = ;
			int expected[]            = ;

			clock_t moj_start_time    = clock();
			vector <int> received     = ClassScores().findMode( vector <int>( scores, scores + ( sizeof scores / sizeof scores[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}*/
/*      case 4: {
			int scores[]              = ;
			int expected[]            = ;

			clock_t moj_start_time    = clock();
			vector <int> received     = ClassScores().findMode( vector <int>( scores, scores + ( sizeof scores / sizeof scores[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}*/
/*      case 5: {
			int scores[]              = ;
			int expected[]            = ;

			clock_t moj_start_time    = clock();
			vector <int> received     = ClassScores().findMode( vector <int>( scores, scores + ( sizeof scores / sizeof scores[0] ) ) );
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
