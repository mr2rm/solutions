#include <iostream>
#include <string>
#include <sstream>
 
using namespace std;
 
int main ()
{
    int n, sum1, sum2, sum, tmp1, tmp2;
    string str;
    for (cin >> n; n; n--)
    {
    	sum1 = sum2 = 0;
        for (int I = 0; I < 4 && cin >> str; I++)
        {
        	sum1 += (str[1]-'0') + (str[3]-'0');
            tmp1 = (str[0]-'0')*2;
            tmp2 = (str[2]-'0')*2;
            sum2 += (tmp1 % 10) + (tmp1 / 10) + (tmp2 % 10) + (tmp2 / 10);
		}
        sum = sum1 + sum2;
        if (sum % 10)
        	cout << "Invalid" << endl;
		else
        	cout << "Valid" << endl;
	}
    return 0;
}