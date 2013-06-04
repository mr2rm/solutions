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

class GolfScore {
public:
   int tally( vector <int> parValues, vector <string> scoreSheet ) 
   {
	   string Performance[7] = { "triple bogey" , "double bogey" , "bogey" , "par" , "birdie" , "eagle" , "albatross" };
	   int Points[7] = { 3 , 2 , 1 , 0 , -1 , -2 , -3 };
	   int Scores = 0;
	   bool b;
	   for ( int i = 0 ; i < scoreSheet.size() ; i++ )
	   {
		   b = false;
		   for ( int j = 0 ; j < 7 ; j++ )
			   if ( scoreSheet[i] == Performance[j] )
			   {
				   Scores += parValues[i] + Points[j];
				   b = true;
				   break;
			   }
		   if ( b == false )
			   Scores++;
	   }
	   return Scores;
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
			int parValues[]           = {1, 1, 1, 1, 1, 1,  1, 1, 1, 5, 5, 5,  5, 5, 5, 5, 5, 5};
			string scoreSheet[]       = {"bogey", "bogey", "bogey", "bogey", "bogey", "bogey",  "bogey", "bogey", "bogey", "eagle", "eagle", "eagle",  "eagle", "eagle", "eagle", "eagle", "eagle", "eagle"};
			int expected              = 45;

			clock_t moj_start_time    = clock();
			int received              = GolfScore().tally( vector <int>( parValues, parValues + ( sizeof parValues / sizeof parValues[0] ) ), vector <string>( scoreSheet, scoreSheet + ( sizeof scoreSheet / sizeof scoreSheet[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int parValues[]           = {3, 2, 4, 2, 2, 1,  1, 1, 3, 2, 4, 4,  4, 2, 3, 1, 3, 2};
			string scoreSheet[]       = {"bogey", "double bogey", "par", "double bogey", "double bogey", "triple bogey",  "triple bogey", "triple bogey", "bogey", "double bogey", "par", "par",  "par", "double bogey", "bogey", "triple bogey", "bogey", "double bogey"};
			int expected              = 72;

			clock_t moj_start_time    = clock();
			int received              = GolfScore().tally( vector <int>( parValues, parValues + ( sizeof parValues / sizeof parValues[0] ) ), vector <string>( scoreSheet, scoreSheet + ( sizeof scoreSheet / sizeof scoreSheet[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int parValues[]           = {3, 2, 4, 2, 2, 1,  1, 1, 3, 2, 4, 4,  4, 2, 3, 1, 3, 2};
			string scoreSheet[]       = {"eagle", "birdie", "albatross", "birdie", "birdie", "par",  "hole in one", "par", "eagle", "birdie", "albatross", "albatross",  "albatross", "birdie", "eagle", "hole in one", "eagle", "birdie"};
			int expected              = 18;

			clock_t moj_start_time    = clock();
			int received              = GolfScore().tally( vector <int>( parValues, parValues + ( sizeof parValues / sizeof parValues[0] ) ), vector <string>( scoreSheet, scoreSheet + ( sizeof scoreSheet / sizeof scoreSheet[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			int parValues[]           = {4, 1, 3, 3, 4, 4,  1, 4, 2, 3, 3, 5,  4, 1, 4, 4, 2, 1};
			string scoreSheet[]       = {"triple bogey", "triple bogey", "bogey", "par", "triple bogey", "double bogey",  "triple bogey", "triple bogey", "par", "eagle", "bogey", "bogey",  "birdie", "par", "triple bogey", "eagle", "triple bogey", "triple bogey"};
			int expected              = 77;

			clock_t moj_start_time    = clock();
			int received              = GolfScore().tally( vector <int>( parValues, parValues + ( sizeof parValues / sizeof parValues[0] ) ), vector <string>( scoreSheet, scoreSheet + ( sizeof scoreSheet / sizeof scoreSheet[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 4: {
			int parValues[]           = ;
			string scoreSheet[]       = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = GolfScore().tally( vector <int>( parValues, parValues + ( sizeof parValues / sizeof parValues[0] ) ), vector <string>( scoreSheet, scoreSheet + ( sizeof scoreSheet / sizeof scoreSheet[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 5: {
			int parValues[]           = ;
			string scoreSheet[]       = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = GolfScore().tally( vector <int>( parValues, parValues + ( sizeof parValues / sizeof parValues[0] ) ), vector <string>( scoreSheet, scoreSheet + ( sizeof scoreSheet / sizeof scoreSheet[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int parValues[]           = ;
			string scoreSheet[]       = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = GolfScore().tally( vector <int>( parValues, parValues + ( sizeof parValues / sizeof parValues[0] ) ), vector <string>( scoreSheet, scoreSheet + ( sizeof scoreSheet / sizeof scoreSheet[0] ) ) );
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
