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

int n, a[100005], b[100005], c[100005];
int dp[100005][4];
int solve(int day, int pre_activity)
{
    if (day == n + 1)
        return 0;

    if (dp[day][pre_activity] != -1)
        return dp[day][pre_activity];
    int happiness = 0;

    // doing activity 0 on day
    if (pre_activity != 0)
        happiness = max(happiness, solve(day + 1, 0) + a[day]);
    // doing activity 1 on day
    if (pre_activity != 1)
        happiness = max(happiness, solve(day + 1, 1) + b[day]);
    // doing activity 2 on day
    if (pre_activity != 2)
        happiness = max(happiness, solve(day + 1, 2) + c[day]);

    return dp[day][pre_activity] = happiness;
}
int main()
{
    fast;  

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> c[i];
    memset(dp, -1, sizeof(dp));
    cout << solve(1, -1) << endl;
    return 0;
}
