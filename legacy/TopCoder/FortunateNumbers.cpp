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

class FortunateNumbers {
public:
   int getFortunate( vector <int> a, vector <int> b, vector <int> c ) 
   {
	   vector<bool> flags ( 90000 , false );
	   int Result = 0;
	   int fortune;
	   int Temp;
	   for ( int i = 0 ; i < a.size() ; i++ )
		   for ( int j = 0 ; j < b.size() ; j++ )
			   for ( int k = 0 ; k < c.size() ; k++ )
			   {
				   fortune = a[i] + b[j] + c[k];
				   Temp = fortune;
				   bool b = true;
				   do
				   {
					   if ( Temp % 10 != 8 && Temp % 10 != 5 )
					   {
						   b = false;
						   break;
					   }
					   else
						   Temp /= 10;
				   }
				   while ( Temp != 0 );
				   if ( b == true && flags[fortune] == false )
				   {
					   flags[fortune] = true;
					   Result++;
				   }
			   }
			   return Result;
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
			int a[]                   = { 1, 10, 100 };
			int b[]                   = { 3, 53 };
			int c[]                   = { 4, 54 };
			int expected              = 2;

			clock_t moj_start_time    = clock();
			int received              = FortunateNumbers().getFortunate( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), vector <int>( c, c + ( sizeof c / sizeof c[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int a[]                   = { 47 };
			int b[]                   = { 500 };
			int c[]                   = { 33 };
			int expected              = 0;

			clock_t moj_start_time    = clock();
			int received              = FortunateNumbers().getFortunate( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), vector <int>( c, c + ( sizeof c / sizeof c[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int a[]                   = { 100, 1, 10, 100, 1, 1 };
			int b[]                   = { 3, 53, 53, 53, 53, 53, 53 };
			int c[]                   = { 4, 54, 4, 54, 4, 54 };
			int expected              = 2;

			clock_t moj_start_time    = clock();
			int received              = FortunateNumbers().getFortunate( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), vector <int>( c, c + ( sizeof c / sizeof c[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			int a[]                   = { 500, 800 };
			int b[]                   = { 50, 80 };
			int c[]                   = { 5, 8 };
			int expected              = 8;

			clock_t moj_start_time    = clock();
			int received              = FortunateNumbers().getFortunate( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), vector <int>( c, c + ( sizeof c / sizeof c[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			int a[]                   = { 30000, 26264 };
			int b[]                   = { 30000, 29294 };
			int c[]                   = { 30000, 29594 };
			int expected              = 3;

			clock_t moj_start_time    = clock();
			int received              = FortunateNumbers().getFortunate( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), vector <int>( c, c + ( sizeof c / sizeof c[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			int a[]                   = ;
			int b[]                   = ;
			int c[]                   = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = FortunateNumbers().getFortunate( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), vector <int>( c, c + ( sizeof c / sizeof c[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int a[]                   = ;
			int b[]                   = ;
			int c[]                   = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = FortunateNumbers().getFortunate( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), vector <int>( c, c + ( sizeof c / sizeof c[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			int a[]                   = ;
			int b[]                   = ;
			int c[]                   = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = FortunateNumbers().getFortunate( vector <int>( a, a + ( sizeof a / sizeof a[0] ) ), vector <int>( b, b + ( sizeof b / sizeof b[0] ) ), vector <int>( c, c + ( sizeof c / sizeof c[0] ) ) );
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
