#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long int>
#define vvll vector<vector<long long int>>
#define loop0(i, a, b) for (ll i = a; i < b; i++)
#define loop1(i, a, b) for (ll i = a; i <= b; i++)
#define end '\n'
#define vpi vector<pair<int, int>>
#define vpll vector<pair<long long int, long long int>>
#define pb push_back
const int inf = 1e9 + 7;

void solve()
{
    ll n, s;
    cin >> n >> s;

    ll max = INT_MIN;
    ll i = 0, j = n;
    while (i <= j)
    {
        if (i + j == s)
        {
            if (abs(i - j) > max)
            {
                max = abs(i - j);
            }
            i++, j--;
        }
        else if (i + j < s)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    cout << max;
}
int main()
{
    fast;
    ll t = 1;
    cin >> t;

    while (t--)
    {
        solve();
        cout << end;
    }
}