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

class grafixClick {
public:
   vector <int> checkSaveButton( vector <int> mouseRows, vector <int> mouseCols ) 
   {
	   vector <int> Results;
	   int size = mouseRows.size();
	   for ( int i = 0 ; i < size ; i++ )
		   if ( mouseRows[i] >= 20 && mouseRows[i] <= 39 &&
			    mouseCols[i] >= 50 && mouseCols[i] <= 99 )
				Results.push_back ( i );
	   sort ( Results.begin() , Results.end() );
	   return Results;
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
			int mouseRows[]           = {20, 39, 100};
			int mouseCols[]           = {99, 50, 200};
			int expected[]            = { 0,  1 };

			clock_t moj_start_time    = clock();
			vector <int> received     = grafixClick().checkSaveButton( vector <int>( mouseRows, mouseRows + ( sizeof mouseRows / sizeof mouseRows[0] ) ), vector <int>( mouseCols, mouseCols + ( sizeof mouseCols / sizeof mouseCols[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 1: {
			int mouseRows[]           = {0, 100, 399};
			int mouseCols[]           = {0, 200, 599};
			// int expected[]         = empty, commented out for VC++;

			clock_t moj_start_time    = clock();
			vector <int> received     = grafixClick().checkSaveButton( vector <int>( mouseRows, mouseRows + ( sizeof mouseRows / sizeof mouseRows[0] ) ), vector <int>( mouseCols, mouseCols + ( sizeof mouseCols / sizeof mouseCols[0] ) ) );
			return verify_case( casenum, vector <int>(), received, clock()-moj_start_time );
		}
		case 2: {
			int mouseRows[]           = {30};
			int mouseCols[]           = {75};
			int expected[]            = { 0 };

			clock_t moj_start_time    = clock();
			vector <int> received     = grafixClick().checkSaveButton( vector <int>( mouseRows, mouseRows + ( sizeof mouseRows / sizeof mouseRows[0] ) ), vector <int>( mouseCols, mouseCols + ( sizeof mouseCols / sizeof mouseCols[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 3: {
			int mouseRows[]           = {10, 20, 30, 30, 30, 30, 34, 35, 345};
			int mouseCols[]           = {10, 20, 30, 50, 60, 80, 34, 35, 345};
			int expected[]            = { 3,  4,  5 };

			clock_t moj_start_time    = clock();
			vector <int> received     = grafixClick().checkSaveButton( vector <int>( mouseRows, mouseRows + ( sizeof mouseRows / sizeof mouseRows[0] ) ), vector <int>( mouseCols, mouseCols + ( sizeof mouseCols / sizeof mouseCols[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 4: {
			int mouseRows[]           = {57, 28, 18, 25, 36, 12, 33, 44, 13, 32,  32, 51, 11, 27, 8, 51, 17, 34, 10, 16,  47, 57, 20, 57, 32, 14, 13, 37, 10, 16,  49, 37, 52, 8, 18, 44, 50, 43, 11, 1,  21, 22, 17, 35, 28, 53, 56, 16, 11, 44};
			int mouseCols[]           = {146, 22, 41, 88, 123, 99, 43, 110, 25, 64,  141, 110, 70, 34, 99, 103, 60, 64, 142, 109,  133, 144, 72, 68, 25, 32, 21, 140, 30, 105,  32, 72, 114, 97, 35, 131, 103, 110, 133, 81,  125, 36, 76, 78, 77, 47, 50, 94, 22, 20};
			int expected[]            = { 3,  9,  17,  22,  31,  43,  44 };

			clock_t moj_start_time    = clock();
			vector <int> received     = grafixClick().checkSaveButton( vector <int>( mouseRows, mouseRows + ( sizeof mouseRows / sizeof mouseRows[0] ) ), vector <int>( mouseCols, mouseCols + ( sizeof mouseCols / sizeof mouseCols[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			int mouseRows[]           = ;
			int mouseCols[]           = ;
			int expected[]            = ;

			clock_t moj_start_time    = clock();
			vector <int> received     = grafixClick().checkSaveButton( vector <int>( mouseRows, mouseRows + ( sizeof mouseRows / sizeof mouseRows[0] ) ), vector <int>( mouseCols, mouseCols + ( sizeof mouseCols / sizeof mouseCols[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int mouseRows[]           = ;
			int mouseCols[]           = ;
			int expected[]            = ;

			clock_t moj_start_time    = clock();
			vector <int> received     = grafixClick().checkSaveButton( vector <int>( mouseRows, mouseRows + ( sizeof mouseRows / sizeof mouseRows[0] ) ), vector <int>( mouseCols, mouseCols + ( sizeof mouseCols / sizeof mouseCols[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}*/
/*      case 7: {
			int mouseRows[]           = ;
			int mouseCols[]           = ;
			int expected[]            = ;

			clock_t moj_start_time    = clock();
			vector <int> received     = grafixClick().checkSaveButton( vector <int>( mouseRows, mouseRows + ( sizeof mouseRows / sizeof mouseRows[0] ) ), vector <int>( mouseCols, mouseCols + ( sizeof mouseCols / sizeof mouseCols[0] ) ) );
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
