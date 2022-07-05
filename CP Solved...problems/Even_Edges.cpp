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
        ll v, e;
        cin >> v >> e;
        vll adj[v + 1];
        vll res(v + 1, 1);

        ll a, b;

        loop(i, 0, e)
        {
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }

        if (e % 2 == 0)
        {
            cout << 1 << end;
        }
        else
        {
            ll oddDegreeNode = -1;
            loope(i, 1, v)
            {
                if (adj[i].size() % 2 == 1)
                {
                    cout << 2 << end;
                    res[i] = 2;
                    oddDegreeNode = i;
                    break;
                }
            }

            if (oddDegreeNode == -1)
            {
                cout << 3 << end;
                loope(i, 1, v)
                {
                    if (adj[i].size() != 0)
                    { //in case of vertex having 0 edge -> it's present in subgroup 1
                        res[i] = 2;
                        ll connected_to_i = adj[i][0];
                        res[connected_to_i] = 3;
                        break;
                    }
                }
            }
        }
        loope(i, 1, v) cout << res[i] << " ";
        cout << end;
    }
    return 0;
}