#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

// const int V = 1e5 + 10;
// vector<pair<int, int>> adj[V];
// const int inf = 1e9 + 7;
// vector<int> level(V, inf);

int main()
{
    fast;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll res = 0;
        ll mn = *min_element(v.begin(), v.end());
        for (ll i = 0; i < n; i++)
        {
            if (mn != v[i])
            {
                res += (mn * v[i]);
            }
        }

        cout << res << endl;
    }
    return 0;
}