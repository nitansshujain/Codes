#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long int>
#define vvll vector<vector<long long int>>
#define endd '\n'
#define pi 3.1415926535897932384626433832795028841971
#define ld long double
#define MOD 1000000007
#define MOD1 998244353

#define vpi vector<pair<int, int>>
#define vpll vector<pair<long long int, long long int>>
#define pb push_back

int add(long long a, long long b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}
int subtract(long long a, long long b) { return ((a % MOD) - (b % MOD)) % MOD; }
int mult(long long a, long long b) { return ((a % MOD) * (b % MOD)) % MOD; }
int add1(long long a, long long b) { return ((a % MOD1) + (b % MOD1)) % MOD1; }
int subtract1(long long a, long long b) { return ((a % MOD1) - (b % MOD1)) % MOD1; }
int mult1(long long a, long long b) { return ((a % MOD1) * (b % MOD1)) % MOD1; }

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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// Max(Sum(0,i),sum(i+1,n))
// Isme for every value of i take the minimum and that is ans
void solve()
{
    ll n, ct = 0;
    cin >> n;

    vll v(n);
    for (auto &x : v)
        cin >> x;

    string s;
    cin >> s;

    if (is_sorted(v.begin(), v.end()))
    {
        cout << 0;
        return;
    }

    for (auto x : s)
        if (x == 'N')
            ct++;

    if (ct == n || ct == 0)
    {
        cout << -1;
        return;
    }
    vll V = v;

    sort(v.begin(), v.end());

    ll start = LLONG_MAX, last = LLONG_MIN;

    for (ll i = 0; i < n; i++)
    {
        if (v[i] != V[i])
        {
            start = min(i, start);
            last = max(last, i);
        }
    }
    bool f1 = false, f2 = false;
    for (int i = 0; i < start; i++)
        if (s[i] != s[last])
            f1 = true;
    for (int i = last; i < n; i++)
        if (s[i] != s[start])
            f2 = true;
    if (s[start] != s[last] || f1 || f2)
        cout << 1;
    else
        cout << 2;
}

int main()
{
    fast;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endd;
    }
    return 0;
}