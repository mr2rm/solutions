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

int mat[50][50];
int mark[50];
int n, Res, c, cc, sum;

void dfs (int x)
{
	mark[x] = 1;
	for (int i = 0; i < n; i++)
		if (mark[i] == 0 && mat[x][i] != 0)
		{
			sum += mat[x][i];
			Res = max (Res, sum);
			dfs (i);
			sum -= mat[x][i];
		}
	mark[x] = 0;
}

class Circuits {
public:
   int howLong( vector <string> connects, vector <string> costs ) 
   {
	   Res = 0;
	   n = connects.size();
	   for (int i = 0; i < n; i++)
		   memset (mat[i], 0, sizeof mat[i]);
	   memset (mark, 0, sizeof mark);
	   for (int i = 0; i < n; i++)
	   {
		   stringstream s1 (connects[i]);
		   stringstream s2 (costs[i]);
		   while (s1 >> c && s2 >> cc)	mat[i][c] = cc;
	   }
	   for (int i = 0; i < n; i++)
	   {
		   sum = 0;
		   dfs (i);
	   }
	   return Res;
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
			string connects[]         = {"1 2",  "2",  ""};
			string costs[]            = {"5 3",  "7",  ""};
			int expected              = 12;

			clock_t moj_start_time    = clock();
			int received              = Circuits().howLong( vector <string>( connects, connects + ( sizeof connects / sizeof connects[0] ) ), vector <string>( costs, costs + ( sizeof costs / sizeof costs[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			string connects[]         = {"1 2 3 4 5","2 3 4 5","3 4 5","4 5","5",""};
			string costs[]            = {"2 2 2 2 2","2 2 2 2","2 2 2","2 2","2",""};
			int expected              = 10;

			clock_t moj_start_time    = clock();
			int received              = Circuits().howLong( vector <string>( connects, connects + ( sizeof connects / sizeof connects[0] ) ), vector <string>( costs, costs + ( sizeof costs / sizeof costs[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			string connects[]         = {"1","2","3","","5","6","7",""};
			string costs[]            = {"2","2","2","","3","3","3",""};
			int expected              = 9;

			clock_t moj_start_time    = clock();
			int received              = Circuits().howLong( vector <string>( connects, connects + ( sizeof connects / sizeof connects[0] ) ), vector <string>( costs, costs + ( sizeof costs / sizeof costs[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			string connects[]         = {"","2 3 5","4 5","5 6","7","7 8","8 9","10",  "10 11 12","11","12","12",""};
			string costs[]            = {"","3 2 9","2 4","6 9","3","1 2","1 2","5",  "5 6 9","2","5","3",""};
			int expected              = 22;

			clock_t moj_start_time    = clock();
			int received              = Circuits().howLong( vector <string>( connects, connects + ( sizeof connects / sizeof connects[0] ) ), vector <string>( costs, costs + ( sizeof costs / sizeof costs[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			string connects[]         = {"","2 3","3 4 5","4 6","5 6","7","5 7",""};
			string costs[]            = {"","30 50","19 6 40","12 10","35 23","8","11 20",""};
			int expected              = 105;

			clock_t moj_start_time    = clock();
			int received              = Circuits().howLong( vector <string>( connects, connects + ( sizeof connects / sizeof connects[0] ) ), vector <string>( costs, costs + ( sizeof costs / sizeof costs[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			string connects[]         = ;
			string costs[]            = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Circuits().howLong( vector <string>( connects, connects + ( sizeof connects / sizeof connects[0] ) ), vector <string>( costs, costs + ( sizeof costs / sizeof costs[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			string connects[]         = ;
			string costs[]            = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Circuits().howLong( vector <string>( connects, connects + ( sizeof connects / sizeof connects[0] ) ), vector <string>( costs, costs + ( sizeof costs / sizeof costs[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			string connects[]         = ;
			string costs[]            = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Circuits().howLong( vector <string>( connects, connects + ( sizeof connects / sizeof connects[0] ) ), vector <string>( costs, costs + ( sizeof costs / sizeof costs[0] ) ) );
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
