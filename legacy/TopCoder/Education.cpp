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

class Education {
public:
   int minimize( string desire, vector <int> tests ) 
   {
	   int Sum = 0;
	   int Result;
	   int Size = tests.size();
	   for ( int i = 0 ; i < Size ; i++ )
		   Sum += tests[i];
	   char arr[4] = { 'A' , 'B' , 'C' , 'D' };
	   int MinGrade[4] = { 90 , 80 , 70 , 60 };
	   for ( int i = 0 ; i < 4 ; i++ )
		   if ( arr[i] == desire[0] )
		   {
			   Size++;
			   Result = ( Size * MinGrade[i] ) - Sum;
			   break;
		   }
	   if ( Result < 0 )	Result = 0;
	   if ( Result > 100 )	Result = -1;
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
			string desire             = "A";
			int tests[]               = {0,70};
			int expected              = -1;

			clock_t moj_start_time    = clock();
			int received              = Education().minimize( desire, vector <int>( tests, tests + ( sizeof tests / sizeof tests[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			string desire             = "D";
			int tests[]               = {100,100,100,100,100,100};
			int expected              = 0;

			clock_t moj_start_time    = clock();
			int received              = Education().minimize( desire, vector <int>( tests, tests + ( sizeof tests / sizeof tests[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			string desire             = "B";
			int tests[]               = {80,80,80,73};
			int expected              = 87;

			clock_t moj_start_time    = clock();
			int received              = Education().minimize( desire, vector <int>( tests, tests + ( sizeof tests / sizeof tests[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			string desire             = "B";
			int tests[]               = {80,80,80,73,79};
			int expected              = 88;

			clock_t moj_start_time    = clock();
			int received              = Education().minimize( desire, vector <int>( tests, tests + ( sizeof tests / sizeof tests[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			string desire             = "A";
			int tests[]               = {80};
			int expected              = 100;

			clock_t moj_start_time    = clock();
			int received              = Education().minimize( desire, vector <int>( tests, tests + ( sizeof tests / sizeof tests[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			string desire             = ;
			int tests[]               = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Education().minimize( desire, vector <int>( tests, tests + ( sizeof tests / sizeof tests[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			string desire             = ;
			int tests[]               = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Education().minimize( desire, vector <int>( tests, tests + ( sizeof tests / sizeof tests[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			string desire             = ;
			int tests[]               = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Education().minimize( desire, vector <int>( tests, tests + ( sizeof tests / sizeof tests[0] ) ) );
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
