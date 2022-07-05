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

void solve()
{
    ll n, t;
    cin >> n >> t;

    vector<ll> v(n);
    // vector<ll> prefix(n);
    // ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        // sum += v[i];
        // prefix[i] = sum;
    }

    ll books = 0;
    ll start = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + v[i] > t)
        {
            while (start < i && sum + v[i] > t)
            {
                sum -= v[start];
                start++;
            }
        }
        sum += v[i];
        if (sum <= t)
        {
            books = max(books, i - start + 1);
        }
    }

    cout << books << endl;

    // Anpther Approach
    // ll books = 0, maxi = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     books = upper_bound(prefix.begin(), prefix.end(), t) - prefix.begin() - i;
    //     if (books > maxi)
    //         maxi = books;

    //     // sliding the window so add the time of v[i]
    //     t += v[i];
    // }
    // cout << maxi << endl;

    // Wronng Approach
    // sort(v.begin(), v.end());

    // int books = 0;
    // int i = 0;
    // while (i < v.size())
    // {
    //     if (v[i] > t)
    //         break;
    //     else
    //     {
    //         books++;
    //         t -= v[i++];
    //     }
    // }

    // cout << books << endd;
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

    return 0;
}
