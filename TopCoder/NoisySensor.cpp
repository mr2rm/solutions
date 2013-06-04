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

class NoisySensor {
public:
   vector <int> medianFilter( vector <int> data )
   {
       int size = data.size();
       vector <int> v ( 3 );
       vector <int> Result ( size );
       Result[0] = data[0];
       Result[size-1] = data[size-1];
       for ( int i = 1 ; i < size - 1 ; i++ )
       {
           v[0] = data[i-1];    v[1] = data[i];    v[2] = data[i+1];
           sort ( v.begin() , v.end() );
           Result[i] = v[1];
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
			int data[]                = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			int expected[]            = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

			clock_t moj_start_time    = clock();
			vector <int> received     = NoisySensor().medianFilter( vector <int>( data, data + ( sizeof data / sizeof data[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 1: {
			int data[]                = {10, 1, 9, 2, 8};
			int expected[]            = {10, 9, 2, 8, 8 };

			clock_t moj_start_time    = clock();
			vector <int> received     = NoisySensor().medianFilter( vector <int>( data, data + ( sizeof data / sizeof data[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 2: {
			int data[]                = {500, 500, 500, 500, 500};
			int expected[]            = {500, 500, 500, 500, 500 };

			clock_t moj_start_time    = clock();
			vector <int> received     = NoisySensor().medianFilter( vector <int>( data, data + ( sizeof data / sizeof data[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 3: {
			int data[]                = {-2147483648, 2147483647};
			int expected[]            = {-2147483648, 2147483647 };

			clock_t moj_start_time    = clock();
			vector <int> received     = NoisySensor().medianFilter( vector <int>( data, data + ( sizeof data / sizeof data[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 4: {
			int data[]                = {432296535, 1983848899, -434724194, 135703525, -1146336142, -680568092, -1183352724, 1337550909, -1597342716, -1901441857, 1726722019, -558651015, 649930787, 1889036519, 1752815826, 930647381, -852547667, 2028345278, -1835531493, -1040566300, -1566043783, -1282411107, -1123988603, 2132078516, -1169614369, -523503536, 1466102514, -2003903121, -779001645, 1919742042, 1210980485, -9273881, 1033032137, -1474003783, 296280591, 920184999, -1235054743, -1329769514, -1727085135};
			int expected[]            = {432296535, 432296535, 135703525, -434724194, -680568092, -1146336142, -680568092, -1183352724, -1597342716, -1597342716, -558651015, 649930787, 649930787, 1752815826, 1752815826, 930647381, 930647381, -852547667, -1040566300, -1566043783, -1282411107, -1282411107, -1123988603, -1123988603, -523503536, -523503536, -523503536, -779001645, -779001645, 1210980485, 1210980485, 1033032137, -9273881, 296280591, 296280591, 296280591, -1235054743, -1329769514, -1727085135 };

			clock_t moj_start_time    = clock();
			vector <int> received     = NoisySensor().medianFilter( vector <int>( data, data + ( sizeof data / sizeof data[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			int data[]                = ;
			int expected[]            = ;

			clock_t moj_start_time    = clock();
			vector <int> received     = NoisySensor().medianFilter( vector <int>( data, data + ( sizeof data / sizeof data[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int data[]                = ;
			int expected[]            = ;

			clock_t moj_start_time    = clock();
			vector <int> received     = NoisySensor().medianFilter( vector <int>( data, data + ( sizeof data / sizeof data[0] ) ) );
			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}*/
/*      case 7: {
			int data[]                = ;
			int expected[]            = ;

			clock_t moj_start_time    = clock();
			vector <int> received     = NoisySensor().medianFilter( vector <int>( data, data + ( sizeof data / sizeof data[0] ) ) );
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
