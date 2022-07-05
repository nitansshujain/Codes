#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

int dp[1001][1001];
int subSet(vector<int> &v, int n, int sum)
{
    if (sum == 0)
        return true;

    if (n <= 0)
        return false;

    if (dp[n - 1][sum] != -1)
        return dp[n - 1][sum];

    if (v[n - 1] > sum)
        return dp[n - 1][sum] = subSet(v, n - 1, sum);

    return dp[n - 1][sum] = subSet(v, n - 1, sum - v[n - 1]) || subSet(v, n - 1, sum);
}
int main()
{
    fast;
    int t;
    cin >> t;

    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        int n, m;
        cin >> n >> m;

        vector<int> v;

        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }

        if (subSet(v, n, m))
        {
            cout << "Yes"
                 << "\n";
        }
        else
        {
            cout << "No"
                 << "\n";
        }
        // Can't use greeky approach here
        // sort(v.begin(), v.end(), greater<int>());

        // for (auto &num : v)
        // {
        //     if (num <= m)
        //     {
        //         m -= num;
        //     }
        //     if (m <= 0)
        //         break;
        // }

        // if (m == 0)
        // {
        //     cout << "Yes"
        //          << "\n";
        // }
        // else
        // {
        //     cout << "No"
        //          << "\n";
        // }
    }
    return 0;
}