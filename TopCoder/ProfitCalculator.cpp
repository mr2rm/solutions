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

class ProfitCalculator {
public:
   int percent( vector <string> items )
   {
   	   /*
   	   double price , cost , Res;
	   price = cost = 0;
	   for ( int i = 0 ; i < items.size() ; i++ )
	   {
		   stringstream ss ( items[i] );
		   ss >> Res;	price += Res;
		   ss >> Res;	cost += Res;
	   }
	   Res = ( price - cost ) / price;
	   Res *= 100;
	   return (int)Res;
   	   */

   	   /*
	   double Prices = 0 , Costs = 0 , temp;
	   for ( int i = 0 ; i < items.size() ; i++ )
	   {
		   string s1 ( items[i].begin() , items[i].begin() + 6 );
		   string s2 ( items[i].begin() + 7 , items[i].end() );
		   stringstream ss1 ( s1 );
		   stringstream ss2 ( s2 );
		   ss1 >> temp;
		   Prices += temp;
		   ss2 >> temp;
		   Costs += temp;
	   }
	   return ( ( Prices - Costs ) * 100 ) / Prices;
	   */
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
			string items[]            = {"012.99 008.73","099.99 050.00","123.45 101.07"};
			int expected              = 32;

			clock_t moj_start_time    = clock();
			int received              = ProfitCalculator().percent( vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			string items[]            = {"000.00 049.99","999.99 936.22","033.99 025.64","249.99 211.87"};
			int expected              = 4;

			clock_t moj_start_time    = clock();
			int received              = ProfitCalculator().percent( vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			string items[]            = {"822.77 704.86","829.42 355.45","887.18 949.38"};
			int expected              = 20;

			clock_t moj_start_time    = clock();
			int received              = ProfitCalculator().percent( vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			string items[]            = {"612.72 941.34","576.46 182.66","787.41 524.70","637.96 333.23","345.01 219.69",  "567.22 104.77","673.02 885.77"};
			int expected              = 23;

			clock_t moj_start_time    = clock();
			int received              = ProfitCalculator().percent( vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			string items[]            = {"811.22 275.32","433.89 006.48","141.28 967.41","344.47 786.23","897.47 860.61",  "007.42 559.29","255.72 460.00","419.35 931.19","419.25 490.52","199.78 114.44",  "505.63 276.58","720.96 735.00","719.90 824.46","816.58 195.94","498.68 453.05",  "399.48 921.39","930.88 017.63","422.20 075.39","380.22 917.27","630.83 995.87",  "821.07 126.87","715.73 985.62","246.23 134.64","168.28 550.33","707.28 046.72",  "117.76 281.87","595.43 410.45","345.28 532.42","554.24 264.34","195.73 814.87",  "131.98 041.28","595.13 939.47","576.04 107.70","716.00 404.75","524.24 029.96",  "673.49 070.97","288.09 849.43","616.34 236.34","401.96 316.33","371.18 014.27",  "809.63 508.33","375.68 290.84","334.66 477.89","689.54 526.35","084.77 316.51",  "304.76 015.91","460.63 636.56","357.84 436.20","752.24 047.64","922.10 573.12"};
			int expected              = 10;

			clock_t moj_start_time    = clock();
			int received              = ProfitCalculator().percent( vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			string items[]            = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = ProfitCalculator().percent( vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			string items[]            = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = ProfitCalculator().percent( vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			string items[]            = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = ProfitCalculator().percent( vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) );
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
