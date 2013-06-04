#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main ()
{

    //TLE
    /*
    int t , n , m , result , tempres;
    cin >> t;
    for ( int i = 0 ; i < t && cin >> n ; i++ )
    {
        vector <int> v ( n );
        m = 0;
        for ( int j = 0 ; j < n && cin >> v[j] ; j++ )
            if ( v[j] > m )
                m = v[j];
        result = 460000000;
        for ( int j = 1 ; j <= m ; j++ )
        {
            tempres = 0;
            for ( int k = 0 ; k < n ; k++ )
                tempres += fabs ( v[k] - j );
            result = min ( tempres , result );
        }
        cout << result << endl;
    */

    int t , n , in , home , Result , tempres;
    cin >> t;
    for ( int i = 0 ; i < t && cin >> n ; i++ )
    {
        vector <int> v ( n );
        for ( int j = 0 ; j < n && cin >> v[j] ; j++ );
        sort ( v.begin() , v.end() );
        in = v.size()/2;
        home = v[in];
        Result = -1;
        if ( v.size() % 2 == 0 )
        {
            double d = ( home + v[in-1] ) / 2;
            if ( d == (int)d )
                home = d;
            else
            {
                tempres = 0;
                for ( int j = 0 ; j < n ; j++ )
                    tempres += fabs ( v[j] - home );
                Result = tempres;
                home = v[in-1];
            }
        }
        tempres = 0;
        for ( int j = 0 ; j < n ; j++ )
            tempres += fabs ( v[j] - home );
        if ( Result == -1 ) Result = tempres;
        else    Result = min ( Result , tempres );
        cout << Result << endl;
    }

    return 0;
}
