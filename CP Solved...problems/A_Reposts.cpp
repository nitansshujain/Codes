#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ll long long int
#define ld long double
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long int>
#define vvll vector<vector<long long int>>
#define endd '\n'
#define pi 3.1415926535897932384626433832795028841971
#define MOD 1000000007

#define vpi vector<pair<int, int>>
#define vpll vector<pair<long long int, long long int>>
#define pb push_back

ll add(ll a, ll b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}
ll subtract(ll a, ll b) { return ((a % MOD) - (b % MOD)) % MOD; }
ll mult(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }

int expo(int a, int b, int mod)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
void sieve()
{
    vector<bool> prime(MOD + 1);
    prime[0] = prime[1] = 0;

    for (int i = 2; i * i <= MOD; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= MOD; j += i)
                prime[j] = 0;
        }
    }
}

class DSU
{
private:
    vector<int> root;
    vector<int> rank;

public:
    DSU(int n) : root(n), rank(n)
    {
        for (int i = 0; i < n; i++)
        {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x)
    {
        if (x == root[x])
            return x;
        return root[x] = find(root[x]);
    }

    void unionFind(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            if (rank[rootX] < rank[rootY])
            {
                root[rootX] = rootY;
            }
            else if (rank[rootY] < rank[rootX])
            {
                root[rootY] = rootX;
            }
            else
            {
                root[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    bool isConnected(int x, int y)
    {
        return find(x) == find(y);
    }
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

ll dfs(ll node, ll par, vector<vector<int>> &adj)
{
    ll maxi = 0, res = 0;

    for (auto child : adj[node])
    {
        if (child != par)
        {
            maxi = max(maxi, dfs(child, node, adj));
            res = maxi + 1;
        }
    }

    return res;
}
void solve()
{
    ll n;
    cin >> n;

    unordered_map<string, int> mp;
    unordered_set<string> seta;
    vector<pair<string, string>> v;

    for (int i = 0; i < n; i++)
    {
        string a, b, c;
        cin >> a >> b >> c;

        transform(a.begin(), a.end(), a.begin(), ::tolower);
        transform(c.begin(), c.end(), c.begin(), ::tolower);

        v.pb(make_pair(c, a));
        seta.insert(a);
        seta.insert(c);
    }

    int c = 0;
    for (auto itr = seta.begin(); itr != seta.end(); itr++)
    {
        mp[*itr] = c++;
    }

    vector<vector<int>> adj(n + 1, vector<int>());
    for (int i = 0; i < n; i++)
    {
        adj[mp[v[i].first]].pb(mp[v[i].second]);
    }

    ll res = dfs(mp[v[0].first], -1, adj);
    cout << res + 1 << endd;
}

int main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}