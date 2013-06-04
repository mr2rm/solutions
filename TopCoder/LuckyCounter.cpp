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

class LuckyCounter {
public:
   int countLuckyMoments( vector <string> moments ) 
   {
	   /*
	   int Sum = 0;
	   for ( int i = 0 ; i < moments.size() ; i++ )
	   {
		   string A ( moments[i].begin() , moments[i].begin() + 2 );
		   string B ( moments[i].begin() + 3 , moments[i].end() );
		   //string C ( 2 , '0' );	C[0] = A[1];	C[1] = A[0];
		   string C = A;	reverse ( A.begin() , A.end() );
		   if ( A == B || B == C || ( A[0] == A[1] && B[0] == B[1] ) )
			   Sum++;
	   }
	   return Sum;
	   */
	   /*
	   int Sum = 0;
	   for ( int i = 0 ; i < moments.size() ; i++ )
	   {
		   if ( ( moments[i][0] == moments[i][1] && moments[i][3] == moments[i][4] ) ||
				( moments[i][0] == moments[i][4] && moments[i][1] == moments[i][3] ) ||
				( moments[i][0] == moments[i][3] && moments[i][1] == moments[i][4] ) )
				  Sum++;
	   }
	   return Sum;
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
			string moments[]          = {"12:21", "11:10"};
			int expected              = 1;

			clock_t moj_start_time    = clock();
			int received              = LuckyCounter().countLuckyMoments( vector <string>( moments, moments + ( sizeof moments / sizeof moments[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			string moments[]          = {"00:00", "00:59", "23:00"};
			int expected              = 1;

			clock_t moj_start_time    = clock();
			int received              = LuckyCounter().countLuckyMoments( vector <string>( moments, moments + ( sizeof moments / sizeof moments[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			string moments[]          = {"12:34"};
			int expected              = 0;

			clock_t moj_start_time    = clock();
			int received              = LuckyCounter().countLuckyMoments( vector <string>( moments, moments + ( sizeof moments / sizeof moments[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			string moments[]          = {"12:11", "22:22", "00:01", "03:30", "15:15", "16:00"};
			int expected              = 3;

			clock_t moj_start_time    = clock();
			int received              = LuckyCounter().countLuckyMoments( vector <string>( moments, moments + ( sizeof moments / sizeof moments[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 4: {
			string moments[]          = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = LuckyCounter().countLuckyMoments( vector <string>( moments, moments + ( sizeof moments / sizeof moments[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 5: {
			string moments[]          = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = LuckyCounter().countLuckyMoments( vector <string>( moments, moments + ( sizeof moments / sizeof moments[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			string moments[]          = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = LuckyCounter().countLuckyMoments( vector <string>( moments, moments + ( sizeof moments / sizeof moments[0] ) ) );
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
