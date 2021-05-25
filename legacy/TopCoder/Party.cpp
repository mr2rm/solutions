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

class Party {
public:
   double averageNames( int n, vector <int> personA, vector <int> personB ) 
   {
	   /*
	   vector < set <int> > vs ( n , set <int> () );
	   for ( int i = 0 ; i < personA.size() ; i++ )
	   {
		   vs[personA[i]].insert ( personB[i] );
		   vs[personB[i]].insert ( personA[i] );
		   for ( set<int>::iterator it = vs[personA[i]].begin() ; it != vs[personA[i]].end() ; it++ )
			   if ( *it != personB[i] )
				   vs[personB[i]].insert ( *it );
		   for ( set<int>::iterator it = vs[personB[i]].begin() ; it != vs[personB[i]].end() ; it++ )
			   if ( *it != personA[i] )
				   vs[personA[i]].insert ( *it );
	   }
	   int sum = 0;
	   for ( int i = 0 ; i < n ; i++ )
		   sum += vs[i].size();
	   return (double)sum / n;
	   */
	   bool v[100][100] = { false };
	   int sum = 0;
	   for ( int i = 0 ; i < personA.size() ; i++ )
	   {
		   v[personA[i]][personB[i]] = true;
		   v[personB[i]][personA[i]] = true;
		   for ( int j = 0 ; j < n ; j++ )
		   {
			   v[personA[i]][j] |= v[personB[i]][j];
			   v[personB[i]][j] = v[personA[i]][j];
		   }
	   }
	   for ( int i = 0 ; i < n ; i++ )
	   {
		   int temp = 0;
		   for ( int j = 0 ; j < n ; j++ )
			   if ( i != j && v[i][j] )
				   temp++;
		   sum += temp;
	   }
	   return (double)sum / n;
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
			int n                     = 4;
			int personA[]             = {0,1,2};
			int personB[]             = {1,2,3};
			double expected           = 2.25;

			clock_t moj_start_time    = clock();
			double received           = Party().averageNames( n, vector <int>( personA, personA + ( sizeof personA / sizeof personA[0] ) ), vector <int>( personB, personB + ( sizeof personB / sizeof personB[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int n                     = 5;
			int personA[]             = {0,0,0,0,0,0,0};
			int personB[]             = {1,2,3,4,3,2,1};
			double expected           = 4.0;

			clock_t moj_start_time    = clock();
			double received           = Party().averageNames( n, vector <int>( personA, personA + ( sizeof personA / sizeof personA[0] ) ), vector <int>( personB, personB + ( sizeof personB / sizeof personB[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int n                     = 100;
			int personA[]             = {52,19,52,19};
			int personB[]             = {19,52,19,52};
			double expected           = 0.02;

			clock_t moj_start_time    = clock();
			double received           = Party().averageNames( n, vector <int>( personA, personA + ( sizeof personA / sizeof personA[0] ) ), vector <int>( personB, personB + ( sizeof personB / sizeof personB[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			int n                     = 25;
			int personA[]             = {14, 14, 16, 4, 14, 16, 2, 16, 8, 15, 17, 17, 3, 3, 19, 17, 20, 4, 24, 8};
			int personB[]             = {16, 2, 23, 16, 11, 8, 5, 19, 15, 20, 19, 18, 14, 12, 22, 9, 0, 7, 23, 10};
			double expected           = 4.44;

			clock_t moj_start_time    = clock();
			double received           = Party().averageNames( n, vector <int>( personA, personA + ( sizeof personA / sizeof personA[0] ) ), vector <int>( personB, personB + ( sizeof personB / sizeof personB[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 4: {
			int n                     = ;
			int personA[]             = ;
			int personB[]             = ;
			double expected           = ;

			clock_t moj_start_time    = clock();
			double received           = Party().averageNames( n, vector <int>( personA, personA + ( sizeof personA / sizeof personA[0] ) ), vector <int>( personB, personB + ( sizeof personB / sizeof personB[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 5: {
			int n                     = ;
			int personA[]             = ;
			int personB[]             = ;
			double expected           = ;

			clock_t moj_start_time    = clock();
			double received           = Party().averageNames( n, vector <int>( personA, personA + ( sizeof personA / sizeof personA[0] ) ), vector <int>( personB, personB + ( sizeof personB / sizeof personB[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int n                     = ;
			int personA[]             = ;
			int personB[]             = ;
			double expected           = ;

			clock_t moj_start_time    = clock();
			double received           = Party().averageNames( n, vector <int>( personA, personA + ( sizeof personA / sizeof personA[0] ) ), vector <int>( personB, personB + ( sizeof personB / sizeof personB[0] ) ) );
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
