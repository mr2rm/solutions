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

class RPG {
public:
   vector <int> dieRolls( vector <string> dice ) 
   {
	   vector <int> ANS ( 3 , 0 );
	   for ( int i = 0 ; i < dice.size() ; i++ )
	   {
		   int index = ( dice[i][1] == 'd' ? 2 : 3 );
		   string str1 ( dice[i].begin() , dice[i].begin() + index - 1 );
		   string str2 ( dice[i].begin() + index , dice[i].end() );
		   stringstream ss1 ( str1 );	stringstream ss2 ( str2 );
		   int x1 , x2;
		   ss1 >> x1;	ss2 >> x2;
		   ANS[1] += x1 * x2;	ANS[0] += x1;
	   }
	   ANS[2] = ( ANS[0] + ANS[1] ) / 2;
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
			string dice[]             = {"3d6"};
			int expected[]            = { 3,  18,  10 };

			clock_t moj_start_time    = clock();
			vector <int> received     = RPG().dieRolls( vector <string>( dice, dice + ( sizeof dice / sizeof dice[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 1: {
			string dice[]             = {"3d4","1d6"};
			int expected[]            = { 4,  18,  11 };

			clock_t moj_start_time    = clock();
			vector <int> received     = RPG().dieRolls( vector <string>( dice, dice + ( sizeof dice / sizeof dice[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 2: {
			string dice[]             = {"6d5","10d10","10d20"};
			int expected[]            = { 26,  330,  178 };

			clock_t moj_start_time    = clock();
			vector <int> received     = RPG().dieRolls( vector <string>( dice, dice + ( sizeof dice / sizeof dice[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 3: {
			string dice[]             = {"1d2","2d2","4d2","6d2","8d2"};
			int expected[]            = { 21,  42,  31 };

			clock_t moj_start_time    = clock();
			vector <int> received     = RPG().dieRolls( vector <string>( dice, dice + ( sizeof dice / sizeof dice[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}

		// custom cases

/*      case 4: {
			string dice[]             = ;
			int expected[]            = ;

			clock_t moj_start_time    = clock();
			vector <int> received     = RPG().dieRolls( vector <string>( dice, dice + ( sizeof dice / sizeof dice[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}*/
/*      case 5: {
			string dice[]             = ;
			int expected[]            = ;

			clock_t moj_start_time    = clock();
			vector <int> received     = RPG().dieRolls( vector <string>( dice, dice + ( sizeof dice / sizeof dice[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}*/
/*      case 6: {
			string dice[]             = ;
			int expected[]            = ;

			clock_t moj_start_time    = clock();
			vector <int> received     = RPG().dieRolls( vector <string>( dice, dice + ( sizeof dice / sizeof dice[0] ) ) );
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
