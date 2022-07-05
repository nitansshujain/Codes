#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long int>
#define vvll vector<vector<long long int>>
#define endd '\n'
#define vpi vector<pair<int, int>>
#define vpll vector<pair<long long int, long long int>>
#define pb push_back
const int inf = 1e9 + 7;

int n, k;
vector<int> dp(1000000, -1);
int solve(vi &v, int stone)
{
    if (stone == n)
        return 0;
    if (dp[stone] != -1)
        return dp[stone];
    int curr_ans = INT_MAX;

    for (int i = 1; i <= k; i++)
    {
        int at_stone = stone + i;
        if (at_stone <= n)
        {
            curr_ans = min(curr_ans, abs(v[at_stone] - v[stone]) + solve(v, at_stone));
        }
    }
    dp[stone] = curr_ans;
    return curr_ans;
}
int main()
{
    fast;

    cin >> n >> k;
    vi v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    // cout << solve(v, 1) << endl;

    dp[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        int curr_ans = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 1)
            {
                curr_ans = min(curr_ans, abs(v[i - j] - v[i]) + dp[i - j]);
            }
        }
        dp[i] = curr_ans;
    }
    cout << dp[n] << endl;
    return 0;
}
