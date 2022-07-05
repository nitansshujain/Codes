#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

bool compare(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}
int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        vector<pair<ll, ll>> v; //distance,sum
        for (ll i = 1; i <= n; i++)
        {
            ll x, y;
            cin >> x >> y;
            ll sum = x + y;
            ll dist = x * x + y * y;
            v.push_back({dist, sum});
        }

        sort(v.begin(), v.end(), compare);

        ll res_sum = 0;
        for (ll i = 0; i < k; i++)
        {
            res_sum += v[i].second;
        }
        cout << res_sum << endl;
    }
    return 0;
}