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
    ll n, k;
    cin >> n >> k;

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

    vll diff;
    for (ll i = 0; i < n; i++)
    {
        ll difference = b[i] - a[i];
        if (difference > 0)
        {
            diff.pb(difference);
        }
    }

    sort(diff.begin(), diff.end(), greater<int>());
    if (diff.empty())
    {
        cout << sum << endd;
    }
    else
    {
        for (int i = 0, j = 0; i < k && j < diff.size(); i++, j++)
        {
            sum += diff[i];
        }
        cout << sum << endd;
    }
}
