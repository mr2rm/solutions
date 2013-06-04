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

class PaperRockScisQuals {
public:
   int whoPassed( vector <string> players ) 
   {
	   vector <double> scores ( players.size() , 0 );
	   for ( int i = 0 ; i < players.size() ; i++ )
	   {
		   for ( int j = i + 1 ; j < players.size() ; j++ )
		   {
			   int throws[2] = { 0 };
			   for ( int k = 0 ; k < 5 ; k++ )
			   {
				   if ( players[i][k] != players[j][k] )
				   {
					   string str;
					   str.push_back ( players[i][k] );	
					   str.push_back ( players[j][k] );
					   if ( str == "SP" || str == "PR" || str == "RS" )
						   throws[0]++;
					   else
						   throws[1]++;
				   }
			   }
			   if ( throws[0] == throws[1] )
			   {
				   scores[i] += 0.5;
				   scores[j] += 0.5;
			   }
			   else if ( throws[0] > throws[1] )
				   scores[i]++;
			   else
				   scores[j]++;
		   }
	   }
	   vector <double> v ( scores.begin() , scores.end() );
	   sort ( v.begin() , v.end() );
	   for ( int i = 0 ; i < scores.size() ; i++ )
		   if ( scores[i] == v[v.size()-1] )
			   return i;
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
			string players[]          = {"PPRRS","PPRRP","PPRSP","PPSSP"};
			int expected              = 0;

			clock_t moj_start_time    = clock();
			int received              = PaperRockScisQuals().whoPassed( vector <string>( players, players + ( sizeof players / sizeof players[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			string players[]          = {"RRRRR","PPPPP","RRRRR","PPPPP"};
			int expected              = 1;

			clock_t moj_start_time    = clock();
			int received              = PaperRockScisQuals().whoPassed( vector <string>( players, players + ( sizeof players / sizeof players[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			string players[]          = {"RRRRR","PPPPP","SSSSS","PPPPP"};
			int expected              = 2;

			clock_t moj_start_time    = clock();
			int received              = PaperRockScisQuals().whoPassed( vector <string>( players, players + ( sizeof players / sizeof players[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			string players[]          = {"RRRRR","PPPPP","SSSSS","SSSSS","RRRRR","RRRRR"};
			int expected              = 0;

			clock_t moj_start_time    = clock();
			int received              = PaperRockScisQuals().whoPassed( vector <string>( players, players + ( sizeof players / sizeof players[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			string players[]          = {"PPRPS","RRRPR","SSPRS","SSPRR","PPRSP","SPRPS","SPRSP","PRSPR","PRSPR"};
			int expected              = 6;

			clock_t moj_start_time    = clock();
			int received              = PaperRockScisQuals().whoPassed( vector <string>( players, players + ( sizeof players / sizeof players[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			string players[]          = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = PaperRockScisQuals().whoPassed( vector <string>( players, players + ( sizeof players / sizeof players[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			string players[]          = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = PaperRockScisQuals().whoPassed( vector <string>( players, players + ( sizeof players / sizeof players[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			string players[]          = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = PaperRockScisQuals().whoPassed( vector <string>( players, players + ( sizeof players / sizeof players[0] ) ) );
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
