#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

bool compare(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}
int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        /*
            row - odd; col - even => ok
            row - even; col - even => ok
            row - even; col - odd => ok
            row - odd; col - odd => no

            since swapping is  possible for oks

        */
        if ((n * m) % 2 == 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}