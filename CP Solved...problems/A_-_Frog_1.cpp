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

int n;
vector<int> dp(1000000, -1);
int solve(vi &v, int stone)
{
    if (stone == n)
        return 0;
    if (dp[stone] != -1)
        return dp[stone];
    int curr_ans = INT_MAX;
    curr_ans = min(curr_ans, abs(v[stone + 1] - v[stone]) + solve(v, stone + 1));
    if (stone + 2 <= n)
        curr_ans = min(curr_ans, abs(v[stone + 2] - v[stone]) + solve(v, stone + 2));

    dp[stone] = curr_ans;
    return curr_ans;
}
int main()
{
    fast;

    cin >> n;
    vi v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    // cout << solve(v, 1) << endl;
    
    return 0;
}
