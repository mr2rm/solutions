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

class Barbecue {
public:
   int eliminate( int n, vector <int> voter, vector <int> excluded ) 
   {
	   int Res , maxvote;
	   Res = maxvote = -1;
	   vector <int> v ( n , 0 );
	   vector <int> vv ( n , 0 );
	   for ( int i = 0 ; i < voter.size() ; i++ )
	   {
		   v[voter[i]]++;
		   vv[excluded[i]]++;
	   }
	   vector <int> temp ( vv.begin() , vv.end() );
	   sort ( temp.begin() , temp.end() );
	   for ( int i = 0 ; i < n ; i++ )
		   if ( vv[i] == temp[n-1] )
			   if ( temp[n-1] != temp[n-2] )
			   {
				   Res = i;
				   break;
			   }
			   else if ( v[i] > maxvote )
			   {
				   maxvote = v[i];
				   Res = i;
			   }
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
			int n                     = 3;
			int voter[]               = {0,1,2,2};
			int excluded[]            = {2,2,0,1};
			int expected              = 2;

			clock_t moj_start_time    = clock();
			int received              = Barbecue().eliminate( n, vector <int>( voter, voter + ( sizeof voter / sizeof voter[0] ) ), vector <int>( excluded, excluded + ( sizeof excluded / sizeof excluded[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int n                     = 3;
			int voter[]               = {0,2,2};
			int excluded[]            = {2,0,1};
			int expected              = 2;

			clock_t moj_start_time    = clock();
			int received              = Barbecue().eliminate( n, vector <int>( voter, voter + ( sizeof voter / sizeof voter[0] ) ), vector <int>( excluded, excluded + ( sizeof excluded / sizeof excluded[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int n                     = 2;
			int voter[]               = {0,1};
			int excluded[]            = {1,0};
			int expected              = 0;

			clock_t moj_start_time    = clock();
			int received              = Barbecue().eliminate( n, vector <int>( voter, voter + ( sizeof voter / sizeof voter[0] ) ), vector <int>( excluded, excluded + ( sizeof excluded / sizeof excluded[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			int n                     = 20;
			int voter[]               = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,3,4,5, 6,7,8,9,10,11,12,13,14,15,16,17,18,19,19,19,19};
			int excluded[]            = {0,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19, 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,1,2,3};
			int expected              = 2;

			clock_t moj_start_time    = clock();
			int received              = Barbecue().eliminate( n, vector <int>( voter, voter + ( sizeof voter / sizeof voter[0] ) ), vector <int>( excluded, excluded + ( sizeof excluded / sizeof excluded[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			int n                     = 5;
			int voter[]               = {4,3,1,0};
			int excluded[]            = {2,2,3,3};
			int expected              = 3;

			clock_t moj_start_time    = clock();
			int received              = Barbecue().eliminate( n, vector <int>( voter, voter + ( sizeof voter / sizeof voter[0] ) ), vector <int>( excluded, excluded + ( sizeof excluded / sizeof excluded[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 5: {
			int n                     = 10;
			int voter[]               = {4,5,6,7,8,9,0,1,2};
			int excluded[]            = {5,6,7,8,9,0,1,2,3};
			int expected              = 0;

			clock_t moj_start_time    = clock();
			int received              = Barbecue().eliminate( n, vector <int>( voter, voter + ( sizeof voter / sizeof voter[0] ) ), vector <int>( excluded, excluded + ( sizeof excluded / sizeof excluded[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 6: {
			int n                     = 7;
			int voter[]               = {1,2,3,4,5,6,0,2,3,4,5,6,0,1,3,4,5,6,0,1,2,  4,5,6,0,1,2,3,5,6,0,1,2,3,4,6,0,1,2,3,4,5};
			int excluded[]            = {0,0,0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,3,3,3,  3,3,3,4,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6};
			int expected              = 0;

			clock_t moj_start_time    = clock();
			int received              = Barbecue().eliminate( n, vector <int>( voter, voter + ( sizeof voter / sizeof voter[0] ) ), vector <int>( excluded, excluded + ( sizeof excluded / sizeof excluded[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 7: {
			int n                     = 5;
			// int voter[]            = empty, commented out for VC++;
			// int excluded[]         = empty, commented out for VC++;
			int expected              = 0;

			clock_t moj_start_time    = clock();
			int received              = Barbecue().eliminate( n, vector <int>(), vector <int>() );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 8: {
			int n                     = ;
			int voter[]               = ;
			int excluded[]            = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Barbecue().eliminate( n, vector <int>( voter, voter + ( sizeof voter / sizeof voter[0] ) ), vector <int>( excluded, excluded + ( sizeof excluded / sizeof excluded[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 9: {
			int n                     = ;
			int voter[]               = ;
			int excluded[]            = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Barbecue().eliminate( n, vector <int>( voter, voter + ( sizeof voter / sizeof voter[0] ) ), vector <int>( excluded, excluded + ( sizeof excluded / sizeof excluded[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 10: {
			int n                     = ;
			int voter[]               = ;
			int excluded[]            = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Barbecue().eliminate( n, vector <int>( voter, voter + ( sizeof voter / sizeof voter[0] ) ), vector <int>( excluded, excluded + ( sizeof excluded / sizeof excluded[0] ) ) );
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
