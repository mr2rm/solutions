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

class CardCount {
public:
   vector <string> dealHands( int numPlayers, string deck ) 
   {
	   vector <string> ANS ( numPlayers , "" );
	   int index , mod;
	   mod = deck.length() % numPlayers;
	   index = ( mod != 0 ? deck.length() - mod : deck.length() );
	   for ( int i = 0 ; i < index ; i++ )
		   ANS[ i % numPlayers ].push_back ( deck[i] );
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
	template<> ostream& operator<<( ostream &os, const vector<string> &v ) { os << "{"; for ( vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case( int casenum, const vector <string> &expected, const vector <string> &received, clock_t elapsed ) { 
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
			int numPlayers            = 6;
			string deck               = "012345012345012345";
			string expected[]         = { "000",  "111",  "222",  "333",  "444",  "555" };

			clock_t moj_start_time    = clock();
			vector <string> received  = CardCount().dealHands( numPlayers, deck );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 1: {
			int numPlayers            = 4;
			string deck               = "111122223333";
			string expected[]         = { "123",  "123",  "123",  "123" };

			clock_t moj_start_time    = clock();
			vector <string> received  = CardCount().dealHands( numPlayers, deck );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 2: {
			int numPlayers            = 1;
			string deck               = "012345012345012345";
			string expected[]         = { "012345012345012345" };

			clock_t moj_start_time    = clock();
			vector <string> received  = CardCount().dealHands( numPlayers, deck );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 3: {
			int numPlayers            = 6;
			string deck               = "01234";
			string expected[]         = { "",  "",  "",  "",  "",  "" };

			clock_t moj_start_time    = clock();
			vector <string> received  = CardCount().dealHands( numPlayers, deck );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 4: {
			int numPlayers            = 2;
			string deck               = "";
			string expected[]         = { "",  "" };

			clock_t moj_start_time    = clock();
			vector <string> received  = CardCount().dealHands( numPlayers, deck );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			int numPlayers            = ;
			string deck               = ;
			string expected[]         = ;

			clock_t moj_start_time    = clock();
			vector <string> received  = CardCount().dealHands( numPlayers, deck );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int numPlayers            = ;
			string deck               = ;
			string expected[]         = ;

			clock_t moj_start_time    = clock();
			vector <string> received  = CardCount().dealHands( numPlayers, deck );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}*/
/*      case 7: {
			int numPlayers            = ;
			string deck               = ;
			string expected[]         = ;

			clock_t moj_start_time    = clock();
			vector <string> received  = CardCount().dealHands( numPlayers, deck );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
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
