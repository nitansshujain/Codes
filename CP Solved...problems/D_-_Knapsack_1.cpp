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

ll n, W, w[100005], v[100005];
ll dp[105][100005];
ll solve1(ll n, ll W)
{
    if (n == 0 || W == 0)
        return 0;

    if (dp[n][W] != -1)
        return dp[n][W];
    if (w[n] <= W)
        return dp[n][W] = max(v[n] + solve1(n - 1, W - w[n]), solve1(n - 1, W));
    else
        return dp[n][W] = solve1(n - 1, W);
}

ll solve2(ll current_item, ll remaining_weight)
{
    if (current_item == n + 1)
        return 0;

    if (dp[current_item][remaining_weight] != -1)
        return dp[current_item][remaining_weight];

    ll total_value = 0;
    // dont't take it
    total_value = max(total_value, solve2(current_item + 1, remaining_weight));

    // take it if possible
    if (remaining_weight >= w[current_item])
    {
        total_value = max(total_value, v[current_item] + solve2(current_item + 1, remaining_weight - w[current_item]));
    }

    return dp[current_item][remaining_weight] = total_value;
}
int main()
{
    fast;

    cin >> n >> W;

    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }
    memset(dp, -1, sizeof(dp));
    // cout << solve1(n, W) << endl;
    cout << solve2(1, W) << endl;
    return 0;
}
