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

class BadVocabulary {
public:
   int count( string badPrefix, string badSuffix, string badSubstring, vector <string> vocabulary ) 
   {
	   int Result = 0;
	   for ( int i = 0 ; i < vocabulary.size() ; i++ )
	   {
		   string s1 = "";
		   string s2 = "";
		   if ( vocabulary[i].length() >= badPrefix.length() )
		   {
			   string s ( vocabulary[i].begin() , vocabulary[i].begin() + badPrefix.length() );
			   s1 = s;
		   }
		   if ( vocabulary[i].length() >= badSuffix.length() )
		   {
			   string s ( vocabulary[i].end() - badSuffix.length() , vocabulary[i].end() );
			   s2= s;
		   }
		   if ( s1 == badPrefix || s2 == badSuffix )
		   {
			   Result++;
			   continue;
		   }
		   else
			   for ( int j = 1 ; j < (int)vocabulary[i].length() - (int)badSubstring.length() ; j++ )
			   {
				   string s3 ( vocabulary[i].begin() + j , vocabulary[i].begin() + j + badSubstring.length() );
				   if ( s3 == badSubstring )
				   {
					   Result++;
					   break;
				   }
			   }   
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
			string badPrefix          = "bug";
			string badSuffix          = "bug";
			string badSubstring       = "bug";
			string vocabulary[]       = {"buggy", "debugger", "debug"};
			int expected              = 3;

			clock_t moj_start_time    = clock();
			int received              = BadVocabulary().count( badPrefix, badSuffix, badSubstring, vector <string>( vocabulary, vocabulary + ( sizeof vocabulary / sizeof vocabulary[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			string badPrefix          = "a";
			string badSuffix          = "b";
			string badSubstring       = "c";
			string vocabulary[]       = {"a", "b", "tco"};
			int expected              = 3;

			clock_t moj_start_time    = clock();
			int received              = BadVocabulary().count( badPrefix, badSuffix, badSubstring, vector <string>( vocabulary, vocabulary + ( sizeof vocabulary / sizeof vocabulary[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			string badPrefix          = "cut";
			string badSuffix          = "sore";
			string badSubstring       = "scar";
			string vocabulary[]       = {"scary", "oscar"};
			int expected              = 0;

			clock_t moj_start_time    = clock();
			int received              = BadVocabulary().count( badPrefix, badSuffix, badSubstring, vector <string>( vocabulary, vocabulary + ( sizeof vocabulary / sizeof vocabulary[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			string badPrefix          = "bar";
			string badSuffix          = "else";
			string badSubstring       = "foo";
			string vocabulary[]       = {"foofoofoo", "foobar", "elsewhere"};
			int expected              = 1;

			clock_t moj_start_time    = clock();
			int received              = BadVocabulary().count( badPrefix, badSuffix, badSubstring, vector <string>( vocabulary, vocabulary + ( sizeof vocabulary / sizeof vocabulary[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			string badPrefix          = "pre";
			string badSuffix          = "s";
			string badSubstring       = "all";
			string vocabulary[]       = {"all", "coders", "be", "prepared", "for", "the", "challenge", "phase"};
			int expected              = 3;

			clock_t moj_start_time    = clock();
			int received              = BadVocabulary().count( badPrefix, badSuffix, badSubstring, vector <string>( vocabulary, vocabulary + ( sizeof vocabulary / sizeof vocabulary[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			string badPrefix          = ;
			string badSuffix          = ;
			string badSubstring       = ;
			string vocabulary[]       = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = BadVocabulary().count( badPrefix, badSuffix, badSubstring, vector <string>( vocabulary, vocabulary + ( sizeof vocabulary / sizeof vocabulary[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			string badPrefix          = ;
			string badSuffix          = ;
			string badSubstring       = ;
			string vocabulary[]       = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = BadVocabulary().count( badPrefix, badSuffix, badSubstring, vector <string>( vocabulary, vocabulary + ( sizeof vocabulary / sizeof vocabulary[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			string badPrefix          = ;
			string badSuffix          = ;
			string badSubstring       = ;
			string vocabulary[]       = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = BadVocabulary().count( badPrefix, badSuffix, badSubstring, vector <string>( vocabulary, vocabulary + ( sizeof vocabulary / sizeof vocabulary[0] ) ) );
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
