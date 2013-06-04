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

class SkipRope {
public:
   vector <int> partners( vector <int> candidates, int height ) 
   {
	   vector <int> ANS;
	   int dif , index = -1 , m;
	   sort ( candidates.begin() , candidates.end() );
	   for ( int j = 0 ; j < 2 ; j++ )
	   {
		   dif = 101;
		   for ( int i = 0 ; i < candidates.size() ; i++ )
			   if ( fabs ( ( double) candidates[i] - height ) <= dif && i != index )
			   {
				   dif = fabs ( (double) candidates[i] - height );
				   m = candidates[i];
				   if ( j == 0 )
					   index = i;
			   }
			ANS.push_back ( m );
	   }
	   sort ( ANS.begin() , ANS.end() );
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
			int candidates[]          = {102, 99, 104};
			int height                = 100;
			int expected[]            = { 99,  102 };

			clock_t moj_start_time    = clock();
			vector <int> received     = SkipRope().partners( vector <int>( candidates, candidates + ( sizeof candidates / sizeof candidates[0] ) ), height );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 1: {
			int candidates[]          = {102, 97, 104};
			int height                = 100;
			int expected[]            = { 97,  102 };

			clock_t moj_start_time    = clock();
			vector <int> received     = SkipRope().partners( vector <int>( candidates, candidates + ( sizeof candidates / sizeof candidates[0] ) ), height );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 2: {
			int candidates[]          = {101, 100, 99};
			int height                = 100;
			int expected[]            = { 100,  101 };

			clock_t moj_start_time    = clock();
			vector <int> received     = SkipRope().partners( vector <int>( candidates, candidates + ( sizeof candidates / sizeof candidates[0] ) ), height );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 3: {
			int candidates[]          = {75, 117, 170, 175, 168, 167, 167, 142, 170, 85, 89, 170};
			int height                = 169;
			int expected[]            = { 170,  170 };

			clock_t moj_start_time    = clock();
			vector <int> received     = SkipRope().partners( vector <int>( candidates, candidates + ( sizeof candidates / sizeof candidates[0] ) ), height );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 4: {
			int candidates[]          = {134, 79, 164, 86, 131, 78, 99, 150, 105, 163, 150, 110, 90, 137, 127, 130, 121,   93, 97, 131, 170, 137, 171, 153, 137, 138, 92, 103, 149, 110, 156};
			int height                = 82;
			int expected[]            = { 79,  86 };

			clock_t moj_start_time    = clock();
			vector <int> received     = SkipRope().partners( vector <int>( candidates, candidates + ( sizeof candidates / sizeof candidates[0] ) ), height );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			int candidates[]          = ;
			int height                = ;
			int expected[]            = ;

			clock_t moj_start_time    = clock();
			vector <int> received     = SkipRope().partners( vector <int>( candidates, candidates + ( sizeof candidates / sizeof candidates[0] ) ), height );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int candidates[]          = ;
			int height                = ;
			int expected[]            = ;

			clock_t moj_start_time    = clock();
			vector <int> received     = SkipRope().partners( vector <int>( candidates, candidates + ( sizeof candidates / sizeof candidates[0] ) ), height );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}*/
/*      case 7: {
			int candidates[]          = ;
			int height                = ;
			int expected[]            = ;

			clock_t moj_start_time    = clock();
			vector <int> received     = SkipRope().partners( vector <int>( candidates, candidates + ( sizeof candidates / sizeof candidates[0] ) ), height );
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
