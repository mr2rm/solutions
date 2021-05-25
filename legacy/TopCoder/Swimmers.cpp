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

class Swimmers {
public:
   vector <int> getSwimTimes( vector <int> distances, vector <int> speeds, int current ) 
   {
	   int S = distances.size();
	   vector <int> ANS ( S );
	   for ( int i = 0 ; i < S ; i++ )
	   {
		   if ( distances[i] == 0 )
		   {
			   ANS[i] = 0;
			   continue;
		   }
		   if ( speeds[i] - current <= 0 )
			   ANS[i] = -1;
		   else
		   {
			   double t;
			   t = ( double ) distances[i] / ( speeds[i] + current );
			   t += ( double ) distances[i] / ( speeds[i] - current );
			   ANS[i] = t;
		   }
	   }
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
			int distances[]           = { 300, 300, 300 };
			int speeds[]              = { 1, 2, 3 };
			int current               = 2;
			int expected[]            = { -1,  -1,  360 };

			clock_t moj_start_time    = clock();
			vector <int> received     = Swimmers().getSwimTimes( vector <int>( distances, distances + ( sizeof distances / sizeof distances[0] ) ), vector <int>( speeds, speeds + ( sizeof speeds / sizeof speeds[0] ) ), current );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 1: {
			int distances[]           = { 500, 500 };
			int speeds[]              = { 4, 5 };
			int current               = 2;
			int expected[]            = { 333,  238 };

			clock_t moj_start_time    = clock();
			vector <int> received     = Swimmers().getSwimTimes( vector <int>( distances, distances + ( sizeof distances / sizeof distances[0] ) ), vector <int>( speeds, speeds + ( sizeof speeds / sizeof speeds[0] ) ), current );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 2: {
			int distances[]           = { 0, 0 };
			int speeds[]              = { 1, 2 };
			int current               = 1;
			int expected[]            = { 0,  0 };

			clock_t moj_start_time    = clock();
			vector <int> received     = Swimmers().getSwimTimes( vector <int>( distances, distances + ( sizeof distances / sizeof distances[0] ) ), vector <int>( speeds, speeds + ( sizeof speeds / sizeof speeds[0] ) ), current );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 3: {
			int distances[]           = { 0, 1 };
			int speeds[]              = { 0, 0 };
			int current               = 0;
			int expected[]            = { 0,  -1 };

			clock_t moj_start_time    = clock();
			vector <int> received     = Swimmers().getSwimTimes( vector <int>( distances, distances + ( sizeof distances / sizeof distances[0] ) ), vector <int>( speeds, speeds + ( sizeof speeds / sizeof speeds[0] ) ), current );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 4: {
			int distances[]           = { 7507, 7517, 7523, 7529, 7537, 7541, 7547, 7549, 7559, 7561, 7573, 7577, 7583,   7589, 7591, 7603, 7607, 7621, 7639, 7643, 7649, 7669, 7673, 7681, 7687, 7691,   7699, 7703, 7717, 7723, 7727, 7741, 7753, 7757, 7759, 7789, 7793, 7817, 7823,   7829, 7841, 7853, 7867, 7873, 7877, 7879, 7883, 7901, 7907, 7919 };
			int speeds[]              = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,   73, 79, 83, 89, 97, 99, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30,   32, 34, 36, 38, 40, 42, 44, 46, 48, 51 };
			int current               = 6;
			int expected[]            = { -1,  -1,  -1,  8108,  1950,  1474,  1014,  882,  705,  544,  507,  420,  377,  359,  328,  290,  260,  252,  229,  216,  210,  195,  185,  173,  159,  155,  -1,  -1,  4409,  2413,  1717,  1354,  1127,  969,  852,  764,  692,  635,  585,  543,  507,  476,  449,  424,  402,  383,  365,  349,  334,  314 };

			clock_t moj_start_time    = clock();
			vector <int> received     = Swimmers().getSwimTimes( vector <int>( distances, distances + ( sizeof distances / sizeof distances[0] ) ), vector <int>( speeds, speeds + ( sizeof speeds / sizeof speeds[0] ) ), current );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			int distances[]           = ;
			int speeds[]              = ;
			int current               = ;
			int expected[]            = ;

			clock_t moj_start_time    = clock();
			vector <int> received     = Swimmers().getSwimTimes( vector <int>( distances, distances + ( sizeof distances / sizeof distances[0] ) ), vector <int>( speeds, speeds + ( sizeof speeds / sizeof speeds[0] ) ), current );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int distances[]           = ;
			int speeds[]              = ;
			int current               = ;
			int expected[]            = ;

			clock_t moj_start_time    = clock();
			vector <int> received     = Swimmers().getSwimTimes( vector <int>( distances, distances + ( sizeof distances / sizeof distances[0] ) ), vector <int>( speeds, speeds + ( sizeof speeds / sizeof speeds[0] ) ), current );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}*/
/*      case 7: {
			int distances[]           = ;
			int speeds[]              = ;
			int current               = ;
			int expected[]            = ;

			clock_t moj_start_time    = clock();
			vector <int> received     = Swimmers().getSwimTimes( vector <int>( distances, distances + ( sizeof distances / sizeof distances[0] ) ), vector <int>( speeds, speeds + ( sizeof speeds / sizeof speeds[0] ) ), current );
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
