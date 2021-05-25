#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int t, n, x, y, sz;
    string str;
    vector <int> v (1000000);
    //char ch;
    //bool b;
    //string s1, s2;
    t = 0;
    while (cin >> str >> n)
    {
        t++;
        sz = str.length();
        cout << "Case " << t << ":" << endl;
        v[0] = 0;
        for (int i = 1; i < sz; i++)
            if (str[i] == str[i-1])
                v[i] = v[i-1];
            else
                v[i] = i;
        for (int i = 0; i < n && cin >> x >> y; i++)
        {
            if (x > y)
                swap(x, y);

            if (x >= v[y])
                cout << "Yes" << endl;
            else
                cout << "No" << endl;

            /*//2 ---> TLE
            s1 = string (y-x+1, str[x]);
            s2 = string (str.begin()+x, str.begin()+y+1);
            if (s1 != s2)
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
            */

            /*//1 ---> TLE
            ch = str[x];
            b = true;
            for (int j = x + 1; b && j <= y; j++)
                if (str[j] != ch)
                    b = false;
            if (b)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
            */
        }
    }
    return 0;
}

/*
int main ()
{
	string str , s;
	int n , i1 , i2;
	bool bl;
	int a , b;
	int c = 0;
	while ( getline ( cin , str ) && str != "" )
	{
		c++;
		cin >> n ;
		cout << "Case " << c << ":" << endl;
		for ( int i = 0 ; i < n ; i++ )
		{
			cin >> i1 >> i2;
			a = min ( i1 , i2 );
			b = max ( i1 , i2 );
			bl = true;
			for ( int j = a + 1 ; j <= b ; j++ )
				if ( str[j] != str[a] )
				{
					bl = false;
					break;
				}
			if ( bl == true )
				cout << "Yes" << endl;
			else 
				cout << "No" << endl;
		}
		getline ( cin , s );
	}
	return 0;
}
*/

/*int main ()
{
	string str , s;
	int 
	int i1 , i2 , n;
	int c = 0;
	while ( getline ( cin , str ) && str != "" )
	{
		cin >> n;
		for ( int i = 0 ; i < str.length() ; i++ )
			
		getline ( cin , str );
	}
	return 0;
}*/