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

class CutoffRounder {
public:
   int round( string num, string cutoff ) 
   {
	   bool b = false;
	   for ( int i = 0 ; i < num.length() ; i++ )
	   {
		   if ( num[i] == '.' )
		   {
			   b = true;
			   break;
		   }
	   }
	   if ( b == false )
		   num = num + ".";
	   if ( num[0] == '.' )
		   num = "0" + num;
	   if ( num[ num.length() - 1 ] == '.' )
		   num = num + "0";
	   int i;
	   for ( i = 0 ; num[i] == '0' ; i++ );
	   string s ( num.begin() + i , num.end() );
	   for ( i = 0 ; s[i] != '.' ; i++ );
	   string str ( s.begin() + i , s.end() );
	   str = "0" + str;
	   stringstream ss1 ( str );
	   double n , c , number;
	   ss1 >> n;
	   stringstream ss2 ( cutoff );
	   ss2 >> c;
	   stringstream ss3 ( s );
	   ss3 >> number;
	   if ( n > c )
		   return ceil ( number );
	   else
		   return floor ( number );
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
			string num                = "003.656930";
			string cutoff             = "0.5000";
			int expected              = 4;

			clock_t moj_start_time    = clock();
			int received              = CutoffRounder().round( num, cutoff );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			string num                = ".001";
			string cutoff             = "0.0001";
			int expected              = 1;

			clock_t moj_start_time    = clock();
			int received              = CutoffRounder().round( num, cutoff );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			string num                = "1.99999999";
			string cutoff             = "0.9999";
			int expected              = 2;

			clock_t moj_start_time    = clock();
			int received              = CutoffRounder().round( num, cutoff );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			string num                = "135";
			string cutoff             = "0.6531";
			int expected              = 135;

			clock_t moj_start_time    = clock();
			int received              = CutoffRounder().round( num, cutoff );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			string num                = "135.";
			string cutoff             = "0.6531";
			int expected              = 135;

			clock_t moj_start_time    = clock();
			int received              = CutoffRounder().round( num, cutoff );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 5: {
			string num                = "1356.13671";
			string cutoff             = "0.1367";
			int expected              = 1357;

			clock_t moj_start_time    = clock();
			int received              = CutoffRounder().round( num, cutoff );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 6: {
			string num                = "0.00010001";
			string cutoff             = "0.0001";
			int expected              = 1;

			clock_t moj_start_time    = clock();
			int received              = CutoffRounder().round( num, cutoff );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 7: {
			string num                = ;
			string cutoff             = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = CutoffRounder().round( num, cutoff );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 8: {
			string num                = ;
			string cutoff             = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = CutoffRounder().round( num, cutoff );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 9: {
			string num                = ;
			string cutoff             = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = CutoffRounder().round( num, cutoff );
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
