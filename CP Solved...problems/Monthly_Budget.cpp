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
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void solve()
{
    int x, y;
    cin >> x >> y;

    if (x >= 30 * y)
        cout << "YES";
    else
        cout << "NO";
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