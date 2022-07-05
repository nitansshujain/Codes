#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &rank, int paratha)
{
    int low = 1, high = 5 * paratha * (paratha + 1);
    // Binary Search
    while (high > low)
    {
        int mid = (high + low) / 2;
        int parathaCooked = 0;

        // Calculate total number of dishes prepared in time = 'mid' by 'N' cooks.
        for (int i = 0; i < rank.size(); i++)
        {
            parathaCooked += (-1 + sqrt(1 + (8 * mid) / rank[i])) / 2;
        }

        if (parathaCooked < paratha)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return high;
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int paratha;
        cin >> paratha;

        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &x : v)
        {
            cin >> x;
        }

        cout << solve(v, paratha) << endl;
    }
    return 0;
}