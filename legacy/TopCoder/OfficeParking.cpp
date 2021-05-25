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

class OfficeParking {
public:
   int spacesUsed( vector <string> events ) 
   {
	   vector <char> Stack;
	   int index , Result = 0 , size;
	   for ( int i = 0 ; i < events.size() ; i++ )
	   {
		   for ( index = 0 ; events[i][index] != ' ' ; index++ );
		   index++;
		   if ( events[i][index] == 'a' )
		   {
			   Stack.push_back ( 'a' );
			   size = Stack.size();
			   Result = max ( Result , size );
		   }
		   else
			   Stack.pop_back();
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
			string events[]           = {"Alice arrives","bob arrives","Alice departs",  "Charles arrives","bob departs","Charles departs"};
			int expected              = 2;

			clock_t moj_start_time    = clock();
			int received              = OfficeParking().spacesUsed( vector <string>( events, events + ( sizeof events / sizeof events[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			string events[]           = {"AdminBrett arrives","lbackstrom arrives","AdminBrett departs","mike arrives",  "TheFaxman arrives","AdminBrett arrives","lbackstrom departs","dok arrives",  "AdminBrett departs","gt arrives","AdminBrett arrives","lbackstrom arrives",  "AdminBrett departs","jhughes arrives","jhughes departs","TheFaxman departs",  "MaryJoe arrives","AdminBrett arrives","AdminBrett departs","AdminBrett arrives"};
			int expected              = 6;

			clock_t moj_start_time    = clock();
			int received              = OfficeParking().spacesUsed( vector <string>( events, events + ( sizeof events / sizeof events[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			string events[]           = {"SnapDragon arrives","tomek arrives","JohnDethridge arrives","ZorbaTHut arrives",  "snewman arrives","reid arrives","NGBronson arrives","Yarin arrives",  "bstanescu arrives","mathijs arrives","radeye arrives","bladerunner arrives",  "dgarthur arrives","venco arrives","dmwright arrives","WishingBone arrives",  "Eryx arrives","antimatter arrives","ChristopherH arrives","lars arrives",  "biggnate arrives","JanKuipers arrives","dary arrives","haha arrives","grotmol arrives",  "XuChuan arrives","Ryan arrives","LunaticFrindge arrives","Wasteland arrives",  "RunningWild arrives","hampster arrives","RalphFurmaniak arrives",  "kyky arrives","qubits arrives","Rustyoldman arrives","turuthok arrives",  "Vulpecular arrives","Eeyore arrives","wackes arrives","Ishan arrives",  "dimkadimon arrives","dplass arrives","Olorin arrives","TangentZ arrives",  "NeverMore arrives","Pops arrives","srowan arrives","tjq arrives",  "vorthys arrives","schveiguy arrives"};
			int expected              = 50;

			clock_t moj_start_time    = clock();
			int received              = OfficeParking().spacesUsed( vector <string>( events, events + ( sizeof events / sizeof events[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			string events[]           = {"AdminBrett arrives","AdminBrett departs","AdminBrett arrives","AdminBrett departs",  "AdminBrett arrives","AdminBrett departs","AdminBrett arrives","AdminBrett departs",  "AdminBrett arrives","AdminBrett departs","AdminBrett arrives","AdminBrett departs",  "AdminBrett arrives","AdminBrett departs","AdminBrett arrives","AdminBrett departs"} ;
			int expected              = 1;

			clock_t moj_start_time    = clock();
			int received              = OfficeParking().spacesUsed( vector <string>( events, events + ( sizeof events / sizeof events[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			string events[]           = {"snapdragon arrives","SnapDragon arrives",  "AdminBrett arrives","AdminBrett departs",  "SnapDragon departs","snapdragon departs"};
			int expected              = 3;

			clock_t moj_start_time    = clock();
			int received              = OfficeParking().spacesUsed( vector <string>( events, events + ( sizeof events / sizeof events[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 5: {
			string events[]           = {"departs arrives","arrives arrives","arrives departs","departs departs"};
			int expected              = 2;

			clock_t moj_start_time    = clock();
			int received              = OfficeParking().spacesUsed( vector <string>( events, events + ( sizeof events / sizeof events[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 6: {
			string events[]           = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = OfficeParking().spacesUsed( vector <string>( events, events + ( sizeof events / sizeof events[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			string events[]           = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = OfficeParking().spacesUsed( vector <string>( events, events + ( sizeof events / sizeof events[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 8: {
			string events[]           = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = OfficeParking().spacesUsed( vector <string>( events, events + ( sizeof events / sizeof events[0] ) ) );
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
