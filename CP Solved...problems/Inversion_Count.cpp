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

ll merge(vector<ll> &arr, ll low, ll mid, ll high)
{
    vector<ll> temp(high - low + 1);
    ll i = low, j = mid, k = 0;
    ll count_invertions = 0;

    while ((i < mid) && (j <= high))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            count_invertions += mid - i;
        }
    }

    while (i < mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= high)
    {
        temp[k++] = arr[j++];
    }

    for (int i = low, k = 0; i <= high; i++, k++)
    {
        arr[i] = temp[k];
    }

    return count_invertions;
}
ll mergeSort(vector<ll> &arr, ll low, ll high)
{
    ll count_inversions = 0;
    if (low < high)
    {
        ll mid = low + (high - low) / 2;
        count_inversions += mergeSort(arr, low, mid);
        count_inversions += mergeSort(arr, mid + 1, high);
        count_inversions += merge(arr, low, mid + 1, high);
    }
    return count_inversions;
}
void solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (auto &x : arr)
        cin >> x;
    cout << mergeSort(arr, 0, n - 1);
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