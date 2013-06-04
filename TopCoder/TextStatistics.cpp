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

#define IF(x) ( ( text[x] >= 'a' && text[x] <= 'z' ) || ( text[x] >= 'A' && text[x] <= 'Z' ) )
#define e( x , y) fabs( x - y ) <= 1E-9

class TextStatistics {
public:
   double averageLength( string text )
   {
	   int word = 0 , alpha = 0;
	   
	   /*(1)
	   int sum = 0;
	   for ( int i = 0 ; i < text.length() ; i++ )
	   {
		   if ( IF(i) )	
			   sum++;
		   if ( sum != 0 && ( ! IF(i) || i == text.length() - 1 ) )
		   {
			   alpha += sum;
			   word++;
			   sum = 0;
		   }
	   }*/

	   /*(2)
	   for ( int i = 0 ; i < text.length() ; i++ )
	   {
		   int j , sum = 0;
		   for ( j = i ; j < text.length() && IF(j) ; j++ )
				   sum++;
		   if ( sum != 0 )
		   {
			   alpha += sum;
			   word++;
		   }
		   i = j;
	   }*/

	   double ANS = ( word == 0 ? 0 : (double) alpha / word );
	   if ( e( ANS , (int) ANS ) )
		   ANS = (int) ANS;
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
	
	bool isinf(const double x) { return !_finite(x); }
	bool isnan(const double x) { return _isnan(x); }
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ( double expected, double result ) { if ( isnan( expected ) ) { return isnan( result ); } else if ( isinf( expected ) ) { if ( expected > 0 ) { return result > 0 && isinf( result ); } else { return result < 0 && isinf( result ); } } else if ( isnan( result ) || isinf( result ) ) { return false; } else if ( fabs( result - expected ) < MAX_DOUBLE_ERROR ) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error( double expected, double result ) { if ( isnan( expected ) || isinf( expected ) || isnan( result ) || isinf( result ) || expected == 0 ) return 0; return fabs( result-expected ) / fabs( expected ); }
	
	int verify_case( int casenum, const double &expected, const double &received, clock_t elapsed ) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if ( topcoder_fequ( expected, received ) ) {
			verdict = "PASSED";
			double rerr = moj_relative_error( expected, received ); 
			if ( rerr > 0 ) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			string text               = "This is div2 easy problem.";
			double expected           = 4.0;

			clock_t moj_start_time    = clock();
			double received           = TextStatistics().averageLength( text );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			string text               = "Hello, world!";
			double expected           = 5.0;

			clock_t moj_start_time    = clock();
			double received           = TextStatistics().averageLength( text );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			string text               = "Simple";
			double expected           = 6.0;

			clock_t moj_start_time    = clock();
			double received           = TextStatistics().averageLength( text );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			string text               = "";
			double expected           = 0.0;

			clock_t moj_start_time    = clock();
			double received           = TextStatistics().averageLength( text );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			string text               = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
			double expected           = 50.0;

			clock_t moj_start_time    = clock();
			double received           = TextStatistics().averageLength( text );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			string text               = ;
			double expected           = ;

			clock_t moj_start_time    = clock();
			double received           = TextStatistics().averageLength( text );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			string text               = ;
			double expected           = ;

			clock_t moj_start_time    = clock();
			double received           = TextStatistics().averageLength( text );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			string text               = ;
			double expected           = ;

			clock_t moj_start_time    = clock();
			double received           = TextStatistics().averageLength( text );
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
