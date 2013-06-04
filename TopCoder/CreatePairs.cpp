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

class CreatePairs {
public:
   int maximalSum( vector <int> data ) 
   {
	   /*(1)
	   int i , sub , msum;	
	   sort ( data.begin() , data.end() );
	   msum = 0;
	   for ( i = 0 ; i < data.size() && data[i] < 0 ; i += 2 )
	   {
		   if 	( data.size() == 1 )
			   msum += data[i];
		   else 
		   {
			   sub = data[i] * data[i+1];
			   if ( sub >= 0 )
				   msum += sub;
			   else
			   {
				   msum += data[i];
				   i--;
			   }
		   }
	   }
	   for ( int j = data.size() - 1 ; j >= 0 && j >= i ; j -= 2 )
	   {
		   if ( j == 0 )
			   msum += data[j];
		   else
		   {
			   sub = data[j] * data[j-1];
			   if ( sub <= 0 || data[j-1] == 1 )
			   {
				   msum += data[j];
				   j++;
			   }
			   else
				   msum += sub;
		   }
	   }
	   return msum;*/

	   /*(2)
	   int maxi = 0 , index;
	   sort ( data.begin() , data.end() );
	   for ( index = 0 ; index < data.size() && data[index] <= 0 ; index++ );
	   vector <int> neg ( data.begin() , data.begin() + index );
	   vector <int> pos ( data.begin() + index , data.end() );
	   reverse ( pos.begin() , pos.end() );
	   for ( int i = 0 ; i < neg.size() ; i += 2 )
		   maxi += ( i + 1 < neg.size() ? neg[i]*neg[i+1] : neg[i] );
	   for ( int i = 0 ; i < pos.size() ; i += 2 )
	   {
		   if ( i + 1 < pos.size() )
			   maxi += ( ( pos[i] == 1 || pos[i+1] == 1 ) ? pos[i] + pos[i+1] : pos[i] * pos[i+1] );
		   else
			   maxi += pos[i];
	   }
	   return  maxi;*/
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
			int data[]                = {0, 1, 2, 4, 3, 5};
			int expected              = 27;

			clock_t moj_start_time    = clock();
			int received              = CreatePairs().maximalSum( vector <int>( data, data + ( sizeof data / sizeof data[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int data[]                = {-1, 1, 2, 3};
			int expected              = 6;

			clock_t moj_start_time    = clock();
			int received              = CreatePairs().maximalSum( vector <int>( data, data + ( sizeof data / sizeof data[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int data[]                = {-1};
			int expected              = -1;

			clock_t moj_start_time    = clock();
			int received              = CreatePairs().maximalSum( vector <int>( data, data + ( sizeof data / sizeof data[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			int data[]                = {-1, 0, 1};
			int expected              = 1;

			clock_t moj_start_time    = clock();
			int received              = CreatePairs().maximalSum( vector <int>( data, data + ( sizeof data / sizeof data[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			int data[]                = {1, 1};
			int expected              = 2;

			clock_t moj_start_time    = clock();
			int received              = CreatePairs().maximalSum( vector <int>( data, data + ( sizeof data / sizeof data[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			int data[]                = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = CreatePairs().maximalSum( vector <int>( data, data + ( sizeof data / sizeof data[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int data[]                = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = CreatePairs().maximalSum( vector <int>( data, data + ( sizeof data / sizeof data[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			int data[]                = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = CreatePairs().maximalSum( vector <int>( data, data + ( sizeof data / sizeof data[0] ) ) );
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
