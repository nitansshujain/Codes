#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long int>
#define vvll vector<vector<long long int>>
#define loop0(i, a, b) for (ll i = a; i < b; i++)
#define loop1(i, a, b) for (ll i = a; i <= b; i++)
#define end '\n'
#define vpi vector<pair<int, int>>
#define vpll vector<pair<long long int, long long int>>
#define pb push_back
const int inf = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;

    cout << n;
}
int main()
{
    fast;
    ll n, k;
    cin >> n >> k;
    ll res_cnt = 0;
    while (n--)
    {
        int t;
        cin >> t;

        if (t % k == 0)
            res_cnt++;
        // solve();
    }
    cout << res_cnt << end;
}