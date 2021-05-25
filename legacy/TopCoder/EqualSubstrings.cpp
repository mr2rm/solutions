#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <string>
#include <complex>

using namespace std;

class EqualSubstrings {
   public: vector <string> getSubstrings ( string str )
   {
       int a[60], b[60];
       int n = str.length();
       a[0] = b[0] = 0;
       if (str[0] == 'a')
            a[0]++;
       else if (str[0] == 'b')
            b[0]++;
       for (int I = 1; I < n; I++)
       {
           a[I] = a[I-1];
           b[I] = b[I-1];
           if (str[I] == 'a')
                a[I]++;
           else if (str[I] == 'b')
                b[I]++;
       }
       vector <string> v;
       v.push_back ("");
       v.push_back (str);
       for (int I = n-1; I >= 0; I--)
       {
           int numa, numb;
           numa = a[I];
           numb = b[n-1] - b[I];
           if (numa == numb)
            {
                v.clear();
                v.push_back (string(str.begin(), str.begin()+I+1));
                v.push_back (string(str.begin()+I+1, str.end()));
                break;
            }
       }
       return v;
   };
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
			string str                = "aaabbb";
			string expected[]         = { "aaa",  "bbb" };

			clock_t moj_start_time    = clock();
			vector <string> received  = EqualSubstrings().getSubstrings( str );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 1: {
			string str                = "bbbaaa";
			string expected[]         = { "bbb",  "aaa" };

			clock_t moj_start_time    = clock();
			vector <string> received  = EqualSubstrings().getSubstrings( str );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 2: {
			string str                = "bbbbbb";
			string expected[]         = { "bbbbbb",  "" };

			clock_t moj_start_time    = clock();
			vector <string> received  = EqualSubstrings().getSubstrings( str );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 3: {
			string str                = "aaaaaa";
			string expected[]         = { "",  "aaaaaa" };

			clock_t moj_start_time    = clock();
			vector <string> received  = EqualSubstrings().getSubstrings( str );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}
		case 4: {
			string str                = "abjlkbjalkbjaljsbljbalb";
			string expected[]         = { "abjlkbjalkbjaljs",  "bljbalb" };

			clock_t moj_start_time    = clock();
			vector <string> received  = EqualSubstrings().getSubstrings( str );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			string str                = ;
			string expected[]         = ;

			clock_t moj_start_time    = clock();
			vector <string> received  = EqualSubstrings().getSubstrings( str );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}*/
/*      case 6: {
			string str                = ;
			string expected[]         = ;

			clock_t moj_start_time    = clock();
			vector <string> received  = EqualSubstrings().getSubstrings( str );
			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), received, clock()-moj_start_time );
		}*/
/*      case 7: {
			string str                = ;
			string expected[]         = ;

			clock_t moj_start_time    = clock();
			vector <string> received  = EqualSubstrings().getSubstrings( str );
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
