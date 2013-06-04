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
#include <sstream>

using namespace std;

class UserName {
public:
   string newMember( vector <string> existingNames, string newName ) 
   {
	   string Result = newName;
	   int Size = existingNames.size();
	   bool b = false;
	   for ( int i = 0 ; !b ; i++ )
	   {
		   if ( i != 0 )
		   {
			   stringstream ss;
			   ss << i;
			   Result = newName + ss.str();
		   }
		   int j = 0;
		   for ( ; j < Size && Result != existingNames[j] ; j++ );
		   if ( j == Size )	b = true;
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
			string existingNames[]    = {"MasterOfDisaster", "DingBat", "Orpheus", "WolfMan", "MrKnowItAll"};
			string newName            = "TygerTyger";
			string expected           = "TygerTyger";

			clock_t moj_start_time    = clock();
			string received           = UserName().newMember( vector <string>( existingNames, existingNames + ( sizeof existingNames / sizeof existingNames[0] ) ), newName );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			string existingNames[]    = {"MasterOfDisaster", "TygerTyger1", "DingBat", "Orpheus",   "TygerTyger", "WolfMan", "MrKnowItAll"};
			string newName            = "TygerTyger";
			string expected           = "TygerTyger2";

			clock_t moj_start_time    = clock();
			string received           = UserName().newMember( vector <string>( existingNames, existingNames + ( sizeof existingNames / sizeof existingNames[0] ) ), newName );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			string existingNames[]    = {"TygerTyger2000", "TygerTyger1", "MasterDisaster", "DingBat",   "Orpheus", "WolfMan", "MrKnowItAll"};
			string newName            = "TygerTyger";
			string expected           = "TygerTyger";

			clock_t moj_start_time    = clock();
			string received           = UserName().newMember( vector <string>( existingNames, existingNames + ( sizeof existingNames / sizeof existingNames[0] ) ), newName );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			string existingNames[]    = {"grokster2", "BrownEyedBoy", "Yoop", "BlueEyedGirl",   "grokster", "Elemental", "NightShade", "Grokster1"};
			string newName            = "grokster";
			string expected           = "grokster1";

			clock_t moj_start_time    = clock();
			string received           = UserName().newMember( vector <string>( existingNames, existingNames + ( sizeof existingNames / sizeof existingNames[0] ) ), newName );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			string existingNames[]    = {"Bart4", "Bart5", "Bart6", "Bart7", "Bart8", "Bart9", "Bart10",  "Lisa", "Marge", "Homer", "Bart", "Bart1", "Bart2", "Bart3",  "Bart11", "Bart12"};
			string newName            = "Bart";
			string expected           = "Bart13";

			clock_t moj_start_time    = clock();
			string received           = UserName().newMember( vector <string>( existingNames, existingNames + ( sizeof existingNames / sizeof existingNames[0] ) ), newName );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			string existingNames[]    = ;
			string newName            = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = UserName().newMember( vector <string>( existingNames, existingNames + ( sizeof existingNames / sizeof existingNames[0] ) ), newName );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			string existingNames[]    = ;
			string newName            = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = UserName().newMember( vector <string>( existingNames, existingNames + ( sizeof existingNames / sizeof existingNames[0] ) ), newName );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			string existingNames[]    = ;
			string newName            = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = UserName().newMember( vector <string>( existingNames, existingNames + ( sizeof existingNames / sizeof existingNames[0] ) ), newName );
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
