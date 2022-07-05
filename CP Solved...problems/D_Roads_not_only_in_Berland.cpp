#include <bits/stdc++.h>
// #include <iostream>
// #include <deque>
// #include <algorithm>
// #include <math.h>
// #include <sstream>
// #include <stdio.h>
// #include <bitset>
// #include <string>
// #include <vector>
// #include <unordered_map>
// #include <map>
// #include <queue>
// #include <set>
// #include <unordered_set>
// #include <fstream>
using namespace std;

#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long int>
#define vvll vector<vector<long long int>>
#define endd "\n"
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

void solve()
{
    int n;
    cin >> n;

    DSU dsu(n + 1);
    vpi vec;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        if (dsu.isConnected(u, v))
        {
            vec.pb({u, v});
        }
        else
        {
            dsu.unionFind(u, v);
        }
    }

    unordered_set<int> seta;

    for (int i = 1; i <= n; i++)
    {
        seta.insert(dsu.find(i));
    }

    int sz = seta.size();
    cout << sz - 1 << endd;

    vector<int> temp_vec(seta.begin(), seta.end());
    int j = 0;
    for (int i = 1; i <= sz - 1; i++)
    {
        cout << vec[i - 1].first << " " << vec[i - 1].second << " " << temp_vec[j] << " " << temp_vec[j + 1] << endd;
        j++;
    }
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