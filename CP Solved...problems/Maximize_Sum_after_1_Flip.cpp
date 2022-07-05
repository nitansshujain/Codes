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

int main()
{
    fast;
    ll n;
    cin >> n;

    vll a(n);
    vll b(n);

    ll sum = 0;
    for (auto &x : a)
    {
        cin >> x;
        sum += x;
    }

    for (auto &x : b)
        cin >> x;

    ll max_diff = LLONG_MIN;
    for (ll i = 0; i < n; i++)
    {
        ll diff = b[i] - a[i];
        if (diff > 0)
        {
            if (diff > max_diff)
            {
                max_diff = diff;
            }
        }
    }

    if (max_diff == LLONG_MIN)
    {
        cout << sum << endd;
    }
    else
    {
        sum = sum + max_diff;
        cout << sum << endd;
    }
}
