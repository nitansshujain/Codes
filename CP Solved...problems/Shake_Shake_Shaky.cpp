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
#define endd '\n'
#define pi 3.1415926535897932384626433832795028841971
#define MOD 1000000007

#define vpi vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
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
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool check(int candy, vector<ll> &v, int k)
{
    ll n = v.size();
    if (k == 1)
        return true;

    ll num_students = 0;

    for (ll i = n - 1; i >= 0; i--)
    {
        num_students += (v[i] / candy);

        if (num_students >= k)
            return true;
    }

    return false;
}
void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;

    sort(v.begin(), v.end());
    ll low = 1, high = v[n - 1];

    ll res = 0;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (check(mid, v, k))
        {
            res = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << res;
}

int main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endd;
    }
}
// https://pastebin.com/4n86mGQn