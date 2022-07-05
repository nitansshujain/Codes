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

ll n, W, w[101], v[101];
ll dp[101][100005];

ll solve(ll current_item, ll value_to_achieve)
{
    if (current_item == n + 1)
    {
        if (value_to_achieve == 0)
            return 0;
        else
            return W + 1;
    }
    if (dp[current_item][value_to_achieve] != -1)
        return dp[current_item][value_to_achieve];
    ll min_weight_needed = W + 1;
    min_weight_needed = min(min_weight_needed, solve(current_item + 1, value_to_achieve));

    if (value_to_achieve >= v[current_item])
    {
        min_weight_needed = min(min_weight_needed, w[current_item] + solve(current_item + 1, value_to_achieve - v[current_item]));
    }

    return dp[current_item][value_to_achieve] = min_weight_needed;
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

    ll res = 0;
    for (ll v = 100000; v >= 1; v--)
    {
        if (solve(1, v) <= W)
        {
            res = max(res, v);
        }
    }
    cout << res << endd;
    return 0;
}
