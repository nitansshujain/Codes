#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long int>
#define vvll vector<vector<long long int>>
#define loop0(i, n) for (ll i = 0; i < n; i++)
#define loop1(i, n) for (ll i = 1; i <= n; i++)
#define loop(i, a, b, n) for (ll i = a; i <= b; i++)
#define end '\n'
#define vpi vector<pair<int, int>>
#define vpll vector<pair<long long int, long long int>>
#define pb push_back
const int inf = 1e9 + 7;

// const int V = 1e5 + 10;
// vector<pair<int, int>> adj[V];
// vector<int> level(V, inf);
ll mx;
ll r, c;
bool isValid(ll x, ll y, vvll &g)
{
    if (x >= 0 && y >= 0 && x < r && y < c && g[x][y] != mx)
        return true;
    return false;
}
int main()
{
    fast;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        r = 0, c = 0, mx = INT_MIN;
        cin >> r >> c;

        vvll g(r, vll(c));

        loop0(i, r)
        {
            loop0(j, c)
            {
                cin >> g[i][j];
                mx = max(mx, g[i][j]);
            }
        }
        queue<pair<ll, ll>> q;
        loop0(i, r)
        {
            loop0(j, c)
            {
                if (g[i][j] == mx)
                    q.push({i, j});
            }
        }
        ll timer = -1;
        vll dx{-1, -1, -1, 0, 0, 1, 1, 1};
        vll dy{-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty())
        {
            ll sz = q.size();
            while (sz--)
            {
                ll x = q.front().first;
                ll y = q.front().second;
                q.pop();
                for (ll i = 0; i < 8; i++)
                {
                    if (isValid(x + dx[i], y + dy[i], g))
                    {
                        q.push({x + dx[i], y + dy[i]});
                        g[x + dx[i]][y + dy[i]] = mx;
                    }
                }
            }
            timer++;
        }

        cout << (timer == -1 ? 0 : timer) << end;
    }
    return 0;
}