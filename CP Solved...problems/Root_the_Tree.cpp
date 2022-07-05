#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long int>
#define vvll vector<vector<long long int>>
#define loop(i, a, n) for (ll i = a; i < n; i++)
#define loope(i, a, n) for (ll i = a; i <= n; i++)
#define end '\n'
#define vpi vector<pair<int, int>>
#define vpll vector<pair<long long int, long long int>>
#define pb push_back
const int inf = 1e9 + 7;

// const int V = 1e5 + 10;
// vector<pair<int, int>> adj[V];
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
        vector<ll> indegree(n + 1);
        ll a, b;

        for (ll i = 0; i < n - 1; i++)
        {
            cin >> a >> b;
            indegree[b]++;
        }

        ll res = 0;
        // for (ll i = 1; i <= n; i++)
        // {
        //     if (indegree[i] == 0)
        //         res++;
        // }
        // cout << res - 1 << end;

        for (ll i = 1; i <= n; i++)
        {
            if (indegree[i] > 1)
                res += (indegree[i] - 1);
        }
        cout << res << end;
    }
    return 0;
}