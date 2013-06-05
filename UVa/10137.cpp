#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main ()
{
    int n;
    double stdu[1000];
    double avg, res;
    int temp;
    while (cin >> n && n)
    {
        avg = res = 0;
        for (int i = 0; i < n && cin >> stdu[i]; avg += stdu[i], i++);
        avg /= n;
        for (int i = 0; i < n; i++)
            if (stdu[i] < avg)
            {
                temp = (avg - stdu[i])*100;
                res += temp;
            }
        }
        res /= 200.;
        printf ("$%.2f\n", res);
    }
    return 0;
}
