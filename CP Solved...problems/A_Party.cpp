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

int dfs(int node, int par, vector<int> &dp, vector<vector<int>> &adj)
{
    dp[node] = 1;
    int maxi = 0, res = 0;
    for (int child : adj[node])
    {
        if (child == par)
            continue;
        else
        {
            // dfs(child, node, dp, adj);
            // maxi = max(maxi, dp[child]);
            maxi = max(maxi, dfs(child, node, dp, adj));
            res = maxi + 1;
        }
    }
    dp[node] = res;
    return res;
    // dp[node] += maxi;
}

int bfs(int node, vector<bool> &vis, vector<vector<int>> &adj)
{
    vis[node] = true;
    queue<int> q;
    q.push(node);

    int res = 0;
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            int curr = q.front();
            q.pop();

            for (auto child : adj[curr])
            {
                if (!vis[child])
                {
                    q.push(child);
                    vis[child] = true;
                }
            }
        }
        res++;
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1, vector<int>());

    // vector<int> dp(n + 1);

    // making a dummy level 0
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;

        if (m == -1)
        {
            adj[0].push_back(i);
        }
        else
        {
            adj[m].push_back(i);
        }
    }
    vector<bool> vis(n + 1);
    cout << bfs(0, vis, adj) - 1 << endd;
    // dfs(0, -1, dp, adj);

    // cout << dp[0] << endd;
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