// #include <bits/stdc++.h>
#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <climits>
#include <bitset>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <fstream>
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
    ll n;
    cin >> n;

    vll v(n);
    for (auto &x : v)
        cin >> x;

    vll asc_sum(n + 1);
    vll desc_sum(n + 1);

    for (int i = 1; i < n + 1; i++)
    {
        asc_sum[i] = asc_sum[i - 1] + v[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        desc_sum[i] = desc_sum[i + 1] + v[i];
    }

    ll res = LLONG_MIN;
    ll min_diff = LLONG_MAX;
    for (int i = 0; i <= n; i++)
    {
        ll temp = abs(desc_sum[i] - asc_sum[i]);
        if (temp < min_diff)
        {
            min_diff = temp;
            res = max(desc_sum[i], asc_sum[i]);
        }
    }

    cout << res;
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