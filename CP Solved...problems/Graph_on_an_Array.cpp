#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long int>
#define vvll vector<vector<long long int>>
#define loop0(i, n) for (int i = 0; i < n; i++)
#define loop1(i, n) for (int i = 1; i <= n; i++)
#define loop(i, a, b, n) for (int i = a; i <= b; i++)
#define end '\n'
#define vpi vector<pair<int, int>>
#define vpll vector<pair<long long int, long long int>>
#define pb push_back
// const int V = 1e5 + 10;
// vector<pair<int, int>> adj[V];
// const int inf = 1e9 + 7;
// vector<int> level(V, inf);

ll dfs(vector<ll> *adj, vector<bool> &vis, ll curr)
{
    vis[curr] = true;
    ll count = 1;
    for (auto child : adj[curr])
    {
        if (!vis[child])
            count += (dfs(adj, vis, child));
    }
    return count;
}
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
        bool check_47 = false; //stores (found,index)
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] == 47)
            {
                check_47 = true;
            }
        }

        vector<ll> adj[n];
        for (ll i = 0; i < n; i++)
        {
            for (ll j = i + 1; j < n; j++)
            {
                if (__gcd(v[i], v[j]) == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        // for (auto x : adj)
        // {
        //     for (auto y : x)
        //     {
        //         cout << y << " ";
        //     }
        // }
        vector<bool> vis(n);
        if (dfs(adj, vis, 0) < n)
        {
            cout << 1 << endl;
            if (check_47 == true)
                v[0] = 43;
            else
                v[0] = 47;
            for (ll i = 0; i < n; i++)
            {
                cout << v[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << 0 << endl;
            for (ll i = 0; i < n; i++)
            {
                cout << v[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}