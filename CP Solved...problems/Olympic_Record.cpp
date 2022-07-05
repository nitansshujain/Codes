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

    vll v(n);
    for (auto x : v)
    {
        cin >> x;
    }
    vpll vp;
    for (ll i = 1; i < n; i++)
    {
        vp.pb({v[i], v[i - 1]});
    }

    for (int i = 0; i < vp.size(); i++)
    {
    }
}

int main()
{
    fast;
    ll x, y, z;
    cin >> x >> y >> z;

    if (x > 87 || y > 87 || z > 87)
        cout << "Yes" << endd;
    else
        cout << "No" << endd;
}
