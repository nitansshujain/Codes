#include <bits/stdc++.h>
using namespace std;

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    int left = -1, right = -1;
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (k < arr[mid])
        {
            e = mid - 1;
        }
        else if (k > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            left = mid;
            e = mid - 1;
        }
    }

    s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (k < arr[mid])
        {
            e = mid - 1;
        }
        else if (k > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            right = mid;
            s = mid + 1;
        }
    }

    return {left, right};
}
int main()
{
    vector<int> arr = {1, 2, 3, 3, 3, 4, 5, 6, 7, 8, 9};
    pair<int, int> res = firstAndLastPosition(arr, arr.size(), 3);
    cout << res.first << " " << res.second << endl;
    return 0;
}