#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 13;
int n, k;
int arr[MAX_N], tmp[MAX_N];

void merge_sort(int l, int r)
{
    if (l + 1 == r)
        return;
    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid, r);
    for (int i = l, j = l, k = mid; i < r; ++i)
        if (j == mid)
            tmp[i] = arr[k++];
        else if (k == r)
            tmp[i] = arr[j++];
        else if (arr[j] < arr[k])
            tmp[i] = arr[j++];
        else
            tmp[i] = arr[k++];
    for (int i = l; i < r; ++i)
        arr[i] = tmp[i];
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr, arr + n); // merge_sort(0, n);
    for (int i = 0, m = 0; k--;)
    {
        while (i < n && arr[i] - m == 0)
            i++;
        if (i < n)
        {
            cout << arr[i] - m << endl;
            m += arr[i] - m;
        }
        else
            cout << 0 << endl;
    }
    return 0;
}