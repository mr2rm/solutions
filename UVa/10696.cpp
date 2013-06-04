#include <iostream>

using namespace std;

int f91 ( int t )
{
    if ( t >= 101 )
        return t-10;
    else
        f91 ( f91( t + 11 ) );
}

int main ()
{
    int n;
    while ( cin >> n && n != 0 )
        cout << "f91(" << n << ") = " << f91 ( n ) << endl;
    return 0;
}
