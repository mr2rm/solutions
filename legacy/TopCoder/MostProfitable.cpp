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

class MostProfitable {
public:
   string bestItem( vector <int> costs, vector <int> prices, vector <int> sales, vector <string> items ) 
   {
   	   /*
   	   int size = costs.size();
	   int Profit , MostProf;
	   MostProf = 0;
	   string Res ( "" );
	   for ( int i = 0 ; i < size ; i++ )
	   {
		   Profit = sales[i] * ( prices[i] - costs[i] );
		   if ( Profit > MostProf )
		   {
			   MostProf = Profit;
			   Res = items[i];
		   }
	   }
	   return Res;
	   */

   	   /*
	   vector <int> profits ( items.size() );
	   int index;
	   int maxi = 0;
	   for ( int i = 0 ; i < items.size() ; i++ )
	   {
		   profits[i] = ( prices[i] - costs[i] ) * sales[i];
		   if ( profits[i] > maxi )
		   {
			   index = i;
			   maxi = profits[i];
		   }
	   }
	   if ( maxi <= 0 )
		   return "";
	   else
		   return items[index];
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
	
	int verify_case( int casenum, const string &expected, const string &received, clock_t elapsed ) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			int costs[]               = {100,120,150,1000};
			int prices[]              = {110,110,200,2000};
			int sales[]               = {20,100,50,3};
			string items[]            = {"Video Card","256M Mem","CPU/Mobo combo","Complete machine"};
			string expected           = "Complete machine";

			clock_t moj_start_time    = clock();
			string received           = MostProfitable().bestItem( vector <int>( costs, costs + ( sizeof costs / sizeof costs[0] ) ), vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <int>( sales, sales + ( sizeof sales / sizeof sales[0] ) ), vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int costs[]               = {100};
			int prices[]              = {100};
			int sales[]               = {134};
			string items[]            = {"Service, at cost"};
			string expected           = "";

			clock_t moj_start_time    = clock();
			string received           = MostProfitable().bestItem( vector <int>( costs, costs + ( sizeof costs / sizeof costs[0] ) ), vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <int>( sales, sales + ( sizeof sales / sizeof sales[0] ) ), vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int costs[]               = {38,24};
			int prices[]              = {37,23};
			int sales[]               = {1000,643};
			string items[]            = {"Letter","Postcard"};
			string expected           = "";

			clock_t moj_start_time    = clock();
			string received           = MostProfitable().bestItem( vector <int>( costs, costs + ( sizeof costs / sizeof costs[0] ) ), vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <int>( sales, sales + ( sizeof sales / sizeof sales[0] ) ), vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			int costs[]               = {10,10};
			int prices[]              = {11,12};
			int sales[]               = {2,1};
			string items[]            = {"A","B"};
			string expected           = "A";

			clock_t moj_start_time    = clock();
			string received           = MostProfitable().bestItem( vector <int>( costs, costs + ( sizeof costs / sizeof costs[0] ) ), vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <int>( sales, sales + ( sizeof sales / sizeof sales[0] ) ), vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 4: {
			int costs[]               = ;
			int prices[]              = ;
			int sales[]               = ;
			string items[]            = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = MostProfitable().bestItem( vector <int>( costs, costs + ( sizeof costs / sizeof costs[0] ) ), vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <int>( sales, sales + ( sizeof sales / sizeof sales[0] ) ), vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 5: {
			int costs[]               = ;
			int prices[]              = ;
			int sales[]               = ;
			string items[]            = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = MostProfitable().bestItem( vector <int>( costs, costs + ( sizeof costs / sizeof costs[0] ) ), vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <int>( sales, sales + ( sizeof sales / sizeof sales[0] ) ), vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int costs[]               = ;
			int prices[]              = ;
			int sales[]               = ;
			string items[]            = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = MostProfitable().bestItem( vector <int>( costs, costs + ( sizeof costs / sizeof costs[0] ) ), vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <int>( sales, sales + ( sizeof sales / sizeof sales[0] ) ), vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) );
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
