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

class Medici {
public:
   int winner( vector <int> fame, vector <int> fortune, vector <int> secrets ) 
   {
	   //1//
	   /*vector <int> MIN ( fame.size() );
	   for ( int i = 0 ; i < MIN.size() ; i++ )
		   MIN[i] = min( min( fame[i] , fortune[i] ) , secrets[i] );
	   int Result = 0;
	   int Minimum = MIN[0];
	   for ( int i = 1 ; i < MIN.size() ; i++ )
	   {
		   if ( MIN[i] > Minimum )
		   {
			   Result = i;
			   Minimum = MIN[i];
		   }
		   else if ( MIN[i] == Minimum )	Result = -1;
	   }
	   return Result;*/

	   //2//
	   /*int Size = fame.size();
	   int Mini , Result , Temp;
	   Result = Mini = -1;
	   for ( int i = 0 ; i < Size ; i++ )
	   {
		   Temp = min( min( fame[i] , fortune[i] ) , secrets[i] );
		   if ( Temp > Mini )
		   {
			   Mini = Temp;
			   Result = i;
		   }
		   else if ( Temp == Mini )	Result = -1;
	   }
	   return Result;*/
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
			int fame[]                = { 20, 30, 50 };
			int fortune[]             = { 60, 80, 40 };
			int secrets[]             = { 40, 30, 50 };
			int expected              = 2;

			clock_t moj_start_time    = clock();
			int received              = Medici().winner( vector <int>( fame, fame + ( sizeof fame / sizeof fame[0] ) ), vector <int>( fortune, fortune + ( sizeof fortune / sizeof fortune[0] ) ), vector <int>( secrets, secrets + ( sizeof secrets / sizeof secrets[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int fame[]                = {   0, 100, 100, 100 };
			int fortune[]             = { 100,   0, 100,  50 };
			int secrets[]             = {  50,  50,  50, 100 };
			int expected              = -1;

			clock_t moj_start_time    = clock();
			int received              = Medici().winner( vector <int>( fame, fame + ( sizeof fame / sizeof fame[0] ) ), vector <int>( fortune, fortune + ( sizeof fortune / sizeof fortune[0] ) ), vector <int>( secrets, secrets + ( sizeof secrets / sizeof secrets[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int fame[]                = { 1, 0 };
			int fortune[]             = { 1, 99 };
			int secrets[]             = { 1, 99 };
			int expected              = 0;

			clock_t moj_start_time    = clock();
			int received              = Medici().winner( vector <int>( fame, fame + ( sizeof fame / sizeof fame[0] ) ), vector <int>( fortune, fortune + ( sizeof fortune / sizeof fortune[0] ) ), vector <int>( secrets, secrets + ( sizeof secrets / sizeof secrets[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			int fame[]                = { 39, 42, 57 };
			int fortune[]             = { 42, 39, 57 };
			int secrets[]             = { 57, 39, 42 };
			int expected              = 2;

			clock_t moj_start_time    = clock();
			int received              = Medici().winner( vector <int>( fame, fame + ( sizeof fame / sizeof fame[0] ) ), vector <int>( fortune, fortune + ( sizeof fortune / sizeof fortune[0] ) ), vector <int>( secrets, secrets + ( sizeof secrets / sizeof secrets[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			int fame[]                = { 3, 98, 0, 71, 81, 85, 99, 58, 93, 79, 100, 98, 73, 83, 52, 100, 37, 93, 39, 27 };
			int fortune[]             = { 96, 34, 45, 20, 72, 71, 7, 18, 47, 35, 54, 51, 52, 21, 49, 20, 44, 72, 90, 93 };
			int secrets[]             = { 15, 72, 50, 84, 41, 49, 35, 71, 20, 29, 73, 18, 35, 61, 70, 34, 59, 68, 90, 18 };
			int expected              = 17;

			clock_t moj_start_time    = clock();
			int received              = Medici().winner( vector <int>( fame, fame + ( sizeof fame / sizeof fame[0] ) ), vector <int>( fortune, fortune + ( sizeof fortune / sizeof fortune[0] ) ), vector <int>( secrets, secrets + ( sizeof secrets / sizeof secrets[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			int fame[]                = ;
			int fortune[]             = ;
			int secrets[]             = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Medici().winner( vector <int>( fame, fame + ( sizeof fame / sizeof fame[0] ) ), vector <int>( fortune, fortune + ( sizeof fortune / sizeof fortune[0] ) ), vector <int>( secrets, secrets + ( sizeof secrets / sizeof secrets[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int fame[]                = ;
			int fortune[]             = ;
			int secrets[]             = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Medici().winner( vector <int>( fame, fame + ( sizeof fame / sizeof fame[0] ) ), vector <int>( fortune, fortune + ( sizeof fortune / sizeof fortune[0] ) ), vector <int>( secrets, secrets + ( sizeof secrets / sizeof secrets[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			int fame[]                = ;
			int fortune[]             = ;
			int secrets[]             = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Medici().winner( vector <int>( fame, fame + ( sizeof fame / sizeof fame[0] ) ), vector <int>( fortune, fortune + ( sizeof fortune / sizeof fortune[0] ) ), vector <int>( secrets, secrets + ( sizeof secrets / sizeof secrets[0] ) ) );
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
