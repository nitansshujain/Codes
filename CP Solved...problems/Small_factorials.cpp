#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long int>
#define vvll vector<vector<long long int>>
#define endd '\n'
#define vpi vector<pair<int, int>>
#define vpll vector<pair<long long int, long long int>>
#define pb push_back
const int inf = 1e9 + 7;

void solve()
{
    ll n;
    cin >> n;
    vll v, temp;

    ll fac = n;
    while (n)
    {
        v.pb(n % 10);
        n /= 10;
    }

    for (ll i = fac - 1; i > 0; i--)
    {
        ll carry = 0;
        for (auto digit : v)
        {
            ll prod = carry + i * digit;
            temp.pb(prod % 10);
            carry = prod / 10;
        }
        while (carry)
        {
            temp.pb(carry % 10);
            carry /= 10;
        }

        v = temp;
        temp.clear();
    }
    reverse(v.begin(), v.end());
    for (auto d : v)
    {
        cout << d;
    }
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
}