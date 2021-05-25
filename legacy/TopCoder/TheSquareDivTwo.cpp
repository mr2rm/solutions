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

class TheSquareDivTwo {
public:
   vector <string> solve( vector <string> board )
   {
	   //WA
	   /*
	   vector <int> NumCol ( board.size() , 0 );
	   vector <int> NumRow ( board.size() , 0 );
	   for ( int i = 0 ; i < board.size() ; i++ )
		   for ( int j = 0 ; j < board.size() ; j++ )
			   if ( board[i][j] == 'C' )
			   {
				   NumCol[j]++;
                   NumRow[i]++;
               }

       for ( int j = 0 ; j < board.size() - 1 ; j++ )
	   {
		   while ( NumCol[j] != NumRow[j] )
		   for ( int i = 0 ; NumCol[j] > NumRow[j] && i < board.size() ; i++ )
			   if ( board[i][j] == 'C' )
				   for ( int k = 1 ; k > -2 ; k-- )
					   if ( i+k >= 0 && i+k < board.size() && board[i+k][j+1] == '.' )
					   {
						   swap ( board[i][j] , board[i+k][j+1] );
						   NumCol[j+1]++;
						   NumCol[j]--;
						   break;
					   }

		   for ( int i = board.size() - 1 ; NumCol[j] < NumRow[j] && i >= 0 ; i-- )
			   if ( board[i][j] == '.' )
				   for ( int k = -1 ; k < 2 ; k++ )
					   if ( i+k >= 0 && i+k < board.size() && board[i+k][j+1] == 'C' )
					   {
						   swap ( board[i][j] , board[i+k][j+1] );
						   NumCol[j+1]--;
						   NumCol[j]++;
						   break;
					   }
	   }

	   return board;
	   */
	   vector <int> NumRow ( board.size() , 0 );
	   for ( int i = 0 ; i < board.size() ; i++ )
		   for ( int j = 0 ; j < board.size() ; j++ )
			   if ( board[i][j] == 'C' )
				   NumRow[i]++;
	   string str ( board.size() , '.' );
	   vector <string> Result ( board.size() , str );
	   for ( int j = board.size() - 1 ; j >= 0 ; j-- )
		   for ( int i = board.size() - 1 ; NumRow[j] > 0 ; i-- , NumRow[j]-- )
			   Result[i][j] = 'C';
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
			string board[]            = {"..",  "C."};
			string expected[]         = {"..", ".C" };

			clock_t moj_start_time    = clock();
			vector <string> received  = TheSquareDivTwo().solve( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 1: {
			string board[]            = {"CC",  ".C"};
			string expected[]         = {"C.", "CC" };

			clock_t moj_start_time    = clock();
			vector <string> received  = TheSquareDivTwo().solve( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 2: {
			string board[]            = {".C..",  "CC.C",  "..C.",  "CCCC"};
			string expected[]         = {"...C", ".C.C", ".C.C", "CCCC" };

			clock_t moj_start_time    = clock();
			vector <string> received  = TheSquareDivTwo().solve( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 3: {
			string board[]            = {"...CCC",  "...CCC",  "...CCC",  "CCC...",  "CCC...",  "CCC..."};
			string expected[]         = {"......", "......", "......", "CCCCCC", "CCCCCC", "CCCCCC" };

			clock_t moj_start_time    = clock();
			vector <string> received  = TheSquareDivTwo().solve( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 4: {
			string board[]            = {".....C",  "....CC",  "...CCC",  "..CCCC",  ".CCCCC",  "CCCCCC"};
			string expected[]         = {".....C", "....CC", "...CCC", "..CCCC", ".CCCCC", "CCCCCC" };

			clock_t moj_start_time    = clock();
			vector <string> received  = TheSquareDivTwo().solve( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 5: {
			string board[]            = {"C.C..C.C..C..C.",  "CCC...C..CCC.C.",  "......CC...CCCC",  ".C..CC.C.C.C.C.",  "C....C.C......C",  ".....C..CCCCC.C",  "CCC.......CCCCC",  "..C.C..C.C...C.",  "CCC....CCC.CC..",  "CC.CCCC.CCCC...",  ".C..C.CC.C.CC.C",  "C.CCCC..CC..C.C",  ".CCCC.CCCCCC...",  "..C...C.CCC.CC.",  "CCCC..CCC.C...."};
			string expected[]         = {"...............", "...............", "...............", "...............", "...............", ".........C..C..", ".........C.CC..", ".C....C.CCCCC.C", ".C.C.CC.CCCCCCC", "CCCC.CC.CCCCCCC", "CCCC.CCCCCCCCCC", "CCCCCCCCCCCCCCC", "CCCCCCCCCCCCCCC", "CCCCCCCCCCCCCCC", "CCCCCCCCCCCCCCC" };

			clock_t moj_start_time    = clock();
			vector <string> received  = TheSquareDivTwo().solve( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}

		// custom cases

/*      case 6: {
			string board[]            = ;
			string expected[]         = ;

			clock_t moj_start_time    = clock();
			vector <string> received  = TheSquareDivTwo().solve( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}*/
/*      case 7: {
			string board[]            = ;
			string expected[]         = ;

			clock_t moj_start_time    = clock();
			vector <string> received  = TheSquareDivTwo().solve( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}*/
/*      case 8: {
			string board[]            = ;
			string expected[]         = ;

			clock_t moj_start_time    = clock();
			vector <string> received  = TheSquareDivTwo().solve( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) );
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
